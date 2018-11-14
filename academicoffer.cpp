#include "academicoffer.h"

string AcademicOffer::getPeriod()
{
    return period;
}

string AcademicOffer::getCareer()
{
    return career;
}

string AcademicOffer::getGroups()
{
    return groups;
}

/*string AcademicOffer::getSubject()
{
    return subject;
}

string AcademicOffer::getTeacher()
{
    return teacher;
}*/

void AcademicOffer::setPeriod(const std::string& _period)
{
    strcpy(period,_period.c_str());
}

void AcademicOffer::setCareer(const std::string& _career)
{
    strcpy(career,_career.c_str());
}

void AcademicOffer::setGroups(const std::string& _groups)
{
    strcpy(groups,_groups.c_str());
}

/*void AcademicOffer::setSubject(const std::string& _subject)
{
    strcpy(subject,_subject.c_str());
}

void AcademicOffer::setTeacher(const std::string& _teacher)
{
    strcpy(teacher,_teacher.c_str());
}
*/
