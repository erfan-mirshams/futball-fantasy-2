#ifndef SYSTEM_H_
#define SYSTEM_H_

#include "general.h"
#include "io.h"
#include "player.h"
#include "real_team.h"
#include "week.h"

const string PREMIER_LEAGUE_FILE = "premier_league.csv";
const string WEEK_FILE_TEMP = "week";
const Role FANTASY_ROLES[FANTASY_TEAM_SIZE] = {GOAL_KEEPER, DEFENDER, DEFENDER, MIDFIELDER, FORWARD};

struct StandingEntry{
  string teamName;
  int score;
  int gf;
  int ga;
};

class System {
public:
  void readPremierLeagueInfo();
  void readWeeksInfo();
  System();
  virtual ~System();
  RealTeam *findTeamByName(string name);
  Player *findPlayerByName(string name);
  StandingEntry calculateTeamStandingEntry(RealTeam* rt, int weekNum);
  int whoWon(int weekNum, int gameInd);
  string leagueStandings();
  string teamOfTheWeek(int weekNum);
private:
  int curWeekNum;
  vector<RealTeam *> leagueTeams;
  vector<Player *> players;
  vector<Week *> weeks;
};

#endif // SYSTEM_H_
