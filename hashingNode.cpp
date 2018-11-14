#include "hashingNode.h"

HashingNode::HashingNode() : next(NULL) {    }

HashingNode::HashingNode(const Disponibility& d) : HashingNode() {
    data = d;
    }

Disponibility& HashingNode::getData() {
    return data;
    }

HashingNode* HashingNode::getNext() {
    return next;
    }

void HashingNode::setData(const Disponibility& d) {
    data = d;
    }

void HashingNode::setNext(HashingNode* n) {
    next = n;
    }
