#include "../include/real_team.h"

RealTeam::RealTeam(string _name) { name = _name; }

void RealTeam::pushPlayer(Player *p) { players.push_back(p); }

RealTeam::~RealTeam() {}

bool nameSort(Player *a, Player *b) { return a->getName() < b->getName(); }

bool scoreSort(Player *a, Player *b) {
  if (a->getScore() == b->getScore()) {
    return a->getName() < b->getName();
  }
  return a->getScore() > b->getScore();
}

void printDetails(Player *p, stringstream &ss) {
  ss << ROW_DELIM;
  switch (p->getRole()) {
  case (GOAL_KEEPER):
    ss << "clean sheets: " << p->getCleanSheet();
    break;
  case (FORWARD):
    ss << "goals: " << p->getGoal() << ROW_DELIM
       << "assists: " << p->getAssist();
    break;

  default:
    ss << "clean sheets: " << p->getCleanSheet() << ROW_DELIM
       << "goals: " << p->getGoal() << ROW_DELIM
       << "assists: " << p->getAssist();
  }
  ss << endl;
}

vector<Player *> RealTeam::findPlayers(bool sorted, int role) {
  vector<Player *> res;
  for (int i = 0; i < (int)players.size(); i++) {
    Player *p = players[i];
    if (role == -1 or p->getRole() == role) {
      res.push_back(p);
    }
  }
  if (sorted) {
    sort(res.begin(), res.end(), scoreSort);
  } else {
    sort(res.begin(), res.end(), nameSort);
  }
  return res;
}

string RealTeam::stringify(bool sorted, int role) {
  stringstream res;
  vector<Player *> pickedPlayers = findPlayers(sorted, role);
  if (pickedPlayers.empty())
    throw logic_error(BAD_REQUEST_ERR);
  res << "list of players:" << endl;
  for (int i = 0; i < (int)pickedPlayers.size(); i++) {
    Player *p = pickedPlayers[i];
    res << (i + 1) << ". name: " << p->getName() << ROW_DELIM
        << "role: " << p->getRoleString() << ROW_DELIM << "score: " << fixed
        << setprecision(1) << p->getScore() << ROW_DELIM
        << "cost: " << p->getPrice();
    printDetails(p, res);
  }
  return res.str();
}