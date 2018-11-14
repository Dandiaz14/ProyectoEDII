#ifndef HASHINGNODE_H_INCLUDED
#define HASHINGNODE_H_INCLUDED
#include <iostream>

#include "disponibility.h"

class HashingNode {
    private:
        Disponibility data;
        HashingNode* next;

    public:
        HashingNode();
        HashingNode(const Disponibility&);

        Disponibility& getData();
        HashingNode* getNext();

        void setData(const Disponibility&);
        void setNext(HashingNode*);
    };


#endif // HASHINGNODE_H_INCLUDED
