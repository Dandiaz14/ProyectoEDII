#ifndef LISTSUBJECT_H_INCLUDED
#define LISTSUBJECT_H_INCLUDED

#include <iostream>
#include <cstdio>
#include <fstream>
#include "nodeSubject.h"

using namespace std;

//EXCEPTIONS
class ListException : public exception {
  private:
    string msg;

  public:
    explicit ListException(const char* message) : msg(message) {}
    explicit ListException(const string& message): msg(message) {}
    virtual ~ListException() throw() {}
    virtual const char* what() const throw() {
        return msg.c_str();
    }
};


class ListSubject {
  private:
    NodeSubject* anchor;

    bool isPosValid(NodeSubject*);
    void quickSort(NodeSubject*, NodeSubject*);

  public:
    ListSubject();
    ///List& operator = (const List&);
    ~ListSubject();

    bool isEmpty();

    void insertData(NodeSubject*, const NodeSubject&);

    void selectSort();
    void doExchange(NodeSubject*, NodeSubject*);
    void quickSort();

    NodeSubject* getFirstPos();
    NodeSubject* getLastPos();
    NodeSubject* getPrevPos(NodeSubject*);
    NodeSubject* getNextPos(NodeSubject*);

    void toString();
    void FromListToDisk();
    ///string toString();
    void deleteAll();
};


#endif // LISTSUBJECT_H_INCLUDED
