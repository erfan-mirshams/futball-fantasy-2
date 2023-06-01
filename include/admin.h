#ifndef ADMIN_H_
#define ADMIN_H_

#include "account.h"

class Admin : public Account {
public:
  Admin(string _name, string _pass);
  virtual ~Admin();
  bool isAdmin() { return true; }
};

#endif // ADMIN_H_
