#pragma once

#include "header.h"

#define SCORE 5
#define ROCKS 35000
#define SIZE 40
#define MSX_TEXTURE 600
#define MSY_TEXTURE 200
#define WINDOW_X 800
#define WINDOW_Y 1200

class Snake;

class Elements {
public:
    Elements(int size);
    ~Elements();

    void createFood(sf::RenderWindow &window,
                    Snake snake,
                    int width,
                    int heigh);
    void createRocks(sf::RenderWindow &window,
                    Snake snake,
                    int width,
                    int heigh);
    void renderElements(sf::RenderWindow &window);
    void renderMenu(sf::RenderWindow& window);
    void renderLBoard(sf::RenderWindow& window, int score);
    int mousePress(sf::RenderWindow &window, int flag);
    bool isRock(int x, int y);
    // bool moveRight;
    int xy_food[2];
    std::vector<std::pair<int, int> > rock;

private:
    bool m_pressed;
    sf::Texture m_rock;
    sf::Texture m_food;
    sf::Texture m_normal;
    sf::Texture m_hard;
    sf::Texture m_lboard;
    sf::Texture m_exit;
};
