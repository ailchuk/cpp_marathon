#ifndef ITEMS_H
#define ITEMS_H

#define DEFAULT_ITEM 1
#define BEST_ITEM 2
#define ENEMY_ITEM 3

class Items;

class Items {
private:
    int m_score;
    int m_count;

public:
    Items(int type);
    // ~Items() {}
    int getScore() const;
};

#endif
