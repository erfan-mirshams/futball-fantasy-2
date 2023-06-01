#ifndef USER_H_
#define USER_H_

#include "account.h"
#include "general.h"
#include "player.h"

class User : public Account {
public:
  User(string _name, string _pass);
  virtual ~User();

private:
  Player *fantasyTeam[FANTASY_TEAM_SIZE];
};

#endif // USER_H_
