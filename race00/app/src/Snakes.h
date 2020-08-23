#ifndef SNAKES_H
#define SNAKES_H

#define ADD_1HP 1
#define SUB_1HP 2

#include "Items.h"

class Snakes {
private:
    int m_health;
    int m_score;
    bool m_isAlive;

public:
    Snakes();
    // ~Snake();

    void setScore(Items* item);
    int getScore() const;
    void uppdateHealth(int flag);

};

#endif
