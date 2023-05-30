#include "../include/general.h"
#include "../include/io.h"
#include "../include/system.h"

string handleGetCommand(System &sys, vector<string> vecStr){
  if(vecStr[0] == TEAM_OF_THE_WEEK_CMD){
    int weekNum = 0;
    if(vecStr.size() > 1){
      weekNum = stoi(vecStr[3]);
    }
    return sys.teamOfTheWeek(weekNum);
  }
  throw logic_error(NOT_FOUND_MSG);
}

string handleCommand(System &sys, vector<string> vecStr){
  if(vecStr[0] == GET_CMD_STR){
    vecStr.erase(vecStr.begin());
    return handleGetCommand(sys, vecStr);
  }
  throw logic_error(NOT_FOUND_MSG);
}

int main() {
  System sys;
  sys.readPremierLeagueInfo();
  sys.readWeeksInfo();
  string CMDLine;
  while(getline(cin, CMDLine)){
    cout << handleCommand(sys, splitIntoWords(CMDLine));
  }
  cerr << sys.leagueStandings();
  return 0;
}
