#include "listCareer.h"

bool CareerList::isValidPos(CareerNode* p) {
    CareerNode* aux = anchor;

    while(aux != nullptr) {
        if(aux == p) {
            return true;
            }
        aux = aux->getNext();
        }
    return false;
    }

CareerList::CareerList() : anchor(nullptr) {
    }

CareerList::~CareerList() {
    writeToDisck();
    }

bool CareerList::isEmpty() {
    return anchor == nullptr;
    }

void CareerList::InsertData(CareerNode* p, const Career& e) {
    if(!isValidPos(p) and p != nullptr) {
        ///throw ListException("Posicion Invalida, Tratando de Insertar Datos.");
        }

    CareerNode* aux = new CareerNode(e);

    if(aux == nullptr) {
        ///throw ListException("Memoria insuficiente para insertar a la lista.");
        }

    if(p == nullptr) {///Inicio
        aux->setNext(anchor);
        anchor = aux;
        }
    else {
        aux->setNext(p->getNext());
        p->setNext(aux);
    }
    last++;
}

void CareerList::deleteData(CareerNode* p)
{
    if(!isValidPos(p)) {
        cout << "Posicion invalida, eliminando." ;
    }
    if(p == anchor) { //Eliminando el primero
        anchor = anchor->getNext();
    } else { //Eliminar cualquier otro elemento
        getPrevPos(p)->setNext(p->getNext());
    }
    delete p;
}

CareerNode* CareerList::findDataLinear(const string& e) {
    CareerNode* aux = anchor;

    while(aux != nullptr) {
        if(e == aux->getData().getName()) {
            return aux;
            }
        aux = aux->getNext();
        }
    return nullptr;
    }

bool CareerList::searchDataLinear(const string& e) {
    CareerNode* aux = anchor;

    while(aux != nullptr) {
        if(e == aux->getData().getName()) {
            return true;
            }
        aux = aux->getNext();
        }
    return false;
    }

int CareerList::reatriveLabel(const string& e) {
    CareerNode* aux = anchor;

    while(aux != nullptr) {
        if(e == aux->getData().getName()) {
            return aux->getData().getLabel();
            }
        aux = aux->getNext();
        }
    return 0;
}

CareerNode* CareerList::getFirstPos() {
    return anchor;
    }

CareerNode* CareerList::getLastPost() {
    if(isEmpty()) {
        return nullptr;
        }

    CareerNode* aux = anchor;
    while(aux->getNext() != nullptr) {
        aux = aux->getNext();
        }
    return aux;
    }

CareerNode* CareerList::getPrevPos(CareerNode* p) {
    if(!isValidPos(p)) {
        ///throw ListException("Posicion invalida al tratar de optener anterior.");
        }

    CareerNode* aux = anchor;

    while(aux != nullptr and aux->getNext() != p) {
        aux = aux->getNext();
        }

    return aux;
    }

CareerNode* CareerList::getNextPos(CareerNode* p) {
    if(!isValidPos(p)) {
        return nullptr;
        }
    return p->getNext();
    }

int CareerList::getLast() {
    return last;
    }

void CareerList::toString() {
    int i = 0;
    CareerNode* aux = anchor;

    while(aux != nullptr && isValidPos(aux)) {

        ///cout << "-----" << i+1 << "-----" << endl;
        cout << "Carrera: " << aux->getData().getName() << endl;
        cout << "Posicion: " << aux->getData().getLabel() << endl;
        cout << endl << endl << endl;

        aux = aux->getNext();
        i++;
        }
    }

string CareerList::showCareer(const string& myStr)
{
    int i = 0;
    CareerNode* aux = anchor;

    while(aux != nullptr && isValidPos(aux)) {

        if(stoi(myStr) == aux->getData().getLabel()){
            return aux->getData().getName();
        }
        aux = aux->getNext();
        i++;
    }
    return 0;
}

void CareerList::writeToDisck() {
    CareerNode* aux = anchor;

    while(aux != nullptr) {

        ofstream writeIndex("Carreras.txt", ios::app);
        Career myAuxCareer = aux->getData();

        writeIndex.write((char*)&myAuxCareer,sizeof(Career));
        writeIndex.close();

        aux = aux->getNext();
        }
}

