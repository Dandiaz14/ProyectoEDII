#ifndef SUBJECT_H_INCLUDED
#define SUBJECT_H_INCLUDED

#include <string.h>
#include <iostream>
using namespace std;

class Subject {
    private:
        char code[15];
        char credit[5];
        char name[40];
        char program[40];
        char group[10];
        char status[10];

    public:
        std::string getCode();
        std::string getCredit();
        std::string getName();
        std::string getProgram();
        std::string getGroup();
        std::string getStatus();

        void setCode(const std::string&);
        void setCredit(const std::string&);
        void setName(const std::string&);
        void setProgram(const std::string&);
        void setGroup(const std::string&);
        void setStatus(const std::string&);
};


#endif // SUBJECT_H_INCLUDED
