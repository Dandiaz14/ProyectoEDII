#ifndef HASHINGTABLE_H_INCLUDED
#define HASHINGTABLE_H_INCLUDED

#include <iostream>
#include <fstream>
#include <stdexcept>

#include "disponibility.h"
#include "hashingList.h"

class HashingTable{
public:
    void drawFile();
    void insertDisponibility(Disponibility);
    int getBase(const string&);
    void showDisponibility();
    void showTeacher(const string&);///muestra los maestros que pueden dar la materia
    void deleteDisponibility(const string&);
    void modifyDisponibility(const string&, const Disponibility&);
    void increaseColumns();
    bool existHashingCode(const string&);
    void retrieveDisponibility();
    bool verifyDisponibility(const std::string&,const std::string&);

    int getColumns();
    void setColumns(const int&);

    int getRows();
    void setRows(const int&);
private:
    Disponibility myDisponibility;
    HashingList myList;
    int counter = 0;
    int columns=100;
    int rows=4;
};

#endif // HASHINGTABLE_H_INCLUDED
