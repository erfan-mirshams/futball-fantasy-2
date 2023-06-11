#ifndef SYSTEM_H_
#define SYSTEM_H_

#include "admin.h"
#include "general.h"
#include "io.h"
#include "player.h"
#include "real_team.h"
#include "user.h"
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
  string signUp(string _name, string _password);
  string logIn(string _name, string _password);
  string registerAdmin(string _name, string _password);
  User *findUserByName(string name);
  inline int getCurWeekNum() { return curWeekNum; }
  string logOut();
  void verifyAdmin();
  void verifyUser();
  string openTransferWindow();
  string closeTransferWindow();
  string sellPlayer(string _name);
  string buyPlayer(string _name);
  string passWeek();
  string getSquad();
  string getSquad(string userName);
  string usersRanking();
  string stringifyTeamPlayers(string teamName, bool sorted, int role);
  int findRole(string role);

private:
  int curWeekNum;
  Account *curAccount;
  Admin admin;
  bool isTransferWindowOpen;
  vector<RealTeam *> leagueTeams;
  vector<Player *> players;
  vector<Week *> weeks;
  vector<User *> users;
};

#endif // SYSTEM_H_
