#include "ptr.h"

MoveManager::MoveManager(std::shared_ptr<Player>& player, std::shared_ptr<Map>& map)
    : m_map(map), m_player(player) {}

bool MoveManager::checkMove(Direction dir) const {
  if (dir == Direction::Up) {
    if (m_player->posY() == 0)
      return false;
    return true;
  } else if (dir == Direction::Down) {
    if (m_player->posY() == m_map->height() - 1)
      return false;
    return true;
  } else if (dir == Direction::Left) {
    if (m_player->posX() == 0)
      return false;
    return true;
  } else {
    if (m_player->posX() == m_map->width() - 1)
      return false;
    return true;
  }
  return false;
}

void MoveManager::processInputAndMove(const std::string& inputStr) {
  std::stringstream ss(inputStr);
  std::string comm;
  Direction dir;

  if (!((ss >> comm) && ss.peek()) != 0) {
    std::cerr << "Invalid direction\n";
    m_map->outputMap();
    return;

  } else {
    if (comm == "u")
      dir = Direction::Up;
    else if (comm == "d")
      dir = Direction::Down;
    else if (comm == "r")
      dir = Direction::Right;
    else if (comm == "l")
      dir = Direction::Left;
    else if (comm == "e")
      exit(0);
    else {
      std::cerr << "Invalid direction\n";
      m_map->outputMap();
      return;
    }
  }
  if (checkMove(dir))
    m_player->movePlayer(dir);
  else
    std::cerr << "Invalid direction\n";
  m_map->outputMap();
}
