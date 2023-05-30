#ifndef SYSTEM_H_
#define SYSTEM_H_

#include "general.h"
#include "player.h"
#include "real_team.h"
#include "io.h"
#include "week.h"

const string PREMIER_LEAGUE_FILE = "premier_league.csv";
const string WEEK_FILE_TEMP = "week";

class System{
public:
    void ReadPremierLeagueInfo();
    void ReadWeeksInfo();
    System();
    virtual ~System();
private:
    vector<RealTeam*> leagueTeams;
    vector<Player*> players;
    vector<Week*> weeks;
};

#endif // SYSTEM_H_
