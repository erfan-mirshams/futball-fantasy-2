#ifndef WEEK_H_
#define WEEK_H_

#include "game.h"
#include "general.h"
#include "player.h"


class Week {
public:
  Week();
  ~Week();
  vector<Game *> games;
  map<Player *, bool> injured;
  map<Player *, bool> yellowCardRecieved;
  map<Player *, bool> redCardRecieved;
  map<Player *, double> playerRawScore;
  double getScore(Player *p);
  void proccess();
private:
  map<Player*, int> goals;
  map<Player*, int> assists;
  map<Player*, int> cleanSheets;
};

#endif // WEEK_H_
