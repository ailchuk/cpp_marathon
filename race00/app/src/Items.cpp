#include "Items.h"


Items::Items(int type) {
    switch (type)
    {
      case DEFAULT_ITEM:
        m_score = 1;
        m_count = 1;
        break;
      case BEST_ITEM:
        m_score = 5;
        m_count = 1;
      case ENEMY_ITEM:
        m_score = -1;
        m_count = 1;
        break;
      default: break;
    }
}

int Items::getScore() const {
    return m_score;
}
