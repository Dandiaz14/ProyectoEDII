#include "nodeIndex.h"

NodeIndex::NodeIndex() : prev(nullptr), next(nullptr) { }

/* Se arregla problema de delegacion por doble inicializacion
ya que cada constructor inicializa todos los datos por defecto,
ahora se especifica cuales se inicializan despues de data(e)*/

NodeIndex::NodeIndex(const Index& e) : data(e), prev(nullptr), next(nullptr) { }


Index NodeIndex::getData() {
    return data;
}


NodeIndex* NodeIndex::getPrev() {
    return prev;
}


NodeIndex* NodeIndex::getNext() {
    return next;
}


void NodeIndex::setData(const Index& e) {
    data = e;
}

void NodeIndex::setPrev(NodeIndex* p) {
    prev = p;
}


void NodeIndex::setNext(NodeIndex* p) {
    next = p;
}
