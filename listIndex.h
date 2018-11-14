#ifndef LISTINDEX_H_INCLUDED
#define LISTINDEX_H_INCLUDED

#include <iostream>
#include <cstdio>
#include <fstream>
#include "nodeIndex.h"

using namespace std;

//EXCEPTIONS
/*class ListException : public exception {
  private:
    string msg;

  public:
    explicit ListException(const char* message) : msg(message) {}
    explicit ListException(const string& message): msg(message) {}
    virtual ~ListException() throw() {}
    virtual const char* what() const throw() {
        return msg.c_str();
    }
};*/


class ListIndex {
  private:
    NodeIndex* anchor;

    bool isPosValid(NodeIndex*);
    void quickSort(NodeIndex*, NodeIndex*);

  public:
    ListIndex();
    ///List& operator = (const List&);
    ~ListIndex();

    bool isEmpty();
    bool isValidPos(NodeIndex*); ///Posición válida

    void insertData(NodeIndex*, const NodeIndex&);
    void deleteData(NodeIndex*);
    NodeIndex* findData(const std::string&);

    void selectSort();
    void doExchange(NodeIndex*, NodeIndex*);
    void quickSort();

    NodeIndex* getFirstPos();
    NodeIndex* getLastPos();
    NodeIndex* getPrevPos(NodeIndex*);
    NodeIndex* getNextPos(NodeIndex*);

    ///NodeIndex retrieveData(NodeIndex*);

    void toString();
    void fromListToDisk();
    ///string toString();
    void deleteAll();
};


#endif // LISTINDEX_H_INCLUDED
