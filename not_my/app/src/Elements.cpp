#include "Elements.h"
#include <ctime>
#include <random>
#include <time.h>

int randNum(int low, int up, int size) {
    std::random_device random;
    std::uniform_int_distribution<int> uid(low, up);
    int res = uid(random);

    while (res % SIZE != 0)
        res++;
    return res;
}

Elements::Elements(int size) {
    m_pressed = false;
    m_food.loadFromFile("./resource/red.png");
    m_rock.loadFromFile("./resource/grass.png");
    m_normal.loadFromFile("./resource/normal.png");
    m_hard.loadFromFile("./resource/hard.png");
    m_lboard.loadFromFile("./resource/duo.png");
    m_exit.loadFromFile("./resource/exit.png");
}

Elements::~Elements() {
}

void Elements::renderElements(sf::RenderWindow &window) {
    sf::Sprite sprite;
    sprite.setTexture(m_food);
	sprite.setPosition(sf::Vector2f(xy_food[0], xy_food[1]));
	window.draw(sprite);
    if (!rock.empty()) {
        sprite.setTexture(m_rock);
        for (auto i : rock) {
	        sprite.setPosition(sf::Vector2f(i.first, i.second));
	        window.draw(sprite);
        }
    }
}

bool Elements::isRock(int x, int y) {
    for (auto i : rock)
        if (i.first == x && i.second == y)
            return true;
    return false;
}

void Elements::createFood(sf::RenderWindow &window, Snake snake, int width, int heigh) {
    int size = snake.getSizeBlock();
	int x = randNum(1, width - size, size);
	int y = randNum(1, heigh - size, size);

	while (!snake.IsNotSnake(width, heigh) && !isRock(x, y)) {
		x = randNum(1, width - 1, size);
		y = randNum(1, heigh - 1, size);
	}
    xy_food[0] = x;
    xy_food[1] = y;
}

void Elements::createRocks(sf::RenderWindow &window, Snake snake, int width, int heigh) {
    int size, x, y, i = (width * heigh) / (ROCKS + SIZE * 2);

    for (; i > 0; i--) {
        size = snake.getSizeBlock();
        x = randNum(1, width - size, size);
        y = randNum(1, heigh - size, size);
        while (!snake.IsNotSnake(width, heigh)
            && x != xy_food[0]
            && y != xy_food[1]) {
            x = randNum(1, width - 1, size);
            y = randNum(1, heigh - 1, size);
        }
        rock.push_back(std::make_pair(x, y));
    }
}

static void setIcon(sf::Texture texture, sf::RenderWindow& window, int x, int y) {
    sf::Sprite sprite(texture);
	sprite.setPosition(sf::Vector2f(x, y));
	window.draw(sprite);
}
void Elements::renderMenu(sf::RenderWindow& window) {
    setIcon(m_normal, window, 100, 80);
    setIcon(m_hard, window, 100, 360);
    setIcon(m_lboard, window, 100, 640);
    setIcon(m_exit, window, 100, 920);
}

static void getFile(std::multiset<std::string>& list, std::fstream& file) {
	std::string line;

	while (std::getline(file, line))
		if (!line.empty())
			list.insert(line);
}
static void printOut(sf::RenderWindow& window, std::string score, int y, int flag) {
    sf::Font font;
    font.loadFromFile("./resource/arial.ttf");
    sf::Text text(score, font);
    if (flag == 1) {
        text.setCharacterSize(50);
        text.setPosition(sf::Vector2f(125, y));
    }
    else {
        text.setCharacterSize(40);
        text.setPosition(sf::Vector2f(350, y));
    }
    text.setStyle(sf::Text::Bold);
    text.setFillColor(sf::Color(0, 0, 0));
    window.draw(text);
}
void Elements::renderLBoard(sf::RenderWindow& window, int score) {
    std::stringstream str_score;
	str_score << score;
    std::string line = "Your score is " + str_score.str();
    printOut(window, line, 100, 1);
    line.clear();
	std::fstream file;
	file.open ("score_list.txt",std::fstream::in);
    for (int i = 0; i < SCORE && getline(file, line); i++)
        printOut(window, line, 100 * (i + 2), 2);
}

static int checkPos(sf::Vector2i pos, int flag) {
    if (pos.y >= 80 && pos.y <= 280)
        return 1;
    else if (pos.y >= 360 && pos.y <= 560)
        return 2;
    else if (pos.y >= 640 && pos.y <= 840)
        return 5;
    else if (pos.y >= 920 && pos.y <= 1120)
        return 4;
    return flag;
}
int Elements::mousePress(sf::RenderWindow &window, int flag) {
    sf::Vector2i pos = sf::Mouse::getPosition(window);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)
        && pos.x >= 100 && pos.x <= 700) {
		if (!m_pressed) {
			m_pressed = true;
            return checkPos(pos, flag);
		}
	}
	else
		m_pressed = false;
    return flag;
}


