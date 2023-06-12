#include "../include/user.h"

User::User(string _name, string _pass) : Account(_name, _pass) {
  point = 0;
  sellsCnt = 0;
  getsSellRestrcition = 0;
  for (int i = 0; i < FANTASY_TEAM_SIZE; i++) {
    fantasyTeam[i] = nullptr;
  }
}

User::~User() {}

bool User::hasCompleteTeam() {
  for (int i = 0; i < FANTASY_TEAM_SIZE; i++) {
    if (fantasyTeam[i] == nullptr) {
      return false;
    }
  }
  return true;
}

int User::findPlayerId(Player *p) {
  int ans = NA;
  for (int i = 0; i < FANTASY_TEAM_SIZE; i++) {
    if (fantasyTeam[i] == nullptr) {
      continue;
    }
    if (fantasyTeam[i] == p) {
      ans = i;
      break;
    }
  }
  return ans;
}

void User::setCaptain(Player *p){
  int id = findPlayerId(p);
  if (id == NA) {
    throw logic_error(NOT_FOUND_MSG);
  }
  captain = fantasyTeam[id];
}

void User::sellPlayer(Player *p) {
  int id = findPlayerId(p);
  if (id == NA) {
    throw logic_error(NOT_FOUND_MSG);
  }
  if (sellsCnt == SELL_CAP and getsSellRestrcition) {
    throw logic_error(PERMISSION_DENIED_ERR);
  }
  if(p == captain){
    captain = nullptr;
  }
  budget += p->getPrice();
  sellsCnt++;
  fantasyTeam[id] = nullptr;
}

int User::firstEmptyRole(Role r) {
  int ans = NA;
  for (int i = 0; i < FANTASY_TEAM_SIZE; i++) {
    if (FANTASY_ROLES[i] == r && fantasyTeam[i] == nullptr) {
      ans = i;
      break;
    }
  }
  return ans;
}

void User::buyPlayer(Player *p) {
  int id = findPlayerId(p);
  int fer = firstEmptyRole(p->getRole());
  if (id != NA || fer == NA) {
    throw logic_error(BAD_REQUEST_ERR);
  }
  if (p->isSuspended()) {
    throw logic_error(NOT_AVAILABLE_PLAYER_ERR);
  }
  if(p->getPrice() > budget){
    throw logic_error(BAD_REQUEST_ERR);
  }
  budget -= p->getPrice();
  fantasyTeam[fer] = p;
}

void User::addPoints(Week *w) {
  double sum = 0;
  bool flag = true;
  if (hasCompleteTeam()) {
    for (int i = 0; i < FANTASY_TEAM_SIZE; i++) {
      Player* p = fantasyTeam[i];
      if (p->isSuspended()) {
        flag = false;
        break;
      }
      if(p == captain){
        sum += p->calcScore(w->playerScore[p], 1);
      }
      else{
        sum += p->calcScore(w->playerScore[p], 0);
      }
    }
    if (flag) {
      point += sum;
    }
  }
}

bool playerCmp(Player *a, Player *b) { return (a->getName()) < (b->getName()); }

void User::sortPlayers() {
  int pre, ind;
  for (pre = ind = 0; ind < FANTASY_TEAM_SIZE; ind++) {
    if (fantasyTeam[ind]->getRole() != fantasyTeam[pre]->getRole()) {
      sort(fantasyTeam + pre, fantasyTeam + ind, playerCmp);
      pre = ind;
    }
  }
  sort(fantasyTeam + pre, fantasyTeam + ind, playerCmp);
}
