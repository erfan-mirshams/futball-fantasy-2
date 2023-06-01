#ifndef PLAYER_H_
#define PLAYER_H_

#include "general.h"

const int YELLOW_CARD_CAP = 3;
const int INJURY_SUSPENSION = 3;

class Player {
public:
  Player(string _name, Role _role);
  virtual ~Player();
  inline string getName() { return name; }
  inline Role getRole() { return role; }
  inline bool isSuspended() { return suspendedWeeks; }
  void redCardPenalty();
  void yellowCardPenalty();
  inline void injuryPenalty() { suspendedWeeks = INJURY_SUSPENSION; }
  inline void passWeekUpdate() {
    suspendedWeeks--;
    suspendedWeeks = max(suspendedWeeks, 0);
  }

private:
  string name;
  Role role;
  int yellowCardCnt;
  int suspendedWeeks;
};

#endif // PLAYER_H_
