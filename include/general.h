#ifndef GENERAL_H_
#define GENERAL_H_

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <dirent.h>

using namespace std;

const int TEAMS_COLUMN_SIZE = 5;
const string DATA_DIR = "data";
const string DIR_DELIM = "/";
const string NAME_DELIM = "_";
const string PERMISSION_DENIED_ERR = "Permission Denied";
const string CSV_EXT = ".csv";
const string WEEK_DIR = "week_stats";

enum TEAMS_COLUMN{TEAM_NAME, TEAM_GOAL_KEEPER, TEAM_DEFENDER, TEAM_MIDFIELDER, TEAM_FORWARD};
#endif // GENERAL_H_
