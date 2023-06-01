#ifndef SYSTEM_H_
#define SYSTEM_H_

#include "general.h"
#include "io.h"
#include "player.h"
#include "real_team.h"
#include "week.h"

const string PREMIER_LEAGUE_FILE = "premier_league.csv";
const string WEEK_FILE_TEMP = "week";

struct StandingEntry {
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
  StandingEntry calculateTeamStandingEntry(RealTeam *rt, int weekNum);
  int whoWon(int weekNum, int gameInd);
  string leagueStandings();
  string teamOfTheWeek(int weekNum);
  string matchesResult(int weekNum);
  inline int getCurWeekNum() { return curWeekNum; }

private:
  int curWeekNum;
  vector<RealTeam *> leagueTeams;
  vector<Player *> players;
  vector<Week *> weeks;
};

#endif // SYSTEM_H_
