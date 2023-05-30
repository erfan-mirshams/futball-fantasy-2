#ifndef REAL_TEAM_H_
#define REAL_TEAM_H_

#include "general.h"
#include "player.h"

class RealTeam{
public:
    RealTeam(string _name);
    void pushPlayer(Player* p);
private:
    string name;
    vector<Player*> players;
};

#endif // REAL_TEAM_H_
