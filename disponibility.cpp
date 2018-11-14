#include "disponibility.h"

void Disponibility::setHashingCode(const std::string& hc)
{
    strcpy(hashingCode,hc.c_str());
}

void Disponibility::setDate(const std::string& d)
{
    strcpy(date,d.c_str());
}

void Disponibility::setHour(const std::string& h)
{
    strcpy(hour,h.c_str());
}

string Disponibility::getHashingCode()
{
    return hashingCode;
}

string Disponibility::getDate()
{
    return date;
}

string Disponibility::getHour()
{
    return hour;
}
