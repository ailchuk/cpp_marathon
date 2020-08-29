#include "Snake.h"

#include <ctime>
#include <random>
#include <time.h>

int randNum(int low, int up) {
    std::random_device random;
    std::uniform_int_distribution<int> uid(low, up);
    int res = uid(random);

    return res;
}

Snake::Snake(int size) {
    rotate = 4;
    skin = 0;
    texture.loadFromFile("./resource/snake.png");
    texture1.loadFromFile("./resource/snake.png");
    head.loadFromFile("./resource/head.png");
    head1.loadFromFile("./resource/head.png");
    m_os = 'y';
}

Snake::~Snake() {
}

void Snake::startNewGame(int size, int w, int h, int& timer) {
    if (xy.empty()) {
        score = 0;
        new_game = true;
        int j = 0;

        for (int i = 0; i < 4; i++, j += size)
            xy.push_back(std::make_pair((w / 2) + j, h / 2));
        m_size = -size;
        m_os = 'y';
        timer = 0;
    }
}

int Snake::getSizeBlock() {
    return m_size;
}

std::pair<int, int> Snake::getXY() {
    return std::make_pair(xy[0].first, xy[0].second);
}

void Snake::increaseSnake() {
    xy.push_back(std::make_pair((xy.end() - 1)->first + m_size,
                                 (xy.end() - 1)->second + m_size));
}

void Snake::reduceSnake() {
    xy.pop_back();
}

bool Snake::eatYourself() {
    for (auto i = xy.begin() + 1; i != xy.end(); i++) {
        if (xy[0].first == i->first && xy[0].second == i->second)
            return true;
    }
    return false;
}

bool Snake::IsNotSnake(int x, int y) {
    for (auto i : xy) {
        if (i.first == x ||  i.second == y)
            return false;
    }
    return true;
}

static void moveSprite(sf::Sprite& sprite, int x, int y, int flag) {
    if (flag == 2)
        sprite.setPosition(x + SIZE, y + SIZE);
    else if (flag == 4)
        sprite.setPosition(x, y);
    else if (flag == 3)
        sprite.setPosition(x, y + SIZE);
    else
        sprite.setPosition(x + SIZE, y);
}
void Snake::renderSnake(sf::RenderWindow &win) {
    for (auto i : xy) {
        sf::Sprite sprite;
        if (i.first == xy.at(0).first && i.second == xy.at(0).second) {
            if (skin == 0) {
                sprite.setTexture(head);
                sprite.setColor(sf::Color(randNum(0, 255), randNum(0, 255), randNum(0, 255)));
            }
	        else {
                sprite.setTexture(head1);
                sprite.setColor(sf::Color(randNum(0, 255), randNum(0, 255), randNum(0, 255)));
            }
            sprite.setRotation(rotate * 90.f);
        }
	    else {
            if (skin == 0) {
                sprite.setTexture(texture);
                sprite.setColor(sf::Color(randNum(0, 255), randNum(0, 255), randNum(0, 255)));
            }
            else {
                sprite.setTexture(texture1);
                sprite.setColor(sf::Color(randNum(0, 255), randNum(0, 255), randNum(0, 255)));
            }
        }
        if (i.first == xy.at(0).first && i.second == xy.at(0).second)
            moveSprite(sprite, i.first, i.second, rotate);
        else
            sprite.setPosition(sf::Vector2f(i.first, i.second));
        win.draw(sprite);
    }
}

void Snake::moveSnake() {
    if (!xy.empty()) {
        for (auto i = xy.end() - 1; i != xy.begin(); i--) {
            i->first = (i - 1)->first;
            i->second = (i - 1)->second;  
        }
        m_os == 'x' ? xy[0].second += m_size : xy[0].first += m_size;
    }
}

static int setRotate(int length, char os) {
    if (length < 0 && os == 'x')
        return 1;
    else if (length > 0 && os == 'x')
        return 3;
    else if (length < 0 && os == 'y')
        return 4;
    else
        return 2;
}
void Snake::moveSnake(int length, char os) {
    rotate = setRotate(length,os);
    if ((os == m_os && m_size == length) ||
         (os == m_os && length == -m_size))
        return;
    m_os = os;
    length < 0 && m_size > 0 ? m_size *= -1 : 0;
    length > 0 && m_size < 0 ? m_size *= -1 : 0;
    for (auto i = xy.end() - 1; i != xy.begin(); i--) {
        i->first = (i - 1)->first;
        i->second = (i - 1)->second;  
    }
    os == 'x' ? xy[0].second += length : xy[0].first += length;   
}

bool Snake::rockSnake(Elements el) {
    for (auto i : el.rock)
        if (i.first == xy.at(0).first
            && i.second == xy.at(0).second)
            return true;
    return false;
}
