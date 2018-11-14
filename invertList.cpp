#include "invertList.h"

using namespace std;

bool InvertList::isValidPos(InvertNode* p) {
    InvertNode* aux = anchor;

    while(aux != nullptr) {
        if(aux == p) {
            return true;
            }
        aux = aux->getNext();
        }
    return true;
    }

InvertList::InvertList() : anchor(nullptr) {

    }

InvertList::InvertList(const InvertList& l)
{
    copyAll(l);
}

InvertList& InvertList::operator=(const InvertList& l)
{
    deleteAll();
    copyAll(l);

    return *this;
}

InvertList::~InvertList() {
    writeToDisck();
    deleteAll();
    }

bool InvertList::isEmpty() {
    return anchor == nullptr;
    }

void InvertList::inserData(InvertNode* p, const InvertData& e) {
    if(!isValidPos(p) and p != nullptr) {
        ///throw ListException("Posicion invalida, tratando de insertar Datos.");
        cout << "Posicion invalida, insertando.";
    }

    InvertNode* aux = new InvertNode(e);

    if(aux == nullptr) {
        ///throw ListException("Memomoria insuficiente para insertar a la lista.");
        cout << "Memoria insuficiente, insertando.";
    }

    if(p == nullptr) { //Insertando al principio
        aux->setNext(anchor);
        anchor = aux;
    }
    else { //Insertando en cualquier posicion
        /*aux->setNext(p->getNext());
        p->setNext(aux);*/

        if(searhDataLinear(aux->getData().getLabel())) {
            aux->setNext(p->getNext());
            p->setNext(aux);

            InvertNode* aux1 = findDataLenear(aux->getData().getLabel());

            if(aux1->getNextSame() == nullptr) {
                aux1->setNextSame(aux);
                }
            else {
                while(aux1->getNextSame() != nullptr) {
                    aux1 = aux1->getNextSame();
                    }
                aux1->setNextSame(aux);
                }

            }
        else {
            aux->setNext(p->getNext());
            p->setNext(aux);
        }
    }

}

void InvertList::deleteData(InvertNode* p)
{
    if(!isValidPos(p)) {
        cout << "Posicion invalida, eliminando." ;
    }
    if(p == anchor) { //Eliminando el primero
        anchor = anchor->getNext();
    } else { //Eliminar cualquier otro elemento
        getPrevPos(p)->setNext(p->getNext());
        if(isValidPrev(p) == true){
            getPrevSame(p)->setNextSame(p->getNextSame());
        }
    }
    delete p;
}

InvertNode* InvertList::findDataLenear(const int& e) {
    InvertNode* aux(anchor);

    while(aux != nullptr) {
        if(e == aux->getData().getLabel()) {
            return aux;
            }
        aux = aux->getNext();
        }
    return nullptr;
    }

InvertNode* InvertList::reatrieveData(const string& e)
{
    InvertNode* aux(anchor);

    while(aux != nullptr) {
        if(e == aux->getData().getCode()) {
            return aux;
            }
        aux = aux->getNext();
        }
    return nullptr;
}

bool InvertList::searhDataLinear(const int e) {
    InvertNode* aux = anchor;

    while(aux != nullptr) {
        if(e == aux->getData().getLabel()) {
            return true;
            }
        aux = aux->getNext();
        }
    return false;
    }

InvertNode* InvertList::getFirstPos() {
    return anchor;
    }

InvertNode* InvertList::getLastPos() {
    if(isEmpty()) {
        return nullptr;
        }

    InvertNode* aux(anchor);

    while(aux->getNext() != nullptr) {
        aux = aux->getNext();
        }
    return aux;
    }

InvertNode* InvertList::getPrevPos(InvertNode* p) {
     InvertNode* aux(anchor);

    while(aux != nullptr && aux->getNext() != p) {
        aux = aux->getNext();
    }
    return aux;
}

InvertNode* InvertList::getPrevSame(InvertNode* p)
{
    InvertNode* aux(anchor);

    while(aux != nullptr && aux->getNextSame() != p) {
        aux = aux->getNext();
    }
    return aux;
}

bool InvertList::isValidPrev(InvertNode* p)
{
      InvertNode* aux(anchor);

    while(aux != nullptr && aux->getNextSame() != nullptr) {
        if(aux->getNextSame() == p){
            return true;
        }
        aux = aux->getNext();
    }
    return false;
}

bool InvertList::existCareer(const int& e)
{
    InvertNode* aux(anchor);

    while(aux != nullptr) {
        if(e == aux->getData().getLabel()) {
            return true;
            }
        aux = aux->getNext();
        }
    return false;
}

InvertNode* InvertList::getNextPost(InvertNode* p) {
    if(!isValidPos(p)) {
        return nullptr;
        }
    return p->getNext();
    }

void InvertList::toString() {
    int i = 0;
    InvertNode* aux = anchor;

    while(aux != nullptr && isValidPos(aux)) {

        ///cout << "-----" << i+1 << "-----" << endl;
        cout << "Posicion del Nodo: " << aux << endl;
        cout << "Codigo: " << aux->getData().getCode() << endl;
        ///cout << "Label: " << aux->getData().getLabel() << endl;
        cout << "Siguiente De La Misma Carrera: " << aux->getNextSame() << endl;
        cout << "Siguiente En La Lista: " << aux->getNext() << endl;
        cout << endl << endl;

        aux = aux->getNext();
        i++;
        }
    }

void InvertList::writeToDisck() {
    InvertNode* aux = anchor;

    while(aux != nullptr) {

        ofstream writeIndex("ListaInvertida.txt", ios::app);
        InvertData myAuxData = aux->getData();

        writeIndex.write((char*)&myAuxData,sizeof(InvertData));
        writeIndex.close();

        aux = aux->getNext();
        }
    }

void InvertList::showNext(const int& p) {
    InvertNode* aux = findDataLenear(p);

    while(aux != nullptr) {
        ///int auxInt = aux->getData().getSqu();
        aux = aux->getNextSame();
        }
    }

void InvertList::copyAll(const InvertList& l)
{
    InvertNode* aux(l.anchor);
    InvertNode* lastInserted(nullptr);
    InvertNode* newNode;

    while(aux != nullptr){
        //insertData(getLastPos(), aux->getData());   *Inflacion de software*

        newNode = new InvertNode(aux->getData());
        if(newNode == nullptr){
            ///throw ListException("Memoria no disponible, copyAll");
        }
        if(lastInserted == nullptr){
            anchor = newNode;
        }
        else{
            lastInserted->setNext(newNode);
        }

        lastInserted = newNode;

        aux = aux->getNext();
    }
}

void InvertList::deleteAll()
{
    InvertNode* aux;

    while(anchor != nullptr) {
        aux = anchor;
        anchor = anchor->getNext();
        delete aux;
    }
}
