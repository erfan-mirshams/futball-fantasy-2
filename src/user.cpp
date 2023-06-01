#include "../include/user.h"

User::User(string _name, string _pass) : Account(_name, _pass) {
  point = 0;
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

void User::sellPlayer(Player *p) {
  int id = findPlayerId(p);
  if (id == NA) {
    throw logic_error(NOT_FOUND_MSG);
  }
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
  fantasyTeam[fer] = p;
}

void User::addPoints(Week *w) {
  double sum = 0;
  bool flag = true;
  if (hasCompleteTeam()) {
    for (int i = 0; i < FANTASY_TEAM_SIZE; i++) {
      if (fantasyTeam[i]->isSuspended()) {
        flag = false;
        break;
      }
      sum += w->playerScore[fantasyTeam[i]];
    }
    if (flag) {
      point += sum;
    }
  }
}
