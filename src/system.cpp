#include "../include/system.h"

void System::readPremierLeagueInfo() {
  vector<vector<string>> CSVFileContent =
      readCSV(DATA_DIR + DIR_DELIM + PREMIER_LEAGUE_FILE);
  for (size_t i = SKIPPED_LINE_CNT; i < CSVFileContent.size(); i++) {
    RealTeam *rt;
    Player *p;
    for (size_t j = 0; j < TEAMS_COLUMN_SIZE; j++) {
      if (j == TEAM_NAME) {
        rt = new RealTeam(CSVFileContent[i][j]);
      }
      vector<string> playerStr = splitString(CSVFileContent[i][j], FIELD_DELIM);
      Role r;
      if (j == TEAM_GOAL_KEEPER) {
        r = GOAL_KEEPER;
      }
      if (j == TEAM_DEFENDER) {
        r = DEFENDER;
      }
      if (j == TEAM_MIDFIELDER) {
        r = MIDFIELDER;
      }
      if (j == TEAM_FORWARD) {
        r = FORWARD;
      }
      for (size_t k = 0; k < playerStr.size(); k++) {
        p = new Player(playerStr[k], r);
        players.push_back(p);
        rt->pushPlayer(p);
      }
    }
    leagueTeams.push_back(rt);
  }
}

void System::readWeeksInfo() {
  int weekCnt = CSVFilesInDirCount(DATA_DIR + DIR_DELIM + WEEK_DIR + DIR_DELIM);
  cerr << "CNT: " << weekCnt << endl;
  for (size_t i = 1; i <= weekCnt; i++) {
    vector<vector<string>> weekContent;
    cerr << ": " << DATA_DIR + DIR_DELIM + WEEK_DIR + DIR_DELIM + WEEK_FILE_TEMP + NAME_DELIM + to_string(i) + CSV_EXT << endl;
    weekContent = readCSV(DATA_DIR + DIR_DELIM + WEEK_DIR + DIR_DELIM + WEEK_FILE_TEMP +
                          NAME_DELIM + to_string(i) + CSV_EXT);
    Week *week = new Week();
    for (size_t j = SKIPPED_LINE_CNT; j < weekContent.size(); j++) {
      Game *g = new Game;
      for (size_t k = 0; k < WEEKS_COLUMN_SIZE; k++) {
        if (k == WEEK_MATCH) {
          vector<string> gt;
          gt = splitString(weekContent[j][k], COLON_DELIM);
          g->team[0] = findTeamByName(gt[0]);
          g->team[1] = findTeamByName(gt[1]);
        }
        if (k == WEEK_RESULT) {
          vector<string> resultStr;
          resultStr = splitString(weekContent[j][k], COLON_DELIM);
          g->result[0] = stoi(resultStr[0]);
          g->result[1] = stoi(resultStr[1]);
          week->games.push_back(g);
        }
        {
          vector<string> playerStr;
          if (k == WEEK_INJURED || k == WEEK_YELLOW_CARDS ||
              k == WEEK_RED_CARDS) {
            playerStr = splitString(weekContent[j][k], FIELD_DELIM);
            for (auto x : playerStr) {
              if (k == WEEK_INJURED) {
                week->injured[findPlayerByName(x)] = true;
              }
              if (k == WEEK_YELLOW_CARDS) {
                week->yellowCardRecieved[findPlayerByName(x)] = true;
              }
              if (k == WEEK_RED_CARDS) {
                week->redCardRecieved[findPlayerByName(x)] = true;
              }
            }
          }
        }
        if(k == WEEK_SCORES){
          vector<string> scoreInstanceStr;
          scoreInstanceStr = splitString(weekContent[j][k], FIELD_DELIM);
          for(auto sis : scoreInstanceStr){
            if(contains(sis, string(1, COLON_DELIM))){
              vector<string> vec;
              vec = splitString(sis, COLON_DELIM);
              week->playerScore[findPlayerByName(vec[0])] = stod(vec[1]);
            }
            else{
              week->playerScore[findPlayerByName(sis)] = 0;
            }
          }
        }
      }
    }
    weeks.push_back(week);
  }
}

RealTeam *System::findTeamByName(string name) {
  for (auto rt : leagueTeams) {
    if (rt->getName() == name) {
      return rt;
    }
  }
  cerr << "TEAMNAME: " << name << endl;
  throw logic_error(NOT_FOUND_MSG);
}

Player *System::findPlayerByName(string name) {
  for (auto p : players) {
    if (p->getName() == name) {
      return p;
    }
  }
  cerr << "PLAYERNAME: " << name << endl;
  throw logic_error(NOT_FOUND_MSG);
}

System::System() {}

System::~System() {
  for (auto rt : leagueTeams) {
    delete rt;
  }
  for (auto p : players) {
    delete p;
  }
  for(auto w : weeks){
    delete w;
  }
}

StandingEntry System::calculateTeamStandingEntry(RealTeam *rt, int weekNum){
  StandingEntry se = {rt -> getName(), 0, 0, 0};
  for(size_t i = 0; i < weekNum; i++){
    int teamInd = NA;
    int gameInd = NA;
    for(size_t j = 0; j < weeks[i]->games.size(); j++){
      for(int k = 0; k < 2; k++){
        if(weeks[i] -> games[j] -> team[k] == rt){
          teamInd = k;
          gameInd = j;
        }
      }
      if(gameInd != NA){
        break;
      }
    }
    se.gf += weeks[i] -> games[gameInd] -> result[teamInd];
    se.ga += weeks[i] -> games[gameInd] -> result[teamInd ^ 1];
    int x = whoWon(weekNum, gameInd);
    if(x == teamInd){
      se.score += WINNING_SCORE;
    }
    if(x == 2){
      se.score += DRAW_SCORE;
    }
  }
  return se;
}

int System::whoWon(int weekNum, int gameInd){
  int ans[TEAMS_PARTICIPATING_IN_GAMES];
  for(int i = 0; i < TEAMS_PARTICIPATING_IN_GAMES; i++){
    ans[i]= weeks[weekNum] -> games[gameInd] -> result[i];
  }
  if(ans[0] > ans[1]){
    return 0;
  }
  if(ans[0] == ans[1]){
    return 2;
  }
  return 1;
}

bool standingEntryCmp(StandingEntry a, StandingEntry b){
  if(a.score > b.score){
    return true;
  }
  if(b.score > a.score){
    return false;
  }
  if(a.gf - a.ga > b.gf - b.ga){
    return true;
  }
  if(b.gf - b.ga > a.gf - a.ga){
    return false;
  }
  if(a.gf > b.gf){
    return true;
  }
  if(b.gf > a.gf){
    return false;
  }
  if(a.teamName < b.teamName){
    return true;
  }
  return false;
}
