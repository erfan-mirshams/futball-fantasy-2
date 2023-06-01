#include "../include/account.h"

Account::Account() {}

Account::Account(string _name, string _pass) {
  name = _name;
  pass = _pass;
}

bool Account::authenticate(string _pass) { return (pass == _pass); }

Account::~Account() {}
