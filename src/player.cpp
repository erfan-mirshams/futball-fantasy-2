#include "../include/player.h"

Player::Player(string _name, Role _role) {
  name = _name;
  role = _role;
  yellowCardCnt = 0;
  haveRedCard = false;
  suspendedWeeks = 0;
}

Player::~Player() {}
