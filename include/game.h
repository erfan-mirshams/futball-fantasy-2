#ifndef GAME_H_
#define GAME_H_

#include "general.h"
#include "player.h"
#include "real_team.h"

const int TEAMS_PARTICIPATING_IN_GAMES = 2;

struct Game {
  RealTeam *team[TEAMS_PARTICIPATING_IN_GAMES];
  int result[TEAMS_PARTICIPATING_IN_GAMES];
};

#endif // GAME_H_
