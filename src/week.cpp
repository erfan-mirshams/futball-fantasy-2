#include "../include/week.h"

Week::Week() {}

Week::~Week() {
  for (auto g : games) {
    delete g;
  }
}

double Week::getScore(Player *p) {
  return playerRawScore[p];
}

void Week::proccessGoalDetails(Game* g){
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

void Week::proccessResult(Game* g){
    int score[2] = {0, 0};
    if(g->result[0] == g->result[1]){
        score[0] = score[1] = 1;
    }
    if(g->result[0] > g->result[1]){
        score[0] = 5;
        score[1] = -1;
    }
    if(g->result[0] < g->result[1]){
        score[0] = -1;
        score[1] = 5;
    }
    for(int i = 0 ; i < TEAMS_PARTICIPATING_IN_GAMES ; i ++){
        for(auto p : g->teamPlayers[i])
            playerRawScore[p] += score[i];
        playerRawScore[g->teamPlayers[i][GOALER]] -= g->result[!i];
        if(!g->result[!i])  
            playerRawScore[g->teamPlayers[i][GOALER]] += 5;
    }
}

void Week::initializeScores(Player** p){
    auto &mp = playerRawScore;
    mp[p[GOALER]] = 3;
    for(size_t i = LEFT_DEFENDER; i <= RIGHT_DEFENDER ; i ++)
        mp[p[i]] = 1;
}

void Week::proccess() {
  for (auto g : games) {
    for(int i = 0 ; i < TEAMS_PARTICIPATING_IN_GAMES ; i ++)
        initializeScores(g->teamPlayers[i]);
    proccessGoalDetails(g);
    proccessResult(g);
  }
}