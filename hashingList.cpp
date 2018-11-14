#include "hashingList.h"

HashingList::HashingList() : anchor(NULL){
    contRegister = 0;
}

HashingList::~HashingList() {
    deleteAll();
    }

bool HashingList::isEmpty() {
    return anchor == NULL;
    }

void HashingList::insertData(HashingNode* p , const Disponibility& s) {
    HashingNode* newNombre = new HashingNode(s);

    if(newNombre == NULL) {
        ///throw HashingListException("\tMemoria no disponible para insertar nuevo elemento.");
        }

    if(p == NULL) {
        newNombre->setNext(anchor);
        anchor = newNombre;
        }

    else {
        newNombre->setNext(p->getNext());
        p->setNext(newNombre);
        }

    contRegister++;
    }

HashingNode* HashingList::getFirstPos() {
    return anchor;
    }

HashingNode* HashingList::getLastPos() {
    if(isEmpty()) {
        return NULL;
        }

    HashingNode* aux(anchor);
    while(aux->getNext() != NULL) {
        aux = aux->getNext();
        }

    return aux;
}

void HashingList::deleteAll() {
    HashingNode* aux;
    while(anchor != NULL) {
        aux = anchor;
        anchor = anchor->getNext();
        delete aux;
        }
    }

HashingNode* HashingList::returnData(const std::string& d) {
    HashingNode* aux(anchor);
    while(anchor != NULL) {
        if(aux->getData().getHashingCode() == d) {
            return aux;
            }
        aux = aux->getNext();
        }
        return NULL;
    }

void HashingList::deleteData(std::string& d) {
    HashingNode* eliminar = returnData(d);
    if(eliminar != NULL) {
        if(isEmpty()) {
            ///throw HashingListException("\tNo hay elementos a eliminar.");
            }

        if(eliminar == anchor) {
            anchor = anchor->getNext();
            delete eliminar;
            contRegister--;
            }
        else {
            HashingNode* temp = anchor;
            while(temp->getNext() != NULL) {
                if(temp->getNext() == eliminar){
                    break;
                }
                temp = temp->getNext();
                //if(temp->getNext() == NULL) {
                    //throw HashingListException("\tPosici\242n no v\240lida.");
                    //}
                }
            HashingNode* aux = temp->getNext();
            temp->setNext(aux->getNext());
            delete aux;
            contRegister--;
            }
        }
        else{
            ///throw HashingListException("\tNo existe ese registro.");
        }
}

Disponibility HashingList::retrieve(HashingNode* p) {
    if(isEmpty()) {
        ///throw HashingListException("\tRegistros vac\241os.");
        }

    return p->getData();
    }

bool HashingList::findData(std::string& s) {
    HashingNode* aux(anchor);
    while(aux != NULL) {
        if(aux->getData().getHashingCode() == s) {
            return true;
            }
        aux = aux->getNext();
        }
    return false;
    }

int HashingList::getCountRegister() {
    return contRegister;
    }

Disponibility& HashingList::operator[](const int& i) {
    HashingNode* aux = anchor;
    int j = 0;
    while(j != i){
        aux = aux->getNext();
        j++;
     }
     return aux->getData();
    }
