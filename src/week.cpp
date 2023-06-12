#include "../include/week.h"

Week::Week() {}

Week::~Week() {
  for (auto g : games) {
    delete g;
  }
}

double Week::getScore(Player *p) {
  if (!playerRawScore.count(p)) {
    return -1;
  }
  return playerRawScore[p];
}

void Week::proccess() {
  for (auto g : games) {
    for (auto p : g->ownGoals)
      p->addGoal();
    for (auto p : g->teamGoals[0])
      p->addGoal();
    for (auto p : g->teamGoals[1])
      p->addGoal();
    for (auto p : g->assists)
      p->addAssist();
    for (int i = 0; i < TEAMS_PARTICIPATING_IN_GAMES; i++)
      if (!g->result[i])
        for (auto p : g->teamPlayers[i])
          p->addCleanSheet();
  }
}