#include "../include/general.h"
#include "../include/io.h"
#include "../include/system.h"

string handleGetCommand(System &sys, vector<string> vecStr) {
  if (vecStr[0] == TEAM_OF_THE_WEEK_CMD) {
    int weekNum = sys.getCurWeekNum();
    if (vecStr.size() > 1) {
      weekNum = stoi(vecStr[3]) - 1;
    }
    return sys.teamOfTheWeek(weekNum);
  }
  if (vecStr[0] == MATCHES_RESULT_LEAGUE_CMD) {
    int weekNum = sys.getCurWeekNum();
    if (vecStr.size() > 1) {
      weekNum = stoi(vecStr[3]) - 1;
    }
    return sys.matchesResult(weekNum);
  }
  if (vecStr[0] == LEAUGE_STANDINGS_CMD) {
    return sys.leagueStandings();
  }
  throw logic_error(NOT_FOUND_MSG);
}

string handlePostCommand(System &sys, vector<string> vecStr) {
  if (vecStr[0] == SIGNUP_CMD) {
    return sys.signUp(vecStr[3], vecStr[5]);
  }
  if (vecStr[0] == LOGIN_CMD) {
    return sys.logIn(vecStr[3], vecStr[5]);
  }
  if (vecStr[0] == REGISTER_ADMIN_CMD) {
    return sys.registerAdmin(vecStr[3], vecStr[5]);
  }
  throw logic_error(NOT_FOUND_MSG);
}

string handleCommand(System &sys, vector<string> vecStr) {
  if (!vecStr.size()) {
    return "";
  }
  if (vecStr[0] == GET_CMD_STR) {
    vecStr.erase(vecStr.begin());
    return handleGetCommand(sys, vecStr);
  }
  if (vecStr[0] == POST_CMD_STR) {
    vecStr.erase(vecStr.begin());
    return handlePostCommand(sys, vecStr);
  }
  throw logic_error(NOT_FOUND_MSG);
}

int main() {
  System sys;
  sys.readPremierLeagueInfo();
  sys.readWeeksInfo();
  string CMDLine;
  while (getline(cin, CMDLine)) {
    cout << handleCommand(sys, splitIntoWords(CMDLine));
  }
  cerr << sys.leagueStandings();
  return 0;
}
