#ifndef IO_H_
#define IO_H_

#include "general.h"

const char CSV_DELIM = ',';
const char FIELD_DELIM = ';';
const char COLON_DELIM = ':';
const int SKIPPED_LINE_CNT = 1;

vector<string> splitString(string str, char delim);
vector<string> splitIntoWords(string str);
vector<vector<string>> readCSV(string fileName);
string stitchWordsWithSpace(vector<string> words);
int CSVFilesInDirCount(string path);

#endif // IO_H_
