#include "hashingTable.h"

using namespace std;

int HashingTable::getColumns()
{
    return columns;
}

void HashingTable::setColumns(const int& _columns)
{
    columns = _columns;
}

int HashingTable::getRows()
{
    return rows;
}

void HashingTable::setRows(const int& _rows)
{
    rows = _rows;
}


void HashingTable::drawFile() {
    ifstream leer("Disponibilidad.txt");
    if(!leer.good()) {
        ofstream escribir("Disponibilidad.txt", ios::app);
        for(int x(0); x < getColumns(); x++) {
            escribir.write((char*)&counter, sizeof(int));
            for(int y(0); y < getRows(); y++) {
                escribir.write((char*)&myDisponibility, sizeof(myDisponibility));
                }
            }
        }
    leer.close();
}

void HashingTable::insertDisponibility(Disponibility s) {
    Disponibility myNewDisponibility = s;
    string auxString = string(myNewDisponibility.getHashingCode());

    fstream archivo("Disponibilidad.txt", ios::in|ios::out);
    int pos = getBase(auxString) * ((sizeof(myDisponibility)*getRows()) + sizeof(int));
    archivo.seekg(pos,ios::beg);
    archivo.read((char*)&counter, sizeof(int));

    if(counter == getRows()) {
        cout << "Memoria Llena, libere espacio" << endl;
        }
    else {
        int celda = pos + (counter*sizeof(myDisponibility)) + sizeof(int);
        archivo.seekp(celda, ios::beg);
        archivo.write((char*)&myNewDisponibility, sizeof(myNewDisponibility));
        counter++;
        archivo.seekp(pos, ios::beg);
        archivo.write((char*)&counter, sizeof(int));
        }
    archivo.close();

}

int HashingTable::getBase(const string& key) {
    char auxKey[6];
    strcpy(auxKey, key.c_str());

    unsigned int j = 0, base = 0;

    while(j < strlen(auxKey)) {
        base = base + (100*auxKey[j]) + (auxKey[j + 1]%84645);
        j = j + 2;
        }
    return base = base % 100;
}

void HashingTable::showDisponibility() {
    int pos = 0;
    int aux = 0;
    ifstream leer("Disponibilidad.txt");
    if(!leer.good()){
        cout << "Imposible abrir el archivo." << endl;
        }
    else{
        while(!leer.eof()){
            leer.seekg(pos, ios::beg);
            leer.read((char*)&counter, sizeof(int));

            if(counter == 0){
                pos = pos + (sizeof(myDisponibility) * getRows()) + sizeof(int);
                }
            else{
                for(int i(0); i < counter; i++){
                    leer.read((char*)&myDisponibility, sizeof(myDisponibility));

                    cout << "Hashing Code: " << myDisponibility.getHashingCode() << endl;
                    cout << "Fecha: " << myDisponibility.getDate() << endl;
                    cout << "Hora: " << myDisponibility.getHour() << endl;
                    cout << "Direccion Base: " << aux << endl;
                    cout << endl;
                    }
                pos = pos + (sizeof(myDisponibility) * getRows()) + sizeof(int);
                }
            aux++;
            }
        }
    leer.close();
}
void HashingTable::showTeacher(const string& idMateria)
{
    std::string myName, myCode, myEmail, myPhone,newId;

    ifstream maestro;
    maestro.open("Maestros.txt",ios::in);

    if(!maestro.good()){
        cout << "Error";
    }
    else{
        while(!maestro.eof()){

           getline(maestro,myCode,'|');
           getline(maestro,myName,'|');
           getline(maestro,myEmail,'|');
           getline(maestro,myPhone,'|');

            newId = myCode + idMateria;

           if(maestro.eof()) break;

           int pos = 0;
            int aux = 0;
            int flag = 0;
            ifstream leer("Disponibilidad.txt");
            if(!leer.good()){
                cout << "Imposible abrir el archivo." << endl;
                }
            else{
                while(!leer.eof()){
                    leer.seekg(pos, ios::beg);
                    leer.read((char*)&counter, sizeof(int));

                    if(counter == 0){
                        pos = pos + (sizeof(myDisponibility) * getRows()) + sizeof(int);
                        }
                    else{
                        for(int i(0); i < counter; i++){
                            leer.read((char*)&myDisponibility, sizeof(myDisponibility));

                            if(newId==myDisponibility.getHashingCode()){
                                flag=1;
                            }
                            /*cout << "Hashing Code: " << myDisponibility.getHashingCode() << endl;
                            cout << "Fecha: " << myDisponibility.getDate() << endl;
                            cout << "Hora: " << myDisponibility.getHour() << endl;
                            cout << "Direccion Base: " << aux << endl;
                            cout << endl;*/
                            }
                        pos = pos + (sizeof(myDisponibility) * getRows()) + sizeof(int);
                        }
                    aux++;
                    }
                }
            leer.close();

        if(flag == 1){
           cout << "Codigo Del Maestro: " << myCode;
           cout << "\tNombre Del Profesor: " << myName << endl;
        }
           /*cout << "Email Del Maestro: " << myEmail << endl;
           cout << "Telefono Del Maestro: " << myPhone << endl;

           cout << endl;*/
        }
    }
    maestro.close();
}

void HashingTable::deleteDisponibility(const string& n){
    int pos = 0;
    int auxPos = 0;
    int auxColu = 0;
    int newCounter = 0;
    Disponibility myNewDisponibility[3];

    ifstream leer("Disponibilidad.txt");
    if(!leer.good()){
        cout << "Imposible abrir el archivo." << endl;
        }
    else{
        while(!leer.eof()){
            leer.seekg(pos, ios::beg);
            leer.read((char*)&counter, sizeof(int));

            if(counter == 0){
                pos = pos + (sizeof(myDisponibility) * getRows()) + sizeof(int);
                }
            else{
                for(int i(0); i < counter; i++){
                    leer.read((char*)&myDisponibility, sizeof(myDisponibility));
                    string aux = string(myDisponibility.getHashingCode());
                    if(aux == n){
                        auxPos = pos;
                        auxColu = i;
                        break;
                        }
                    }
                pos = pos + (sizeof(myDisponibility) * getRows()) + sizeof(int);
                }
            }
        }
    leer.close();

    ifstream leerOne("Disponibilidad.txt", ios::app);
    if(!leerOne.good()){
        cout << "Imposible abrir el archivo." << endl;
        }
    else{
        leerOne.seekg(auxPos, ios::beg);
        leerOne.read((char*)&counter, sizeof(int));
        for(int j(0); j < counter; j++){
            leerOne.read((char*)&myDisponibility, sizeof(myDisponibility));
            myNewDisponibility[j] = myDisponibility;
            }
        }
    leerOne.close();

    fstream archivo("Disponibilidad.txt", ios::in|ios::out);
    if(auxColu == getRows()-1){
        int newCounter = counter - 1;
        archivo.seekp(auxPos, ios::beg);
        archivo.write((char*)&newCounter, sizeof(int));
    }
    else{
        for(int k(0); k < counter; k++){
            if(myNewDisponibility[k].getHashingCode() != "\0" && k != auxColu){
                int celda = auxPos + (newCounter*sizeof(myDisponibility)) + sizeof(int);
                archivo.seekp(celda, ios::beg);
                archivo.write((char*)&myNewDisponibility[k], sizeof(myDisponibility));
                newCounter++;
                }
            }
        int newCounter = counter - 1;
        archivo.seekp(auxPos, ios::beg);
        archivo.write((char*)&newCounter, sizeof(int));
        }
    archivo.close();
}

void HashingTable::modifyDisponibility(const string& a, const Disponibility& b){
    deleteDisponibility(a);
    insertDisponibility(b);
}

bool HashingTable::existHashingCode(const string& a){
    int pos = 0;
    ifstream leer("Disponibilidad.txt");
    if(!leer.good()){
        cout << "Imposible abrir el archivo." << endl;
        }
    else{
        while(!leer.eof()){
            leer.seekg(pos, ios::beg);
            leer.read((char*)&counter, sizeof(int));

            if(counter == 0){
                pos = pos + (sizeof(myDisponibility) * getRows()) + sizeof(int);
            }

            else{
                for(int i(0); i < counter; i++){
                    leer.read((char*)&myDisponibility, sizeof(myDisponibility));

                    string auxString = myDisponibility.getHashingCode();

                    if(a == auxString){
                        return true;
                    }

                }
                pos = pos + (sizeof(myDisponibility) * getRows()) + sizeof(int);
                }
            }
        }
    leer.close();
    return false;
}

void HashingTable::increaseColumns()
{
    int pos = 0;
    int aux = 0;
    ifstream leer("Disponibilidad.txt");
    if(!leer.good()){
        cout << "Imposible abrir el archivo." << endl;
        }
    else{
        while(!leer.eof()){
            leer.seekg(pos, ios::beg);
            leer.read((char*)&counter, sizeof(int));

            if(counter == 0){
                pos = pos + (sizeof(myDisponibility) * getRows()) + sizeof(int);
                }
            else{
                for(int i(0); i < counter; i++){
                    leer.read((char*)&myDisponibility, sizeof(myDisponibility));

                    myList.insertData(myList.getLastPos(),myDisponibility);
                    }
                pos = pos + (sizeof(myDisponibility) * getRows()) + sizeof(int);
                }
            aux++;
            }
        }
    leer.close();

    remove("Alumnos.txt");
}

void HashingTable::retrieveDisponibility() {
    for (int i(0); i < myList.getCountRegister(); i++) {
        insertDisponibility(myList[i]);
        }
    }

bool HashingTable::verifyDisponibility(const std::string& teacher, const std::string& idMateria)
{
    std::string myName, myCode, myEmail, myPhone,newId;
    newId = teacher + idMateria;

    int pos = 0;
    int aux = 0;
    int flag = 0;
    ifstream leer("Disponibilidad.txt");
    if(!leer.good()){
        cout << "Imposible abrir el archivo." << endl;
        }
    else{
        while(!leer.eof()){
            leer.seekg(pos, ios::beg);
            leer.read((char*)&counter, sizeof(int));

            if(counter == 0){
                pos = pos + (sizeof(myDisponibility) * getRows()) + sizeof(int);
                }
            else{
                for(int i(0); i < counter; i++){
                    leer.read((char*)&myDisponibility, sizeof(myDisponibility));

                    if(newId==myDisponibility.getHashingCode()){
                        flag=1;
                    }

                }
                pos = pos + (sizeof(myDisponibility) * getRows()) + sizeof(int);
            }
            aux++;
        }
    }
    leer.close();
    if(flag == 1){
           return true;
    }
    return false;
}
