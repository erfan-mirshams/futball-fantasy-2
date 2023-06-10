#include "../include/player.h"

Player::Player(string _name, Role _role) {
  name = _name;
  role = _role;
  yellowCardCnt = 0;
  suspendedWeeks = 0;
}



Player::~Player() {}

void Player::redCardPenalty() {
  if (isSuspended()) {
    return;
  }
  suspendedWeeks = 1;
  return;
}

void Player::yellowCardPenalty() {
  yellowCardCnt++;
  if (isSuspended()) {
    yellowCardCnt = 0;
  }
  if (yellowCardCnt == YELLOW_CARD_CAP) {
    suspendedWeeks = 1;
  }
}

void Player::passWeekUpdate(double score) {
    suspendedWeeks--;
    suspendedWeeks = max(suspendedWeeks, 0);
    if(score > 0){
        scoredWeeksCnt++;
        scoreSum += score;
    }   
}

string Player::getRoleString(){
    switch(role){
        case(GOAL_KEEPER):
            return "gk";
        case(FORWARD):
            return "fw";
        case(MIDFIELDER):
            return "md";
        default:
            return "df";
    }
}   