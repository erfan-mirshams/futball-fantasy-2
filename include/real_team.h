#ifndef REAL_TEAM_H_
#define REAL_TEAM_H_

#include "general.h"
#include "player.h"

class RealTeam {
public:
  RealTeam(string _name);
  void pushPlayer(Player *p);
  virtual ~RealTeam();
  inline string getName() { return name; }
  string stringify(bool sorted, int role);

private:
  string name;
  vector<Player *> players;
  vector<Player *> findPlayers(bool sorted, int role);
};

#endif // REAL_TEAM_H_
