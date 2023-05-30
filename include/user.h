#ifndef USER_H_
#define USER_H_

#include "account.h"
#include "player.h"

class User : public Account {
public:
  User(string _name, string _pass);
  virtual ~User();

private:
  Player *goalKeeper;
  Player *defenders[DEFENDER_CAP];
  Player *midfielder;
  Player *forward;
};

#endif // USER_H_
