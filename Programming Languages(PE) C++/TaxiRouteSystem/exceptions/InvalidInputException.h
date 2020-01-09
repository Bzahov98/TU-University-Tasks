//
// Created by bzahov on 29.12.19 г..
//
#ifndef TAXIROUTESYSTEM_INVALIDINPUTEXCEPTION_H
#define TAXIROUTESYSTEM_INVALIDINPUTEXCEPTION_H

using namespace std;

class InvalidInputException {
public:
    string generalInfo = "InvalidInputException in: ";
    string info;

    InvalidInputException(const string &info) : info(info) {}

    string getMessage() const;
    const char *what() const noexcept;

};


#endif //TAXIROUTESYSTEM_INVALIDINPUTEXCEPTION_H
