#ifndef GENERAL_H_
#define GENERAL_H_

#include <algorithm>
#include <cstring>
#include <dirent.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

using namespace std;

const int DEFAULT_BUDGET = 2500;
const int TEAMS_COLUMN_SIZE = 5;
const int WEEKS_COLUMN_SIZE = 8;
const int DEFENDER_CAP = 2;
const int SELL_CAP = 2;
const int DRAW_SCORE = 1;
const int WINNING_SCORE = 3;
const int TEAM_SIZE = 11;
const int NA = -1;
const int FANTASY_TEAM_SIZE = 5;
const int TEAMS_PARTICIPATING_IN_GAMES = 2;
const double CAPTAIN_COEF = 2;
const string CAPTAIN_STR = "(CAPTAIN)";
const string DATA_DIR = "data";
const string DIR_DELIM = "/";
const string NAME_DELIM = "_";
const string ROW_DELIM = " | ";
const string PERMISSION_DENIED_ERR = "Permission Denied";
const string EMPTY_ERR = "Empty";
const string BAD_REQUEST_ERR = "Bad Request";
const string CSV_EXT = ".csv";
const string WEEK_DIR = "weeks_stats";
const string NOT_FOUND_MSG = "Not Found";
const string GET_CMD_STR = "GET";
const string POST_CMD_STR = "POST";
const string PUT_CMD_STR = "PUT";
const string DELETE_CMD_STR = "DELETE";
const string OK_STR = "OK";
const string SIGNUP_CMD = "signup";
const string LOGIN_CMD = "login";
const string DEF_ADMIN_USER = "admin";
const string DEF_ADMIN_PASS = "123456";
const string REGISTER_ADMIN_CMD = "register_admin";
const string TEAM_OF_THE_WEEK_CMD = "team_of_the_week";
const string LEAUGE_STANDINGS_CMD = "league_standings";
const string MATCHES_RESULT_LEAGUE_CMD = "matches_result_league";
const string LOGOUT_CMD = "logout";
const string CLOSE_TRANSFER_CMD = "close_transfer_window";
const string OPEN_TRANSFER_CMD = "open_transfer_window";
const string SELL_PLAYER_CMD = "sell_player";
const string PLAYERS_CMD = "players";
const string BUY_PLAYER_CMD = "buy_player";
const string PASS_WEEK_CMD = "pass_week";
const string SQUAD_CMD = "squad";
const string SET_CAPTAIN_CMD = "set_captain";
const string NOT_AVAILABLE_PLAYER_ERR =
    "This player is not available for next week";
const string USERS_RANKING_CMD = "users_ranking";
const string QM = "?";
const string RANKS_STR = "ranks";
const string OWN_GOAL_STR = "OWN_GOAL";
const string SHOW_BUDGET_CMD = "show_budget";

enum TEAMS_COLUMN {
  TEAM_NAME,
  TEAM_GOAL_KEEPER,
  TEAM_DEFENDER,
  TEAM_MIDFIELDER,
  TEAM_FORWARD
};
enum WEEKS_COLUMN {
  WEEK_MATCH,
  WEEK_RESULT,
  WEEK_INJURED,
  WEEK_YELLOW_CARDS,
  WEEK_RED_CARDS,
  WEEK_GOAL_DATA,
  WEEK_TEAM1,
  WEEK_TEAM2
};

enum Role { GOAL_KEEPER, DEFENDER, MIDFIELDER, FORWARD };
const Role FANTASY_ROLES[FANTASY_TEAM_SIZE] = {GOAL_KEEPER, DEFENDER, DEFENDER,
                                               MIDFIELDER, FORWARD};
enum FullRole {
  GOALER,
  LEFT_DEFENDER,
  MID_LEFT_DEFENDER,
  MID_RIGHT_DEFENDER,
  RIGHT_DEFENDER,
  LEFT_MID,
  MID_MID,
  RIGHT_MID,
  LEFT_FORWARD,
  MID_FORWARD,
  RIGHT_FORWARD
};
bool contains(string s, string t);
#endif // GENERAL_H_
