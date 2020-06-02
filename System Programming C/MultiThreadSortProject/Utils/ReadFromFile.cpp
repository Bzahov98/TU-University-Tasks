//
// Created by bzahov on 31.05.20 г..
//


#include "FileUtils.h"

using namespace std;

int FileUtils::readInputDataFromFile(const char *filename, int *data) {
    ifstream inputFile;
    string line;
    inputFile.open(filename, ios::out | ios::app);

    if (inputFile.is_open()) {
        while (getline(inputFile, line)) {
            //cout << line << '\n';
            SplitUtils::splitToTokens(line, data);
            //splitToList(line, result);
            //splitToVector(line, ",");
        }
        inputFile.close();
    } else {
        cerr << "Error with opening file" << endl;
        exit(EXIT_FAILURE);
    }
    return 0;
}