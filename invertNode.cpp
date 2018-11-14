#include "invertNode.h"

InvertNode::InvertNode() : next(nullptr), nextSame(nullptr) {
    }

InvertNode::InvertNode(const InvertData& e) : InvertNode() {
    data = e;
    }

InvertData& InvertNode::getData() {
    return data;
    }

InvertNode* InvertNode::getNextSame() {
    return nextSame;
    }

InvertNode* InvertNode::getNext() {
    return next;
    }

void InvertNode::setData(const InvertData& e) {
    data = e;
    }

void InvertNode::setNextSame(InvertNode* p) {
    nextSame = p;
    }

void InvertNode::setNext(InvertNode* p) {
    next = p;
    }
