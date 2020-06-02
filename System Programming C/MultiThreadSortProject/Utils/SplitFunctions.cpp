//
// Created by bzahov on 31.05.20 г..
//
#include "SplitFunctions.h"


void SplitUtils::splitToTokens(const string &inputString, int *data) {
    string basicString = inputString.substr(0, inputString.length());
    string delimiter = ",";
    size_t pos = 0;
    string token;
    int i = 0;
    while ((pos = basicString.find(delimiter)) != string::npos) {
        token = basicString.substr(0, pos);
        data[i++] = std::stoi(token);
        //cout <<"[" <<token<<"|" << data[i-1]<<"]"<< std::endl; // for debug
        basicString.erase(0, pos + delimiter.length());
    }
//    std::cout << ">" << basicString << std::endl; // for debug
    try {
        data[i] = std::stoi(basicString);
    } catch (exception ignored) {} // will not add not numeric data;

    cerr << endl << "FILE INPUT DATA" << endl;
    for (int j = 0; j <= i; ++j) {
        cerr << data[j] << ",";
    }cerr<<endl;


};

vector<int> SplitUtils::splitToVector(string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<int> result;

    while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        int tokenIntValue;
        try {
            // string -> integer
            tokenIntValue = std::stoi(token);

        } catch (exception e) {
            continue;  // dont add incorrect string(not numerable value) into vector
        }
        result.push_back(tokenIntValue);
    }
    try {
        int tokenIntValue;
        // string -> integer
        tokenIntValue = std::stoi(s.substr(pos_start));
        result.push_back(tokenIntValue);
    } catch (exception e) {
        // dont add incorrect string(not numerable value) into vector
    }

    cout << "Result" << endl;
    for (int numb: result) {
        cout << numb << ",";
    }

    //quicksort<int>(result.begin(),result.end());
    /*parallel_quick_sort(result);
    cout << "Result after sort" << endl;
    for (int numb: result) {
        cout << numb << ",";
    }*/
    return result;
}

void SplitUtils::splitToList(string s, list<int> result) {
    string delimiter = ",";
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;

    while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        int tokenIntValue;
        try {
            // string -> integer
            tokenIntValue = std::stoi(token);

        } catch (exception e) {
            continue;  // dont add incorrect string(not numerable value) into vector
        }
        result.push_back(tokenIntValue);
    }
    try {
        int tokenIntValue;
        // string -> integer
        tokenIntValue = std::stoi(s.substr(pos_start));
        result.push_back(tokenIntValue);
    } catch (exception e) {
        // dont add incorrect string(not numerable value) into vector
    }

//    cout << endl<< " Split to list Result" << endl;
//    for (int numb: result) {
//        cout << numb << ",|";
//    }

    //quicksort<int>(result.begin(),result.end());
    //parallel_quick_sort(result);

    // return result;
};
