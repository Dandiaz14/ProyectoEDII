#ifndef CAREERNODE_H_INCLUDED
#define CAREERNODE_H_INCLUDED

#include <iostream>

#include "career.h"
#include "invertNode.h"

class CareerNode {
    private:
        Career data;

        CareerNode* next;
        InvertNode* start;

    public:
        CareerNode();
        CareerNode(const Career&);

        Career& getData();
        CareerNode* getNext();
        InvertNode* getStart();

        void setData(const Career&);
        void setNext(CareerNode*);
        void setStart(InvertNode*);

    };


#endif // CAREERNODE_H_INCLUDED
