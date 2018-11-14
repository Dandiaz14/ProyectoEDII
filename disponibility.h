#ifndef DISPONIBILITY_H_INCLUDED
#define DISPONIBILITY_H_INCLUDED

#include "stdio.h"
#include <string.h>
#include <iostream>
using namespace std;

class Disponibility{
private:

    char hashingCode[25];
    char date[25];
    char hour[25];


public:
    void setHashingCode(const std::string& );
    void setDate(const std::string& );
    void setHour(const std::string& );

    std::string getHashingCode();
    std::string getDate();
    std::string getHour();
};

#endif // DISPONIBILITY_H_INCLUDED
