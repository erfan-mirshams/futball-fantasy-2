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
  inline Role getRole() {return role; }
  inline bool isSuspended() { return suspendedWeeks; }
  double getScore(){return ((scoredWeeksCnt) ? scoreSum/scoredWeeksCnt : 0);}
  void redCardPenalty();
  void yellowCardPenalty();
  inline void injuryPenalty() { suspendedWeeks = INJURY_SUSPENSION; }
  inline void passWeekUpdate(double score) {
    suspendedWeeks--;
    suspendedWeeks = max(suspendedWeeks, 0);
    if(score > 0){
        scoredWeeksCnt++;
        scoreSum += score;
    }   
  }

private:
  string name;
  Role role;
  int yellowCardCnt;
  int suspendedWeeks;
  double scoreSum = 0;
  int scoredWeeksCnt = 0;
};

#endif // PLAYER_H_
