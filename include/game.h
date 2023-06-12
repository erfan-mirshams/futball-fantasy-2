#ifndef GAME_H_
#define GAME_H_

#include "general.h"
#include "player.h"
#include "real_team.h"

struct Game {
  RealTeam *team[TEAMS_PARTICIPATING_IN_GAMES];
  Player *teamPlayers[TEAMS_PARTICIPATING_IN_GAMES][TEAM_SIZE];
  int result[TEAMS_PARTICIPATING_IN_GAMES];
  vector<Player *> ownGoals;
  vector<Player *> teamGoals[TEAMS_PARTICIPATING_IN_GAMES];
  vector<Player *> assists;
};

#endif // GAME_H_
