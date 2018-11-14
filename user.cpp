#include "user.h"

string User::getUserCode()
{
    return userCode;
}

string User::getName()
{
    return name;
}

string User::getPassword()
{
    return password;
}

string User::getIdProfile()
{
    return idProfile;
}

void User::setUserCode(const std::string& _userCode)
{
    strcpy(userCode,_userCode.c_str());
}

void User::setName(const std::string& _name)
{
    strcpy(name,_name.c_str());
}

void User::setPassword(const std::string& _password)
{
    strcpy(password,_password.c_str());
}

void User::setIdProfile(const std::string& _idProfile)
{
    strcpy(idProfile,_idProfile.c_str());
}
