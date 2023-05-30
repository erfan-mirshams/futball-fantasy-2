#ifndef GAME_H_
#define GAME_H_

#include "general.h"
#include "real_team.h"
#include "player.h"

const int TEAMS_PARTICIPATING_IN_GAMES = 2;

struct Game{
    RealTeam* team[TEAMS_PARTICIPATING_IN_GAMES];
    int score[TEAMS_PARTICIPATING_IN_GAMES];
};

#endif // GAME_H_
