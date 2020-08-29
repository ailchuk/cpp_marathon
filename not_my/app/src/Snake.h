#pragma once

#include "header.h"

#define DELAY 2

class Elements;

class Snake final {
public:
    Snake(int size);
    ~Snake();

    void startNewGame(int size, int w, int h, int& timer);
    void moveSnake(int length, char os);
    void moveSnake();
    void increaseSnake();
    void reduceSnake();
    std::pair<int, int> getXY();
    void renderSnake(sf::RenderWindow &win);
    int getSizeBlock();
    bool rockSnake(Elements el);
    bool eatYourself();
    bool IsNotSnake(int x, int y);

    std::vector<std::pair<int, int> > xy;
    sf::Texture texture;
    sf::Texture head;
    sf::Texture texture1;
    sf::Texture head1;
    int score;
    int skin;
    bool new_game;
    int rotate;

private:
    int m_size;
    char m_os;
};
