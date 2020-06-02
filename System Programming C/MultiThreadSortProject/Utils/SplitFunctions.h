//
// Created by bzahov on 31.05.20 г..
//

#ifndef MULTYTHREADSORTPROJECT_SPLITFUNCTIONS_H
#define MULTYTHREADSORTPROJECT_SPLITFUNCTIONS_H

#include <iostream>
#include <vector>
#include <list>
;using namespace std;

class SplitUtils {
public:
    static void splitToTokens(const string &inputString, int *data);

    static vector<int> splitToVector(string s, string delimiter);

    static void splitToList(string s, list<int> result);
};

#endif //MULTYTHREADSORTPROJECT_SPLITFUNCTIONS_H
