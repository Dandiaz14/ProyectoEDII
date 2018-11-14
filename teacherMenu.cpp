#include "teacherMenu.h"

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <limits>
#include <vector>
#include <conio.h>
#include <algorithm>
#include <string>
#include "professor.h"

Professor myTeacher;

void TeacherMenu::teacherMenu()
{
    int opc;
    ///system("pause");
    do{
        system("cls");
        cout << "Profesores" << endl;
        cout << "1.- Agregar Estudiante" << endl;
        cout << "2.- Mostrar Estudiante" << endl;
        cout << "3.- Buscar Estudiante" << endl;
        cout << "4.- Modificar Estudiante" << endl;
        cout << "5.- Eliminar Estudiante" << endl;
        cout << "6.- Salir" << endl << endl;
        cout << "Ingresa la opcion deseada: ";
        cin >> opc;
        if(!std::cin)
                {
                  std::cin.clear();
                  std::cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
                  cout << "Opcion Invalida, intente de nuevo" << endl;
                  system("pause");
                }
        switch(opc){
        case 1:
            system("cls");
            ///insertData();
            system("pause");
        break;
        case 2:
            system("cls");
            ///showData();
            system("pause");
        break;
        case 3:
            system("cls");
            findData();
            system("pause");
        break;
        case 4:
            system("cls");
            modifyData();
            system("pause");
        break;
        case 5:
            system("cls");
            deleteData();
            system("pause");
        break;
        /*default:
            cout << "Intente de nuevo" << endl;
            system("pause");
        break;*/
        }
    }while(opc!=6);
}


/*void TeacherMenu::insertData()
{

    std::string myName, myCode, myEmail, myPhone;

    cin.ignore();
    cout << "Crear Nuevo Registro" << endl;

    cout << "Ingrese Nombre: ";
    getline(cin,myName);
    myTeacher.setName(myName);

    cout << "Ingrese Codigo: ";
    getline(cin,myCode);
    myTeacher.setCode(myCode);

    cout << "Ingrese E-mail: ";
    getline(cin,myEmail);
    while(verifyEmail(myEmail) == false){
        cout << "Ingreso un Correo Invalido, Intentelo de Nuevo. . ." << endl;
        cout << "Ingrese E-mail: ";
        getline(cin,myEmail);
    }
    myTeacher.setEmail(myEmail);

    cout << "Ingrese Telefono: ";
    getline(cin,myPhone);
    myTeacher.setPhone(myPhone);

    ofstream myFile("Maestros.txt",ios::app);
    myFile << myName << '|' << myCode << '|' << myEmail << '|' << myPhone << '|';
    myFile.close();
}*/

void TeacherMenu::showData()
{
     std::string myName, myCode, myEmail, myPhone;

    ifstream myFile;
    myFile.open("Maestros.txt",ios::in);

    if(!myFile.good()){
        cout << "Error";
    }
    else{
        while(!myFile.eof()){

           getline(myFile,myName,'|');
           getline(myFile,myCode,'|');
           getline(myFile,myEmail,'|');
           getline(myFile,myPhone,'|');

           if(myFile.eof()) break;
           cout << endl;

           cout << "Nombre Del Profesor: " << myName << endl;
           cout << "Codigo Del Maestro: " << myCode << endl;
           cout << "Email Del Maestro: " << myEmail << endl;
           cout << "Telefono Del Maestro: " << myPhone << endl;

           cout << endl;
        }
    }
    myFile.close();
}

void TeacherMenu::findData()
{
    bool encontrado = false;
    string myStr, myName, myCode, myEmail, myPhone;

    ifstream myFile("Maestros.txt");

    cout << "Ingrese el codigo del maestro a buscar: ";
    cin >> myStr;

    while(!myFile.eof()){
        getline(myFile,myName,'|');
        getline(myFile,myCode,'|');
        getline(myFile,myEmail,'|');
        getline(myFile,myPhone,'|');


        if(myFile.eof()) break;

        if(myStr == myCode){
            encontrado = true;
            cout << endl;

           cout << "Nombre Del Profesor: " << myName << endl;
           cout << "Codigo Del Maestro: " << myCode << endl;
           cout << "Email Del Maestro: " << myEmail << endl;
           cout << "Telefono Del Maestro: " << myPhone << endl;

            cin.ignore();
        }
    }
    if(encontrado == false){
        cout << "Maestro no encontrado. . ." << endl;
    }

    myFile.close();
}

void TeacherMenu::modifyData()
{

    bool encontrado = false;
    string myStr, myName, myCode, myEmail, myPhone;


    ofstream temp("Temporal.txt",ios::app);
    ifstream myFile("Maestros.txt");

    cout << "Ingrese el codigo del maestro a Modificar: ";
    cin >> myStr;

    while(!myFile.eof()){
        getline(myFile,myName,'|');
        getline(myFile,myCode,'|');
        getline(myFile,myEmail,'|');
        getline(myFile,myPhone,'|');

        if(myFile.eof()) break;

        if(myStr == myCode){
            encontrado = true;
            cin.ignore();

            cout << "Ingrese Nombre: ";
            getline(cin,myName);
            myTeacher.setName(myName);

            cout << "Ingrese Codigo: ";
            getline(cin,myCode);
            myTeacher.setCode(myCode);

            cout << "Ingrese E-mail: ";
            getline(cin,myEmail);
            while(verifyEmail(myEmail) == false){
                cout << "Ingreso un Correo Invalido, Intentelo de Nuevo. . ." << endl;
                cout << "Ingrese E-mail: ";
                getline(cin,myEmail);
            }
            myTeacher.setEmail(myEmail);

            cout << "Ingrese Telefono: ";
            getline(cin,myPhone);
            myTeacher.setPhone(myPhone);

            temp << myName << '|' << myCode << '|' << myEmail << '|' << myPhone << '|';
        }
        else{
             temp << myName << '|' << myCode << '|' << myEmail << '|' << myPhone << '|';
        }
    }
    if(encontrado==false){
        cout << "Maestro no encontrado. . ." << endl;
    }
    else{
        cout << "Maestro Modificado!. . ." << endl;
    }

    myFile.close();
    temp.close();
    remove("Maestros.txt");
    rename("Temporal.txt","Maestros.txt");
}

void TeacherMenu::deleteData()
{
    bool encontrado = false;
     string myStr, myName, myCode, myEmail, myPhone;

    ofstream temp("Temporal.txt",ios::app);
    ifstream myFile("Maestros.txt");

    cout << "Ingrese el codigo del maestro a eliminar: ";
    cin >> myStr;

    while(!myFile.eof()){
        getline(myFile,myName,'|');
        getline(myFile,myCode,'|');
        getline(myFile,myEmail,'|');
        getline(myFile,myPhone,'|');

        if(myFile.eof()) break;

        if(!(myCode == myStr)){
            temp << myName << '|' << myCode << '|' << myEmail << '|' << myPhone << '|';
        }
        else{
            encontrado=true;
            cout << "Nombre Del Profesor: " << myName << endl;
            cout << "Codigo Del Maestro: " << myCode << endl;
            cout << "Email Del Maestro: " << myEmail << endl;
            cout << "Telefono Del Maestro: " << myPhone << endl;
            cout << "Eliminado!.." << endl;
        }
    }
    if(encontrado==false){
        cout<<"MAestro No Encontrado"<<endl;
    }

    myFile.close();
    temp.close();
    remove("Maestros.txt");
    rename("Temporal.txt","Maestros.txt");
}

bool TeacherMenu::verifyEmail(const std::string& email)
{
    auto beg=email.begin(), _end=email.end();

    if((beg=find(beg, _end, '@')) != _end && find(beg, _end, '.') != _end){
        return true;
    }
    return false;
}
