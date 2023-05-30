#include "../include/real_team.h"

RealTeam::RealTeam(string _name){
    name = _name;
}

void RealTeam::pushPlayer(Player *p){
    players.push_back(p);
}

RealTeam::~RealTeam(){

}
