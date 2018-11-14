#include "careerNode.h"

CareerNode::CareerNode() : next(nullptr), start(nullptr) {
    }

CareerNode::CareerNode(const Career& e) : CareerNode() {
    data = e;
    }

Career& CareerNode::getData() {
    return data;
    }

CareerNode* CareerNode::getNext() {
    return next;
    }

InvertNode* CareerNode::getStart() {
    return start;
    }

void CareerNode::setData(const Career& e) {
    data = e;
    }

void CareerNode::setNext(CareerNode* p) {
    next = p;
    }

void CareerNode::setStart(InvertNode* p) {
    start = p;
    }
