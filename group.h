#ifndef GROUP_H_INCLUDED
#define GROUP_H_INCLUDED

#include <string.h>
#include <iostream>
using namespace std;

class Group{
    private:
        char code[15];
        char name[30];
        char grade[15];
        char status[10];

    public:
        std::string getCode();
        std::string getName();
        std::string getGrade();
        std::string getStatus();

        void setCode(const std::string&);
        void setName(const std::string&);
        void setGrade(const std::string&);
        void setStatus(const std::string&);


};

#endif // GROUP_H_INCLUDED
