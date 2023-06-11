#ifndef WEEK_H_
#define WEEK_H_

#include "game.h"
#include "general.h"
#include "player.h"


struct Week {
  Week();
  virtual ~Week();
  vector<Game *> games;
  map<Player *, bool> injured;
  map<Player *, bool> yellowCardRecieved;
  map<Player *, bool> redCardRecieved;
  map<Player *, double> playerScore;
  double getScore(Player *p) {
    if (!playerScore.count(p)) {
      return -1;
    }
    return playerScore[p];
  }
};

#endif // WEEK_H_
