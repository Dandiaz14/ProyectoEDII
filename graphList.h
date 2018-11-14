#ifndef GRAPHLIST_H_INCLUDED
#define GRAPHLIST_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

#define ARRAYSIZE 50

class GraphList
{
private:
    std::string data[ARRAYSIZE];
    int last;

public:
    GraphList();


    bool isEmpty();
    bool isFull();

    void insertData(const int&, const std::string&);
    void deleteData(const int& );

    int getFirstPos();
    int getLastPos();
    int getPrevPos(const int&);
    int getNextPos(const int&);

    bool findData(const std::string&);

    ///void toString();
    /*T retrieveData(const int&);

    void deletAll();*/
};



#endif // GRAPHLIST_H_INCLUDED
