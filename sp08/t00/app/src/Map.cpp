#include "ptr.h"

Map::Map(size_t width, size_t height, std::shared_ptr<Player>& player)
    : m_width(width), m_height(height), 
      m_map(new char[width * height]), m_player(player) {
  generateMap();
}

void Map::outputMap() const {
  size_t player = m_player->posY() * m_width + m_player->posX();
  auto ptr = m_map.get();

  for (int i = 0; i < m_width * m_height; ++i) {
    if (i == player)
      std::cout << m_player->getIdentifier() << ' ';
    else
      std::cout << *(ptr + i) << ' ';
    if (((i + 1) % m_width) == 0)
      std::cout << '\n';
  }
  std::cout << ":> ";
}

size_t Map::width() const { return m_width; }

size_t Map::height() const { return m_height; }

void Map::generateMap() {
  int r;
  srand(time(NULL));
  for (int i = 0; i < m_width * m_height; ++i) {
    r = rand() % 7;
    if (r == 1)
      m_map[i] = 'T';
    else if (r == 2)
      m_map[i] = '@';
    else
      m_map[i] = '.';
  }
  outputMap();
}