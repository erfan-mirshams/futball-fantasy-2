#ifndef GENERAL_H_
#define GENERAL_H_

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

const int TEAMS_COLUMN_SIZE = 5;
const string DATA_DIR = "data";
const string DIR_DELIM = "/";
const string PERMISSION_DENIED_ERR = "Permission Denied";

enum TEAMS_COLUMN{TEAM_NAME, TEAM_GOAL_KEEPER, TEAM_DEFENDER, TEAM_MIDFIELDER, TEAM_FORWARD};
#endif // GENERAL_H_
