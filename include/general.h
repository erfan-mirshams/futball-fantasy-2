#ifndef GENERAL_H_
#define GENERAL_H_

#include <cstring>
#include <dirent.h>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <utility>

using namespace std;

const int TEAMS_COLUMN_SIZE = 5;
const int WEEKS_COLUMN_SIZE = 6;
const int DRAW_SCORE = 1;
const int WINNING_SCORE = 3;
const int NA = -1;
const string DATA_DIR = "data";
const string DIR_DELIM = "/";
const string NAME_DELIM = "_";
const string PERMISSION_DENIED_ERR = "Permission Denied";
const string CSV_EXT = ".csv";
const string WEEK_DIR = "weeks_stats";
const string NOT_FOUND_MSG = "NOT FOUND";

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
  WEEK_SCORES
};

bool contains(string s, string t);
#endif // GENERAL_H_
