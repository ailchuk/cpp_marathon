#include "src/header.h"

#define PX_SIZE 14

void Tick(int width, int height);

void parse(int ac) {
  if (ac != 3) {
    std::cerr << "usage: ./race00 [width] [height]\n";
    exit(EXIT_FAILURE);
  }
}

struct Snake
{
    int x, y;
} s[300 * 300];

struct Fruit
{
    int x, y;
} f;

int dir, num = 4;
int N = 30, M = 20;

int main(int ac, char** av) {
  parse(ac);
  int width = std::stoi(av[1]);
  int height = std::stoi(av[2]);
  sf::RenderWindow window(sf::VideoMode(width, height), "Snake");

  srand(time(0));
  float timer = 0, delay = 0.1;
  sf::Clock clock;
  
  f.x = 10;
  f.y = 10;

  sf::Texture squaret, apple;
  squaret.loadFromFile("app/resources/orange.png");
  apple.loadFromFile("app/resources/red.png");

  sf::Sprite orange(squaret), red(apple);
  // orange.setColor(Color())

  while (window.isOpen()) {
    float time = clock.getElapsedTime().asSeconds();
    clock.restart();
    timer += time;
    
    sf::Event appEvent;
    while (window.pollEvent(appEvent)) {
      if (appEvent.type == sf::Event::Closed || appEvent.key.code == sf::Keyboard::Escape)
        window.close();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
      dir = 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
      dir = 2;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
      dir = 3;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
      dir = 0;
    window.clear(sf::Color(26, 26, 36));
 
    if (timer > delay) {
      timer = 0;
      Tick(width, height);
    }
    for (int i = 0; i < num; i++) {
        orange.setPosition(s[i].x * PX_SIZE, s[i].y * PX_SIZE);
        window.draw(orange); 
    }   
 

    // for (int i = 0; i < num; i++) {
    //   red.setPosition(s[i].x * 16, s[i].y * 16);
    //   window.draw(red);
    //   std::cout << i << " ";
    // }
    // if (f.x)
    red.setPosition(f.x * PX_SIZE, f.y * PX_SIZE);
    window.draw(red);

    window.display();
  }
}

void Tick(int width, int height) {
    for (int i = num; i > 0; --i) {
        s[i].x = s[i - 1].x; 
        s[i].y = s[i - 1].y;
    }

    if (dir == 0) 
      s[0].y += 1;
    if (dir == 1)
      s[0].x -= 1;
    if (dir == 2)
      s[0].x += 1;
    if (dir == 3)
      s[0].y -= 1;

    if ((s[0].x == f.x) && (s[0].y == f.y)) { // удлиняет змейку если она сьела фрукт
        num ++; 
        f.x = rand() % (width / PX_SIZE);
        f.y = rand() % (height / PX_SIZE);
    }

    if (s[0].x > width / PX_SIZE)
      exit(EXIT_FAILURE); // s[0].x = 0;
    if (s[0].x < 0)
      exit(EXIT_FAILURE); // s[0].x = width;
    if (s[0].y > height / PX_SIZE)
      exit(EXIT_FAILURE); //s[0].y = 0; 
    if (s[0].y < 0)
      exit(EXIT_FAILURE); // s[0].y = height;

    for (int i = 1; i < num; i++) {
        if (s[0].x == s[i].x && s[0].y == s[i].y)
          num = i;
          // std::cout << num << " ";
          // if (s[0].x == s[i].x)
          // exit(EXIT_FAILURE);
    }
}