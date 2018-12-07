#include "HuffmanList.h"
using namespace std;

HuffmanList::HuffmanList() : anchor(NULL) { }

HuffmanList::~HuffmanList() {
    deleteAll();
}

bool HuffmanList::isEmpty(){
    return anchor == NULL;
}

bool HuffmanList::isValidPos(HuffmanNode*p) {
    HuffmanNode* aux(anchor);
    while(aux!=NULL){
        if(aux == p){
            return true;
        }
        aux = aux->getNext();
    }
    return false;
}

void HuffmanList::insertData(HuffmanNode* p, std::string&e){
    if(p != NULL and !isValidPos(p)){
        ///throw HuffmanListException("Posicion invalida, tratando de insertar");
    }
    HuffmanNode* aux(new HuffmanNode(e));
    if(aux == NULL){
        ///throw HuffmanListException("Memoria no disponible, tratando de insertar");
    }

    if(p == NULL){///insertando al principio
        aux ->setNext(anchor);
        if(anchor !=NULL){
                anchor ->setPrev(aux);
            }
        anchor = aux;
    }
    else{   ///Insertando en cualquier posicion
        aux ->setPrev(p);
        aux ->setNext(p->getNext());
        if(p->getNext() != NULL){
            p ->getNext()->setPrev(aux);
        }
        p ->setNext(aux);
    }

}

void HuffmanList::insertRoot(HuffmanNode* p, HuffmanNode* l, HuffmanNode* r, std::string&e, int& s){
    if(p != NULL and !isValidPos(p)){
        ///throw HuffmanListException("Posicion invalida, tratando de insertar");
    }
    HuffmanNode* aux(new HuffmanNode(e));
    HuffmanNode* actual;
    if(aux == NULL){
        ///throw HuffmanListException("Memoria no disponible, tratando de insertar");
    }

    if(p == NULL){///insertando al principio
        aux ->setNext(anchor);
        if(anchor !=NULL){
                anchor ->setPrev(aux);
            }
        anchor = aux;
    }
    else{   ///Insertando en cualquier posicion
        aux ->setPrev(p);
        aux ->setNext(p->getNext());
        if(p->getNext() != NULL){
            p ->getNext()->setPrev(aux);
        }
        p ->setNext(aux);
    }

    aux->setSum(s);
    aux->setLeft(l);
    aux->setRight(r);

    if(anchor == l){
        actual = l->getNext()->getNext();

        anchor = actual;
        actual->setPrev(anchor);

        r->setNext(NULL);
        l->setNext(NULL);

        r->setPrev(NULL);
        l->setPrev(NULL);
    }

}

void HuffmanList::deleteData(HuffmanNode*p){
    if(!isValidPos(p)){
        ///throw HuffmanListException("Posicion invalida, tratando de eliminar");
    }
    if(p->getPrev() != NULL){
        p->getPrev()->setNext(p->getNext());
    }
    else{
        anchor = anchor->getNext();
    }
    delete p;
}

HuffmanNode* HuffmanList::getFirstPos() {
    return anchor;
}

HuffmanNode* HuffmanList::getLastPos() {
    if(isEmpty()){
        return NULL;
    }
    HuffmanNode* aux(anchor);
    while(aux ->getNext() != NULL){
        aux = aux ->getNext();
    }
    return aux;
}

HuffmanNode* HuffmanList::getNextPos(HuffmanNode*p) {
    if(!isValidPos(p)){
        return NULL;
    }
    return p ->getNext();
}

HuffmanNode* HuffmanList::getPrevPos(HuffmanNode*p) {
    if(!isValidPos(p)){
        return NULL;
    }
    return p->getPrev();
}

bool HuffmanList::findData(const string &s) {
    HuffmanNode* aux(anchor);

    while(aux != NULL){
        if(aux->getLabel() == s){
            return true;
        }
        aux = aux->getNext();
    }

    return false;
}

void HuffmanList::preOrder(HuffmanNode* p){
    if( p == NULL ){
        return;
    }
    string cadena;
    if(p->getLeft() == NULL or p->getRight() == NULL){
        cadena = "Hoja: ";
    }
    else{
        cadena = "Raiz: ";
    }

    cout << "\t\t" << cadena << p->getLabel() << ":" << p->getSum() << endl;
    if(p->getLeft() != NULL){
        cout << "\t\tHoja Izquierda: " << p->getLeft()->getLabel() << ":" << p->getLeft()->getSum() << endl;
    }
    if(p->getRight() != NULL){
        cout << "\t\tHoja Derecha: " << p->getRight()->getLabel() << ":" << p->getRight()->getSum() << endl;
    }

    cout << endl;

    preOrder(p->getLeft());
    preOrder(p->getRight());
}


std::string HuffmanList::retrieveData(HuffmanNode*p) {
    if(!isValidPos(p)){
        ///throw HuffmanListException("Posicion Invalida, tratando de recuperar");
    }
    return p ->getLabel();
}

HuffmanNode* HuffmanList::returnHuffmanNode(string& x){
    HuffmanNode* aux(anchor);

    while(aux != NULL){
        if(aux->getLabel() == x){
            return aux;
        }
        aux = aux->getNext();
    }

    return NULL;
}

void HuffmanList::deleteAll() {
    HuffmanNode* aux;
    while(anchor != NULL){
        aux = anchor;
        anchor = anchor ->getNext();
        delete aux;
    }
}

void HuffmanList::toString(){
    HuffmanNode* aux(anchor);

     while(aux != nullptr) {
        cout << aux->getLabel() << ":" << aux->getSum() << endl;

        aux = aux->getNext();
    }
}

void HuffmanList::doExchange(HuffmanNode* x, HuffmanNode* y){
    string cad;
    int sum;
    HuffmanNode* izq;
    HuffmanNode* der;

    cad = x->getLabel();
    sum = x->getSum();
    izq = x->getLeft();
    der = x->getRight();

    x->setLabel(y->getLabel());
    x->setSum(y->getSum());
    x->setLeft(y->getLeft());
    x->setRight(y->getRight());

    y->setLabel(cad);
    y->setSum(sum);
    y->setLeft(izq);
    y->setRight(der);
}

void HuffmanList::orderedListAscendent(){
	HuffmanNode* i(getFirstPos());
	HuffmanNode* j;
	HuffmanNode* m;

	while(i != NULL){
		m = i;
		j = i->getNext();
		while(j != NULL){
			if(j->getSum() < m->getSum()){
				m = j;
			}
			else if(j->getSum() == m->getSum()){
                if(j->getLabel() < m->getLabel()){
                    m = j;
                }
			}
			j = j->getNext();
		}
		if( i != m ){
			doExchange(i,m);
		}
		i = i->getNext();
	}
}


HuffmanList& HuffmanList::operator = (const HuffmanList&l) {
    deleteAll();

    return *this;
    }
