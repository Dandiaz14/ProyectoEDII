#include "nodeSubject.h"

NodeSubject::NodeSubject() : prev(nullptr), next(nullptr) { }

/* Se arregla problema de delegacion por doble inicializacion
ya que cada constructor inicializa todos los datos por defecto,
ahora se especifica cuales se inicializan despues de data(e)*/

NodeSubject::NodeSubject(const Subject& e) : data(e), prev(nullptr), next(nullptr) { }


Subject NodeSubject::getData() {
    return data;
}


NodeSubject* NodeSubject::getPrev() {
    return prev;
}


NodeSubject* NodeSubject::getNext() {
    return next;
}


void NodeSubject::setData(const Subject& e) {
    data = e;
}

void NodeSubject::setPrev(NodeSubject* p) {
    prev = p;
}


void NodeSubject::setNext(NodeSubject* p) {
    next = p;
}
