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
