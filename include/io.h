#ifndef IO_H_
#define IO_H_

#include "general.h"

const char CSV_DELIM = ',';
const int SKIPPED_LINE_CNT = 1;

vector<string> splitIntoWords(string str);
vector<vector<string>> readCSV(string fileName);

#endif // IO_H_
