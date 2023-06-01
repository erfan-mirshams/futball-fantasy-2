#ifndef PLAYER_H_
#define PLAYER_H_

#include "general.h"

class Player {
public:
  Player(string _name, Role _role);
  virtual ~Player();
  inline string getName() { return name; }
  inline Role getRole() { return role; }

private:
  string name;
  Role role;
  int yellowCardCnt;
  bool haveRedCard;
  int suspendedWeeks;
};

#endif // PLAYER_H_
