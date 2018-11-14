#ifndef PROFILE_H_INCLUDED
#define PROFILE_H_INCLUDED

#include <string.h>
#include <iostream>
using namespace std;

class Profile {
    private:
        char name[20];
        char code[15];

    public:
        std::string getName();
        std::string getCode();

        void setName(const std::string&);
        void setCode(const std::string&);
};


#endif // PROFILE_H_INCLUDED
