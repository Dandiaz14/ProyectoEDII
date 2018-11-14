#ifndef TEACHERMENU_H_INCLUDED
#define TEACHERMENU_H_INCLUDED

#include <string>
using namespace std;

class TeacherMenu{
private:

public:
    void teacherMenu();
    ///void insertData();
    void showData();
    void findData();
    void modifyData();
    void deleteData();

    bool verifyEmail(const std::string&);
};

#endif // TEACHERMENU_H_INCLUDED
