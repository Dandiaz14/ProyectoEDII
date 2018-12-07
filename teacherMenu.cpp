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

void TeacherMenu::teacherMenu(const std::string &myStr)
{
    int opc;
    ///system("pause");
    do{
        system("cls");
        cout << "Bienvenido Profesor: " << myStr << endl;
        cout << "1.- Consulta de Asignacion" << endl;
        cout << "2.- Carga Academica" << endl;
        cout << "3.- Salir" << endl << endl;
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
        }
    }while(opc!=3);
}

void TeacherMenu::coordinatorMenu(const std::string& myStr)
{
    int opc;
    ///system("pause");
    do{
        system("cls");
        cout << "Bienvenido Coordinador: " << myStr << endl;
        cout << "1.- Consulta de Asignaturas" << endl;
        cout << "2.- Consulta de Maestros" << endl;
        cout << "3.- Consulta de Asignaciones" << endl;
        cout << "4.- Salir" << endl << endl;
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
        }
    }while(opc!=4);
}

void TeacherMenu::asistentMenu(const std::string& myStr)
{
    int opc;
    ///system("pause");
    do{
        system("cls");
        cout << "Bienvenido Asistente: " << myStr << endl;
        cout << "1.- Consulta de Asignacion" << endl;
        cout << "2.- Carga Academica" << endl;
        cout << "3.- Salir" << endl << endl;
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
        }
    }while(opc!=3);
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
