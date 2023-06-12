#include "../include/week.h"

Week::Week() {}

Week::~Week() {
  for (auto g : games) {
    delete g;
  }
}

double Week::getScore(Player *p) { return playerRawScore[p]; }

void Week::proccessGoalDetails(Game *g) {
  for (auto p : g->ownGoals)
    playerRawScore[p] -= 3;
  for (auto p : g->teamGoals[0])
    p->addGoal();
  for (auto p : g->teamGoals[1])
    p->addGoal();
  for (auto p : g->assists)
    p->addAssist();
  for (int i = 0; i < TEAMS_PARTICIPATING_IN_GAMES; i++)
    if (!g->result[!i])
      for (auto p : g->teamPlayers[i])
        p->addCleanSheet();
}

void Week::proccessResult(Game *g) {
  int score[2] = {0, 0};
  if (g->result[0] == g->result[1]) {
    score[0] = score[1] = 1;
  }
  if (g->result[0] > g->result[1]) {
    score[0] = 5;
    score[1] = -1;
  }
  if (g->result[0] < g->result[1]) {
    score[0] = -1;
    score[1] = 5;
  }
  for (int i = 0; i < TEAMS_PARTICIPATING_IN_GAMES; i++) {
    for (auto p : g->teamPlayers[i])
      playerRawScore[p] += score[i];
    playerRawScore[g->teamPlayers[i][GOALER]] -= g->result[!i];
    if (!g->result[!i])
      playerRawScore[g->teamPlayers[i][GOALER]] += 5;
  }
}

void Week::proccessDefenders(Game *g) {
  auto &mp = playerRawScore;
  for (int i = 0; i < TEAMS_PARTICIPATING_IN_GAMES; i++) {
    if (!g->result[!i])
      for (auto p : g->teamPlayers[i])
        if (p->getRole() == DEFENDER)
          mp[p] += 2;
    for (auto p : g->teamGoals[i])
      if (p->getRole() == DEFENDER)
        mp[p] += 4;
    for (auto p : g->teamGoals[!i])
      if (p == g->teamPlayers[!i][RIGHT_FORWARD] or
          p == g->teamPlayers[!i][RIGHT_DEFENDER])
        mp[g->teamPlayers[i][LEFT_DEFENDER]] -= 1;
    for (auto p : g->teamGoals[!i])
      if (p == g->teamPlayers[!i][LEFT_FORWARD] or
          p == g->teamPlayers[!i][LEFT_DEFENDER])
        mp[g->teamPlayers[i][RIGHT_DEFENDER]] -= 1;
    for (auto p : g->teamGoals[!i])
      if (p == g->teamPlayers[!i][MID_FORWARD] or
          p == g->teamPlayers[!i][MID_LEFT_DEFENDER] or
          p == g->teamPlayers[!i][MID_RIGHT_DEFENDER])
        mp[g->teamPlayers[i][MID_RIGHT_DEFENDER]] -= 1,
            mp[g->teamPlayers[i][MID_LEFT_DEFENDER]] -= 1;
  }
  for (auto p : g->assists)
    if (p->getRole() == DEFENDER)
      mp[p] += 3;
}

void Week::proccessMids(Game *g) {
  auto &mp = playerRawScore;
  for (int i = 0; i < TEAMS_PARTICIPATING_IN_GAMES; i++) {
    if (!g->result[!i])
      for (auto p : g->teamPlayers[i])
        if (p->getRole() == MIDFIELDER)
          mp[p] += 1;
    for (auto p : g->teamGoals[i]) {
      if (p->getRole() == MIDFIELDER) {
        mp[p] += 3;
        for (size_t j = LEFT_MID; j <= RIGHT_MID; j++)
          mp[g->teamPlayers[!i][j]] -= 1;
      }
    }
  }
  for (auto p : g->assists)
    if (p->getRole() == MIDFIELDER)
      mp[p] += 2;
}

void Week::proccessForwards(Game *g) {
  auto &mp = playerRawScore;
  for (int i = 0; i < TEAMS_PARTICIPATING_IN_GAMES; i++) {
    for (auto p : g->teamGoals[i])
      if (p->getRole() == FORWARD)
        mp[p] += 3;
    for (auto p : g->teamPlayers[i])
      if (p->getRole() == FORWARD and !goals.count(p))
        mp[p] -= 1;
  }
  for (auto p : g->assists)
    if (p->getRole() == FORWARD)
      mp[p] += 1;
}

void Week::initializeScores(Player **p) {
  auto &mp = playerRawScore;
  mp[p[GOALER]] = 3;
  for (size_t i = LEFT_DEFENDER; i <= RIGHT_DEFENDER; i++)
    mp[p[i]] = 1;
}

void Week::proccess() {
  for (auto g : games) {
    for (int i = 0; i < TEAMS_PARTICIPATING_IN_GAMES; i++)
      initializeScores(g->teamPlayers[i]);
    proccessGoalDetails(g);
    proccessResult(g);
    proccessDefenders(g);
    proccessMids(g);
    proccessForwards(g);
  }
}