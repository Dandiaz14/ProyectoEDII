#ifndef INVERTLIST_H_INCLUDED
#define INVERTLIST_H_INCLUDED

#include <iostream>
#include <fstream>

#include "invertNode.h"
///#include "listexception.h"
#include "invertData.h"

#include "subject.h"

#include "listIndex.h"
#include "nodeIndex.h"
#include "index.h"

using namespace std;

class InvertList {
    private:
        InvertNode* anchor;

        ListIndex myIndexList;

        void copyAll(const InvertList&);
        bool isValidPos(InvertNode*);
    public:
        InvertList();
        InvertList(const InvertList&);
        InvertList& operator = (const InvertList&);
        ~InvertList();

        bool isEmpty();

        void inserData(InvertNode*, const InvertData&);
        void deleteData(InvertNode*);

        InvertNode* findDataLenear(const int&);
        InvertNode* reatrieveData(const string&);

        bool searhDataLinear(const int);


        InvertNode* getFirstPos();
        InvertNode* getLastPos();
        InvertNode* getPrevPos(InvertNode*);
        InvertNode* getPrevSame(InvertNode*);
        InvertNode* getNextPost(InvertNode*);
        bool isValidPrev(InvertNode*);
        bool existCareer(const int&);

        void toString();

        void writeToDisck();

        void showNext(const int&);
        void deleteAll();
    };


#endif // INVERTLIST_H_INCLUDED
