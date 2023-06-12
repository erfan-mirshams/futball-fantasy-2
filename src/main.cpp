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
  if (vecStr[0] == PLAYERS_CMD) {
    string teamName = vecStr[3];
    bool sorted =
        (find(vecStr.begin(), vecStr.end(), RANKS_STR) != vecStr.end());
    int role = NA;
    if (vecStr.size() > 4 and vecStr[4] != RANKS_STR) {
      role = sys.findRole(vecStr[4]);
    }
    return sys.stringifyTeamPlayers(replaceDelimWithSpace(vecStr[3]), sorted,
                                    role);
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
  if (vecStr[0] == SQUAD_CMD) {
    if (vecStr.size() > 1) {
      return sys.getSquad(vecStr[3]);
    }
    return sys.getSquad();
  }
  if (vecStr[0] == USERS_RANKING_CMD) {
    return sys.usersRanking();
  }
  if (vecStr[0] == SHOW_BUDGET_CMD) {
    return sys.getBudget();
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
  if (vecStr[0] == LOGOUT_CMD) {
    return sys.logOut();
  }
  if (vecStr[0] == CLOSE_TRANSFER_CMD) {
    return sys.closeTransferWindow();
  }
  if (vecStr[0] == OPEN_TRANSFER_CMD) {
    return sys.openTransferWindow();
  }
  if (vecStr[0] == SELL_PLAYER_CMD) {
    vector<string> pName(vecStr.begin() + 3, vecStr.end());
    return sys.sellPlayer(stitchWordsWithSpace(pName));
  }
  if (vecStr[0] == BUY_PLAYER_CMD) {
    vector<string> pName(vecStr.begin() + 3, vecStr.end());
    return sys.buyPlayer(stitchWordsWithSpace(pName));
  }
  if (vecStr[0] == PASS_WEEK_CMD) {
    return sys.passWeek();
  }
  if (vecStr[0] == SET_CAPTAIN_CMD) {
    vector<string> pName(vecStr.begin() + 3, vecStr.end());
    return sys.setCaptain(stitchWordsWithSpace(pName));
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

void handleInput(System &sys) {
  string CMDLine;
  while (getline(cin, CMDLine)) {
    try {
      cout << handleCommand(sys, splitIntoWords(CMDLine));
    } catch (exception &e) {
      cout << e.what() << endl;
    }
  }
}

int main() {
  System sys;
  sys.readPremierLeagueInfo();
  sys.readWeeksInfo();
  handleInput(sys);
  return 0;
}
