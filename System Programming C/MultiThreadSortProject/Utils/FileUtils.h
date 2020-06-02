//
// Created by bzahov on 31.05.20 г..
//

#ifndef MULTYTHREADSORTPROJECT_FILEUTILS_H
#define MULTYTHREADSORTPROJECT_FILEUTILS_H

#include <fstream>
#include <list>
#include <iostream>

#include "SplitFunctions.h"

using namespace std;


class FileUtils {
public:
    constexpr static const char *const INPUT_FILE_NAME = "/home/bzahov/Documents/gitRepos/TU-University-Tasks/System Programming C/MultiThreadSortProject/input.txt";

    static int readInputDataFromFile(const char *filename, int *data);
};

#endif //MULTYTHREADSORTPROJECT_FILEUTILS_H
