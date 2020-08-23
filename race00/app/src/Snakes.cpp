#include "Snakes.h"

Snakes::Snakes() {
    m_health = 4;
    m_score = 0;
    m_isAlive = true;
}

// Snakes::~Snakes() {}

int Snakes::getScore() const {
    return m_score;
}

void Snakes::setScore(Items* item) {
    m_score += item->getScore();
}

void Snakes::uppdateHealth(int flag) {
    switch (flag) {
      case ADD_1HP:
        m_health += 1;
        break;
      case SUB_1HP:
        m_health -= 1;
      default:
        break;
    }
}
