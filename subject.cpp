#include "subject.h"

string Subject::getCode()
{
    return code;
}

string Subject::getCredit()
{
    return credit;
}

string Subject::getName()
{
    return name;
}

string Subject::getProgram()
{
    return program;
}

string Subject::getGroup()
{
    return group;
}

void Subject::setCode(const std::string& _code)
{
    strcpy(code,_code.c_str());
}

void Subject::setCredit(const std::string& _credit)
{
    strcpy(credit,_credit.c_str());
}

void Subject::setName(const std::string& _name)
{
    strcpy(name,_name.c_str());
}

void Subject::setProgram(const std::string& _program)
{
    strcpy(program,_program.c_str());
}

void Subject::setGroup(const std::string& _group)
{
    strcpy(group,_group.c_str());
}

string Subject::getStatus()
{
    return status;
}

void Subject::setStatus(const std::string& _status)
{
    strcpy(status,_status.c_str());
}
