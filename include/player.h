#ifndef PLAYER_H_
#define PLAYER_H_

#include "general.h"

enum Role{GOAL_KEEPER, DEFENDER, MIDFIELDER, FORWARD};

class Player{
public:
    Player(string _name, Role _role);
    virtual ~Player();
private:
    string name;
    Role role;
    int yellowCardCnt;
    bool haveRedCard;
    int suspendedWeeks;
};

#endif // PLAYER_H_
