#include "professor.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <limits>
#include <vector>
#include <conio.h>

string Professor::getName()
{
    return name;
}

string Professor::getCode()
{
    return code;
}

string Professor::getEmail()
{
    return email;
}

string Professor::getPhone()
{
    return phone;
}

void Professor::setName(const std::string& _name)
{
    strcpy(name,_name.c_str());
}

void Professor::setCode(const std::string& _code)
{
    strcpy(code,_code.c_str());
}

void Professor::setEmail(const std::string& _email)
{
    strcpy(email,_email.c_str());
}

void Professor::setPhone(const std::string& _phone)
{
    strcpy(phone,_phone.c_str());
}

void Professor::menuProfessor()
{
    int opc;
    do{
        system("cls");
        cout << "Bienvenido Profesor" << endl;
        cout << "1.- Consulta Asignacion" << endl;
        cout << "2.- Consulta Carga Academica" << endl;
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

    }while(opc!=3);
}
