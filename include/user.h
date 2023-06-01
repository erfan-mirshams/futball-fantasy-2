#ifndef USER_H_
#define USER_H_

#include "account.h"
#include "general.h"
#include "player.h"

class User : public Account {
public:
  User(string _name, string _pass);
  virtual ~User();
  bool isAdmin() { return false; }
  void sellPlayer(Player *p);
  bool hasCompleteTeam();
  int firstEmptyRole(Role r);
  int findPlayerId(Player *p);
  void buyPlayer(Player *p);

private:
  Player *fantasyTeam[FANTASY_TEAM_SIZE];
};

#endif // USER_H_
