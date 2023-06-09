#include "../include/real_team.h"

RealTeam::RealTeam(string _name) { name = _name; }

void RealTeam::pushPlayer(Player *p) { players.push_back(p); }

RealTeam::~RealTeam() {}

string RealTeam::stringify(){
    stringstream res;
    res << "list of players:" << endl;
    for(int i = 0 ; i < (int) players.size() ; i ++){
        Player* p = players[i];
        res << (i + 1) << ". name: " << p->getName()
            << ROW_DELIM << "role: " << p->getRole()
            << ROW_DELIM << "score: " << p->getScore() << endl;
    }
    return res.str();
}