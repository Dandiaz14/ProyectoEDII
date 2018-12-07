#include "huffmanNode.h"

HuffmanNode::HuffmanNode(){
    next = NULL;
    prev = NULL;
    right = NULL;
    left = NULL;
    label = "";
    sum = 0;
}

HuffmanNode::HuffmanNode(std::string& d){
    next = NULL;
    prev = NULL;
    right = NULL;
    left = NULL;
    label = d;
    sum = 0;
    }

void HuffmanNode::setLabel(const std::string& d) {
    label = d;
    }

void HuffmanNode::setSum(const int& s) {
    sum = s;
    }

void HuffmanNode::setNext(HuffmanNode* p){
    next = p;
    }

void HuffmanNode::setPrev(HuffmanNode* p){
    prev = p;
    }

void HuffmanNode::setRight(HuffmanNode* p){
    right = p;
}

void HuffmanNode::setLeft(HuffmanNode* p){
    left = p;
}

std::string HuffmanNode::getLabel() {
    return label;
    }

int HuffmanNode::getSum() {
    return sum;
    }

HuffmanNode* HuffmanNode::getNext(){
    return next;
}

HuffmanNode* HuffmanNode::getPrev(){
    return prev;
}

HuffmanNode* HuffmanNode::getRight(){
    return right;
}

HuffmanNode* HuffmanNode::getLeft(){
    return left;
}
