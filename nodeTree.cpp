#include "nodeTree.h"

NodeTree::NodeTree() : right(NULL), left(NULL){
    label = "";
    sum = 0;
}

void NodeTree::setLabel(const std::string& s) {
    label = s;
    }

void NodeTree::setSum(const int& s) {
    sum = s;
    }

void NodeTree::setRight(NodeTree* p) {
    right = p;
    }

void NodeTree::setLeft(NodeTree* p) {
    left = p;
    }

std::string NodeTree::getLabel(){
    return label;
}

int NodeTree::getSum(){
    return sum;
}

NodeTree* NodeTree::getRight() {
    return right;
    }

NodeTree* NodeTree::getLeft() {
    return left;
    }
