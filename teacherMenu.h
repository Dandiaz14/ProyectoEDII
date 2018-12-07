#ifndef TEACHERMENU_H_INCLUDED
#define TEACHERMENU_H_INCLUDED

#include <string>
using namespace std;

class TeacherMenu{
private:

public:
    void teacherMenu(const std::string&);
    void coordinatorMenu(const std::string&);
    void asistentMenu(const std::string&);
    void modifyData();
    void deleteData();

    bool verifyEmail(const std::string&);
};

#endif // TEACHERMENU_H_INCLUDED
