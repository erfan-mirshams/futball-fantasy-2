#include "../include/io.h"

string trimBoth(string str){
    int stPos = 0, fnPos = (int)str.size();
    for(int i = 0; i < (int)str.size(); i++){
        if(!isspace(str[i])){
            stPos = i;
            break;
        }
    }
    for(int i = (int)str.size() - 1; ~i; i--){
        if(!isspace(str[i])){
            fnPos = i + 1;
            break;
        }
    }
    return str.substr(stPos, fnPos - stPos);
}

vector<string> splitString(string str, char delim){
     vector<string> elements;
     istringstream strStream(str);
     string element;
     while(getline(strStream, element, delim)){
         elements.push_back(trimBoth(element));
     }
     return elements;
}

vector<vector<string>> readCSV(string fileName){
    ifstream inputFile(fileName);
    vector<vector<string>> readFile;
    string lineOfFile;
    while(getline(inputFile, lineOfFile)){
        readFile.push_back(splitString(lineOfFile, CSV_DELIM));
    }
    inputFile.close();
    return readFile;
}

vector<string> splitIntoWords(string str){
    vector<string> elements;
    string::iterator it = str.begin();
    while(it != str.end()){
        elements.push_back(wordFromPosition(it, str.end()));
    }
    return elements;
}
