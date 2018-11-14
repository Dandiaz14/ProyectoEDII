#ifndef PERIOD_H_INCLUDED
#define PERIOD_H_INCLUDED

#include <string.h>
#include <iostream>
using namespace std;

class Period{
    private:
        char code[15];
        char name[30];
        char dateBegin[11];
        char dateFinish[11];
        char status[10];

    public:
        std::string getCode();
        std::string getName();
        std::string getDateBegin();
        std::string getDateFinish();
        std::string getStatus();

        void setCode(const std::string&);
        void setName(const std::string&);
        void setDateBegin(const std::string&);
        void setDateFinish(const std::string&);
        void setStatus(const std::string&);


};

#endif // PERIOD_H_INCLUDED
