#ifndef SYSTEM_H_
#define SYSTEM_H_

#include "general.h"
#include "player.h"
#include "real_team.h"
#include "io.h"

const string PREMIER_LEAGUE_FILE = "premier_league.csv";

class System{
public:
    void ReadPremierLeagueInfo();
    System();
    virtual ~System();
private:
    vector<RealTeam*> leagueTeams;
    vector<Player*> players;
};

#endif // SYSTEM_H_
