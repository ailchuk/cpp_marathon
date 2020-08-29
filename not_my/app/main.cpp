#include "src/header.h"

#include <ctime>
#include <random>
#include <time.h>

using namespace sf;



int usage() {
	std::cerr << "usage: ./race00 [width] [height]" << std::endl;
	return 1;
}

static void getFile(std::multiset<std::string>& list, std::fstream& file) {
	std::string line;

	while (std::getline(file, line))
		if (!line.empty())
			list.insert(line);
}
static void writeTo(std::multiset<int> list) {
	std::fstream file;
	int flag = SCORE;

	file.open ("score_list.txt",std::fstream::out | std::fstream::trunc);
	if (!file.is_open())
		return;
	for (auto i = list.rbegin(); i != list.rend(); i++) {
		if (flag == 0)
			break;
		file << *i << std::endl;
		flag--;
	}
	file.close();
}
void setScore(int score) {
	std::multiset<std::string> list;
	std::multiset<int> normal;
	std::fstream file;
	file.open ("score_list.txt",std::fstream::in);
	std::stringstream str_score;

	if (!file.is_open())
		return;
	getFile(list, file);
	str_score << score;
	list.insert(std::string(str_score.str()));
	file.close();
	for (auto& i : list)
		normal.insert(std::stoi(i));
	writeTo(normal);
}

static bool checkFlag(int flag) {
	if (flag == 1 || flag == 2)
		return true;
	return false;
}
void getEvent(RenderWindow& window, Snake& snake, int& flag) {
	Event event;

	if (window.pollEvent(event)) {
		switch (event.type) {
			case Event::Closed:
				window.close();
				break;
			case Event::KeyPressed:
				if (flag == 3)
					flag = 0;
				else if (checkFlag(flag)) {
					if (event.key.code == Keyboard::Up)
						snake.moveSnake(-SIZE, 'x');
					if (event.key.code == Keyboard::Down)
						snake.moveSnake(SIZE, 'x');
					if (event.key.code == Keyboard::Right)
						snake.moveSnake(SIZE, 'y');
					if (event.key.code == Keyboard::Left)
						snake.moveSnake(-SIZE, 'y');
				}
				break;
			default:
				break;
		}
	}
	else if (checkFlag(flag))
		snake.moveSnake();
}
void checkSnake(int& flag, RenderWindow& window, Snake& snake, Elements& el, int& timer) {
	if (snake.getXY().first == el.xy_food[0]
		&& snake.getXY().second == el.xy_food[1]) {
		el.createFood(window, snake, WINDOW_X, WINDOW_Y);
		snake.score += 50;
		snake.increaseSnake();
		timer = 0;
	}
	if (timer >= 400) {
		timer = 0;
		snake.reduceSnake();
	}
	if ((snake.getXY().first <= 0 || snake.getXY().first > WINDOW_X - SIZE)
		|| (snake.getXY().second <= 0 || snake.getXY().second > WINDOW_Y - SIZE)
		|| snake.eatYourself()
		|| snake.xy.size() < 3
		|| snake.rockSnake(el)) {
		snake.xy.clear();
		el.rock.clear();
		el.createFood(window, snake, WINDOW_X, WINDOW_Y);
		window.setSize(Vector2u(WINDOW_X, WINDOW_Y));
		setScore(snake.score);
		flag = 3;
		snake.skin == 0 ? snake.skin = 1 : snake.skin = 0;
    	snake.new_game = true;
	}
}

int main(int arg, char **argv) {
	// if (arg != 3)
	// 	return usage();
	RenderWindow window(VideoMode(WINDOW_X, WINDOW_Y), "Snake", Style::Titlebar | Style::Close);
	Elements el(SIZE);
	Snake snake(SIZE);
	int timer = 0;
	int flag = 0;

	window.setKeyRepeatEnabled(false);
	el.createFood(window, snake, WINDOW_X, WINDOW_Y);
	while (window.isOpen()) {
		int speed = 100 - snake.xy.size();

		if (flag == 1 || flag == 2)
			window.clear(Color(192, 154, 154));
		else
			window.clear(Color(233, 179, 0));

		getEvent(window, snake, flag);
		if (flag == 0) {
			flag = el.mousePress(window, flag);
			el.renderMenu(window);
		}
		else if (flag == 1 || flag == 2) {
			// window.setSize(Vector2u(atoi(argv[1]), atoi(argv[2]))); // open
			if (flag == 2 && el.rock.empty())
				el.createRocks(window, snake, WINDOW_X, WINDOW_Y);
			if (snake.new_game) {
				sleep(DELAY);
    			snake.new_game = false;
			}
			snake.startNewGame(SIZE, WINDOW_X, WINDOW_Y, timer);
			snake.renderSnake(window);
			el.renderElements(window);
			checkSnake(flag, window, snake, el, timer);
		}
		else if (flag == 3)
			el.renderLBoard(window, snake.score);
		else if (flag == 4)
			exit(EXIT_SUCCESS);
		else if (flag == 5)
			flag = 0;
		window.display();
		window.clear();

		usleep(speed * 1000);
		timer += 100 * 1000 / 10000;
    }
	return 0;
}
