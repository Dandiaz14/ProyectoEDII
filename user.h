#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include <string.h>
#include <iostream>
using namespace std;

class User {
    private:
        char userCode[15];
        char name[20];
        char password[30];
        char idProfile[10];

    public:
        std::string getUserCode();
        std::string getName();
        std::string getPassword();
        std::string getIdProfile();

        void setUserCode(const std::string&);
        void setName(const std::string&);
        void setPassword(const std::string&);
        void setIdProfile(const std::string&);
};


#endif // USER_H_INCLUDED
