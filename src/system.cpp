#include "../include/system.h"

void System::ReadPremierLeagueInfo(){
   vector<vector<string>> CSVFileContent = readCSV(PREMIER_LEAGUE_FILE);
   for(size_t i = SKIPPED_LINE_CNT; i < CSVFileContent.size(); i++){
       RealTeam* rt;
       Player* p;
       for(size_t j = 0; j < TEAMS_COLUMN_SIZE; j++){
           if(j == TEAM_NAME){
               rt = new RealTeam(CSVFileContent[i][j]);
           }
           vector<string> playerStr = splitString(CSVFileContent[i][j], FIELD_DELIM);
           Role r;
           if(j == TEAM_GOAL_KEEPER){
               r = GOAL_KEEPER;
           }
           if(j == TEAM_DEFENDER){
               r = DEFENDER;
           }
           if(j == TEAM_MIDFIELDER){
               r = MIDFIELDER;
           }
           if(j == TEAM_FORWARD){
               r = FORWARD;
           }
           for(size_t k = 0; k < playerStr.size(); k++){
               p = new Player(playerStr[k], r);
               players.push_back(p);
               rt -> pushPlayer(p);
           }
           leagueTeams.push_back(rt);
       }
   }
}

System::System(){

}

System::~System(){
    for(auto rt : leagueTeams){
        delete rt;
    }
    for(auto p : players){
        delete p;
    }
}
