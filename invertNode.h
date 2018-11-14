#ifndef INVERTNODE_H_INCLUDED
#define INVERTNODE_H_INCLUDED

#include <iostream>

#include "invertData.h"

using namespace std;

class InvertNode {
    private:
        InvertData data;

        InvertNode* next;
        InvertNode* nextSame;
    public:
        InvertNode();
        InvertNode(const InvertData&);

        InvertData& getData();
        InvertNode* getNextSame();
        InvertNode* getNext();

        void setData(const InvertData&);
        void setNextSame(InvertNode*);
        void setNext(InvertNode*);
    };


#endif // INVERTNODE_H_INCLUDED
