#include "superuser.h"
#include <thread>
#include <chrono>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <limits>
#include <vector>
#include <conio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <sstream>
#include <windows.h>
#include <ctime>
typedef basic_istream<char> istream;

void SuperUser::adminMenu()
{
    int opc;
    fromDiskToList();
    myHashing.drawFile();
    do{
        system("cls");
        ///selfSaved();
        cout << "Bienvenido Administrador" << endl;
        cout << "1.- Agregar" << endl;
        cout << "2.- Mostrar" << endl;
        cout << "3.- Buscar" << endl;
        cout << "4.- Modificar" << endl;
        cout << "5.- Eliminar" << endl;
        cout << "6.- Eliminacion Logica" << endl;
        cout << "7.- Activacion Logica" << endl;
        cout << "8.- Guardar Grafo" << endl;
        cout << "9.- Cargar Grafo" << endl;
        cout << "10.- Cargar Lista Invertida" << endl;
        cout << "11.- Incrementar Tabla Hash" << endl;
        cout << "12.- Salir" << endl << endl;
        cout << "Ingresa la opcion deseada: ";
        cin >> opc;
        selfSaved();
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
            insertData();
        break;
        case 2:
            system("cls");
            showData();
        break;
        case 3:
            system("cls");
            findData();
        break;
        case 4:
            system("cls");
            modifyData();
        break;
        case 5:
            system("cls");
            deleteData();
        break;
        case 6:
            system("cls");
            logicDelete();
        break;
        case 7:
            system("cls");
            logicActivation();
        break;
        case 8:
            system("cls");
            myGraph.writeToDiskV();
            myGraph.writeToDiskA();
        break;
        case 9:
            system("cls");
            myGraph.readFromDiskV();
            myGraph.readFromDiskA();
        break;
        case 10:
            system("cls");
            fromDiskToInvertList();
        break;
        case 11:
            system("cls");
            increaseTable();
        break;
        }
    }while(opc!=12);
}

void SuperUser::insertData()
{
    int opc;

    do{
        system("cls");
        cout << "Que Desea Agregar?" << endl;
        cout << "1) Perfil\n2) Usuario\n3) Grupo\n4) Periodo \n5) Asignatura \n6) Edificios \n7) Disponibilidad" << endl;
        cout << "8) Catalogo\n9) Oferta Academica\n10 Regresar" << endl;
        cout << "opcion: ";
        cin >> opc;
        switch(opc){
            case 1:
                system("cls");
                cout << "Agrega Perfil Nuevo" << endl;
                insertProfile();
                cout << "Perfil Ingresado Exitosamente. . ." << endl;
            break;
            case 2:
                system("cls");
                cout << "Agrega Usuario Nuevo" << endl;
                insertUser();
                cout << "Usuario Ingresado Exitosamente. . ." << endl;
            break;
            case 3:
                system("cls");
                cout << "Agrega Grupo Nuevo" << endl;
                insertGroup();
                cout << "Grupo Ingresado Exitosamente. . ." << endl;
            break;
            case 4:
                system("cls");
                cout << "Agrega Periodo Nuevo" << endl;
                insertPeriod();
                cout << "Periodo Ingresado Exitosamente. . ." << endl;
            break;
            case 5:
                system("cls");
                cout << "Agrega Asignatura Nueva" << endl;
                insertSubject();
                cout << "Asignatura Ingresada Exitosamente. . ." << endl;
            break;
            case 6:
                system("cls");
                graphInsert();
            break;
            case 7:
                system("cls");
                insertHashing();
                system("pause");
            break;
            case 8:
                system("cls");
                insertCatalog();
                system("pause");
            break;
            case 9:
                system("cls");
                insertOffer();
                cout << "Nueva Oferta Academica Creada Exitosamente. . ." << endl;
                system("pause");
            break;
        }
    }while(opc != 10);
}

void SuperUser::graphInsert()
{
    int opc;

    do{
        system("cls");
        cout << "Edificios" << endl;
        cout << "1) Edificios\n2) Conexiones\n3) Regresar" << endl;
        cout << "opcion: ";
        cin >> opc;
        switch(opc){
            case 1:
                system("cls");
                cout << "Agrega Edificio Nuevo" << endl;
                insertVertex();
                cout << "Edificio Ingresado Exitosamente. . ." << endl;
            break;
            case 2:
                system("cls");
                cout << "Agrega Conexion Nueva" << endl;
                insertEdge();
                cout << "Conexion Ingresada Exitosamente. . ." << endl;
            break;
        }
    }while(opc != 3);
}

void SuperUser::insertUser()
{
    string myStr;
    bool flag;
    int n, c, p,i,myInt;

    cin.get();
    ///system("cls");

    cout << "Ingrese El Nombre Del Usuario: ";
    getline(cin,myStr);
    myUser.setName(myStr);

    myInt = increaseUserId() + 1;
    cout << "Codigo Del Usuario: " << myInt << endl;
    writeToId(myInt);
    auto s = std::to_string(myInt);
    myUser.setUserCode(s);

    cout << "Ingrese El Password Del Usuario: ";
    getline(cin,myStr);
    myUser.setPassword(myStr);

    cout << "Ingrese El ID Del Perfil Para Ligarlo: ";
    getline(cin,myStr);
    flag = existUser(myStr);
    while(flag == false){
        cout << "Ingreso un Perfil Inexistente o Invalido, Intentelo de Nuevo. . ." << endl;
        cout << "Ingrese El ID Del Perfil Para Ligarlo: ";
        getline(cin,myStr);
        flag = existUser(myStr);
    }
    myUser.setIdProfile(myStr);

    ofstream myFile("Usuarios.txt",ios::app);
    n = strlen(myUser.getName().c_str());
    c = strlen(myUser.getUserCode().c_str());
    p = strlen(myUser.getPassword().c_str());
    i = strlen(myUser.getIdProfile().c_str());

    myFile.write((char*)&n,sizeof(int));
    myFile.write((char*)myUser.getName().c_str(),n);

    myFile.write((char*)&c,sizeof(int));
    myFile.write((char*)myUser.getUserCode().c_str(),c);

    myFile.write((char*)&p,sizeof(int));
    myFile.write((char*)myUser.getPassword().c_str(),p);

    myFile.write((char*)&i,sizeof(int));
    myFile.write((char*)myUser.getIdProfile().c_str(),i);

    myFile.close();

    if(stoi(myStr) == 4){
        insertProfessor();
    }
}

void SuperUser::insertProfile()
{
    string myStr;
    int n, c;

    cin.get();
    ///system("cls");

    cout << "Ingrese El Nombre Del Perfil: ";
    getline(cin,myStr);
    myProfile.setName(myStr);

    cout << "Ingrese El Codigo Del Perfil: ";
    getline(cin,myStr);
    myProfile.setCode(myStr);

    ofstream myFile("Perfiles.txt",ios::app);
    n = strlen(myProfile.getName().c_str());
    c = strlen(myProfile.getCode().c_str());

    myFile.write((char*)&n,sizeof(int));
    myFile.write((char*)myProfile.getName().c_str(),n);

    myFile.write((char*)&c,sizeof(int));
    myFile.write((char*)myProfile.getCode().c_str(),c);

    myFile.close();
}

void SuperUser::insertGroup()
{
    std::string myName;
    std::string myCode;
    int myInt;
    cin.ignore();

    ofstream myFile("Grupos.txt", std::ios::binary | std::ios::app);
    if(!myFile.good()){
        cout << "Error";
    }
    else{

    myInt = increaseGroupId() + 1;
    cout << "Codigo Del Grupo: " << myInt << endl;
    writeToGroupId(myInt);
    auto s = std::to_string(myInt);
    myGroup.setCode(s);

    cout << "Ingrese Nombre del Grupo" << endl;
    getline(cin,myName);
    myGroup.setName(myName);

    myGroup.setGrade("3");

    myGroup.setStatus("activo");

    myFile.write((char *)&myGroup,sizeof(myGroup));
    }
    myFile.close();
}

void SuperUser::insertPeriod()
{
    std::string myName;
    std::string myCode;
    std::string myDateBegin;
    std::string myDateFinish;
    int myInt;
    cin.ignore();

    ofstream myFile("Periodos.txt",ios::app);
    if(!myFile.good()){
        cout << "Error";
    }
    else{

    myInt = increasePeriodId() + 1;
    cout << "Codigo Del Periodo: " << myInt << endl;
    writeToPeriodId(myInt);
    auto s = std::to_string(myInt);
    myPeriod.setCode(s);

    cout << "Ingrese Nombre del Periodo: ";
    getline(cin,myName);
    myPeriod.setName(myName);

    cout << "Ingrese Fecha de Inicio del Periodo: ";
    getline(cin,myDateBegin);
    myPeriod.setDateBegin(myDateBegin);

    cout << "Ingrese Fecha de Fin del Periodo: ";
    getline(cin,myDateFinish);
    myPeriod.setDateFinish(myDateFinish);

    myPeriod.setStatus("activo");

    myFile.write((char *)&myPeriod,sizeof(myPeriod));
    }
    myFile.close();
}

void SuperUser::insertProfessor()
{
    std::string myName, myCode, myEmail, myPhone;
    int myInt;

    cout << "Crear Nuevo Profesor" << endl;

     myInt = increaseProfessorId() + 1;
    cout << "Codigo Del Profesor: " << myInt << endl;
    writeToProfessorId(myInt);
    auto s = std::to_string(myInt);
    myTeacher.setCode(s);
    myCode = s;

    cout << "Ingrese Nombre del Profesor: ";
    getline(cin,myName);
    myTeacher.setName(myName);

    cout << "Ingrese E-mail del Profesor: ";
    getline(cin,myEmail);
    while(verifyEmail(myEmail) == false){
        cout << "Ingreso un Correo Invalido, Intentelo de Nuevo. . ." << endl;
        cout << "Ingrese E-mail: ";
        getline(cin,myEmail);
    }
    myTeacher.setEmail(myEmail);

    cout << "Ingrese Telefono del Profesor: ";
    getline(cin,myPhone);
    myTeacher.setPhone(myPhone);

    ofstream myFile("Maestros.txt",ios::app);
    myFile << myCode << '|' << myName << '|' << myEmail << '|' << myPhone << '|';
    myFile.close();
}

void SuperUser::insertSubject()
{
    std::string myStr;
    int myInt;
    cin.get();

    myInt = increaseSubjectId() + 1;
    cout << "Codigo de la Asignatura: " << myInt << endl;
    writeToSubjectId(myInt);
    auto s = std::to_string(myInt);
    mySubject.setCode(s);
    ///myCareer.setCode(s);
    myCareer.setLabel(myCareerList.getLast());

    cout << "Ingrese Creditos de la Asignatura: ";
    getline(cin,myStr);
    mySubject.setCredit(myStr);

    cout << "Ingrese Nombre de la Asignatura: ";
    getline(cin,myStr);
    mySubject.setName(myStr);

    cout << "Ingrese Carrera de la Asignatura: ";
    getline(cin, myStr);
    mySubject.setProgram(myStr);
    myCareer.setName(myStr);

    cout << "Ingrese el Grado en el que la Asignatura deberia ser cursada: ";
    getline(cin, myStr);
    mySubject.setGroup(myStr);

    mySubject.setStatus("activo");

    fstream myFile("Asignaturas.txt", ios::in|ios::out);
    myFile.seekg(0, ios::end);
    if (myFile.tellg() == -1) myFile.seekg(0);
    long int pos = myFile.tellg();
    myFile.write((char*)&mySubject, sizeof(Subject));
    myFile.close();
    ///myListSubject.insertData(myListSubject.getLastPos(),mySubject);

    string key = mySubject.getCode();
    myIndex.setIdxReference(pos);
    myIndex.setIndexId(key);
    ofstream myIndexFile("Indices.txt", ios::app);
    myIndexFile.write((char*)&myIndex, sizeof(Index));
    myIndexFile.close();

    myListIndex.insertData(myListIndex.getLastPos(),myIndex);


    if(!myCareerList.findDataLinear(myCareer.getName())){
        myCareerList.InsertData(myCareerList.getLastPost(),myCareer);
    }
    myInvert.setCode(myIndex.getIndexId());
    myInvert.setLabel(myCareerList.reatriveLabel(myCareer.getName()));

    myInvertList.inserData(myInvertList.getLastPos(),myInvert);
}

void SuperUser::insertVertex()
{
    std::string myId,myName,myDivision;
    int myInt;
    cin.get();

    myInt = increaseBuildingId() + 1;
    cout << "Codigo Del Edificio: " << myInt << endl;
    writeToBuildingId(myInt);
    auto s = std::to_string(myInt);
    myBuilding.setId(s);
    myId=to_string(myInt);

    cout << "Ingrese El Nombre Del Edificio: ";
    getline(cin,myName);
    myBuilding.setName(myName);

    cout << "Ingrese su División: ";
    getline(cin,myDivision);
    myBuilding.setDivision(myDivision);

    myBuilding.setExists("activo");

    myGraph.insertVertex(myGraph.getLastPos(),myName);

    ofstream myFile("Edificios.txt",ios::app);
    myFile << myId << '|' << myName << '|' << myDivision << '|' << "activo" << '|';
    myFile.close();
}

void SuperUser::insertEdge()
{
    std::string origen, destino;
    int weight;
    cin.get();

    cout << "Ingrese Su Vector Origen: ";
    getline(cin,origen);

    cout << "Ingrese Su Vector Destino: ";
    getline(cin,destino);

    cout << "Ingrese Su Ponderacion: ";
    cin >> weight;

    myGraph.insertEdge(origen,destino,weight);

    myGraph.insertEdge(destino,origen,weight);
    system("pause");

}

void SuperUser::insertHashing()
{
    string teacherName, subjectName, idMaestro, idMateria, myStr;
    time_t curr_time;
	tm * curr_tm;
	char date_string[100];
	char time_string[100];
	time(&curr_time);
	curr_tm = localtime(&curr_time);
    strftime(date_string, 50, "%d-%m-%Y", curr_tm);
	strftime(time_string, 50, "%H:%M:%S", curr_tm);

	string date, time;
	date = date_string;
	time = time_string;
    cin.get();
    cout << "*****----------*********" << endl;
    cout << "      Materias" << endl;
    showSubject();
    cout << "*****----------*********" << endl;
    cout << "     Profesores" << endl;
    showProfessor();

        cout << "Ingresa el Codigo del Maestro: ";
        getline(cin, idMaestro);
        if(teacherValid(idMaestro)==false){
            cout << "Id de Maestro invalido, favor de revisarlo. . ." << endl;
            return;
        }

        cout << "Ingresa el Codigo de la Materia: ";
        getline(cin, idMateria);
        if(subjectValid(idMateria)==false){
            cout << "Id de la Materia invalida, favor de revisarla. . ." << endl;
            return;
        }

        myStr = idMaestro + idMateria;
        myDisponibility.setHashingCode(myStr);
        myDisponibility.setDate(date);
        myDisponibility.setHour(time);
        myHashing.insertDisponibility(myDisponibility);
}

void SuperUser::insertCatalog()
{
    std::string teacherCode;
    std::string subjectCode;
    std::string grade;
    ///int myInt;
    cin.ignore();

    ofstream myFile("Catalogo.txt",ios::app);
    if(!myFile.good()){
        cout << "Error";
    }
    else{

    cout << "Ingrese Id del Profesor: ";
    getline(cin,teacherCode);
    while(verifyTeacher(teacherCode)==false){
        cout << "Id Inexistente" << endl;
        cout << "Ingrese Id Valido del Profesor: ";
        getline(cin,teacherCode);
    }
    myCatalog.setTeacherCode(teacherCode);

    cout << "Ingrese Id de la Materia: ";
    getline(cin,subjectCode);
    while(verifySubject(subjectCode)==false){
        cout << "Id Inexistente" << endl;
        cout << "Ingrese Id Valido de la Materia: ";
        getline(cin,subjectCode);
    }
    myCatalog.setSubjectCode(subjectCode);

    cout << "Ingrese Id del Grado: ";
    getline(cin,grade);
    while(verifyGroup(grade)==false){
        cout << "Id Inexistente" << endl;
        cout << "Ingrese Id Valido del Grado: ";
        getline(cin,grade);
    }
    myCatalog.setGrade(grade);

    myFile.write((char *)&myCatalog,sizeof(myCatalog));
    }
    myFile.close();
}

void SuperUser::insertOffer()
{
    std::string periodName,careerName,groupNumber,subjectName,teacherName;
    int grado = 1,k=0,letter=65;
    ///char let;
    cin.ignore();
    ofstream myFile("Oferta.txt",ios::app);
    if(!myFile.good()){
        cout << "Error";
    }
    else{
        cout << "Ingrese Nombre del Periodo: ";
        getline(cin,periodName);
        myOffer.setPeriod(periodName);

        system("cls");
        cout << "Usted esta eligiendo la oferta academica para el periodo " << periodName << endl << endl << endl;
        cout << "Carreras A Elegir: " << endl;
        myCareerList.toString();
        cout << endl << endl;
        cout << "Que carrera desea escoger?: ";
        getline(cin,careerName);
        myOffer.setCareer(careerName);
        system("cls");
        cout << "Usted esta eligiendo la oferta academica para el periodo " << periodName << " y la carrera " << myCareerList.showCareer(careerName) << endl << endl << endl;
        cout << "Cuantos grupos desea insertar por cada grupo?: ";
        getline(cin,groupNumber);
        myOffer.setGroups(groupNumber);
        for(int i=0;i<grado;i++){
            for(int j=0;j<stoi(groupNumber);j++){
                system("cls");
                cout << "Usted esta eligiendo la oferta academica para el periodo " << periodName << " y la carrera " << myCareerList.showCareer(careerName) << endl;
                cout << "Eleccion de Materias para " << i+1 << "-" << char(letter+j) << endl << endl;
                cin.get();
                k=showSpecificSubject(myCareerList.showCareer(careerName),i+1);
                ///cout << "llega aqui" << endl;
                for(int l=0;l<k;l++){
                    /*system("cls");
                    cout << "Usted esta eligiendo la oferta academica para el periodo " << periodName << " y la carrera " << myCareerList.showCareer(careerName) << endl;
                    cout << "Eleccion de Materias para " << i+1 << "-" << char(letter+j) << endl << endl;*/
                    cout << "\nQue materia desea escoger?: ";
                    getline(cin,subjectName);///escribo en archivo de delimitador el nombre de la materia, el profesor y el grado y grupo
                    reatriveDisponibility(subjectName);
                    cout << "Que maestro desea escoger?: ";
                    getline(cin,teacherName);
                    while(myHashing.verifyDisponibility(teacherName,subjectName)==false){
                        cout << "Que maestro desea escoger?: ";
                        getline(cin,teacherName);
                    }
                    ofstream myFile("Auxiliar.txt",ios::app);
                    myFile << periodName << '|' << careerName << '|' << i+1 << '|' << char(letter+j) << '|' << subjectName << '|' << teacherName << '|';
                    myFile.close();

                }
            }

        }
        myFile.write((char *)&myOffer,sizeof(myOffer));
    }
}

void SuperUser::showData()
{
    int opc;
    do{
        system("cls");
        cout << "Que Desea Mostrar?" << endl;
        cout << "1) Perfil\n2) Usuario\n3) Grupo\n4) Periodo \n5) Profesores \n6) Asignatura" << endl;
        cout << "7) Asignaturas Descendentes\n8) Edificios\n9) Carreras\n10) Disponibilidad\n11) Catalogo\n12) Oferta Academica\n13) Regresar\n" << endl;
        cout << "opcion: ";
        cin >> opc;
        switch(opc){
            case 1:
                cout << "\n***Perfiles***" << endl;
                showProfile();
                system("pause");
            break;
            case 2:
                cout << "\n***Usuarios***" << endl;
                showUser();
                system("pause");
            break;
            case 3:
                cout << "\n***Grupos***" << endl;
                showGroup();
                system("pause");
            break;
            case 4:
                cout << "\n***Periodos***" << endl;
                showPeriod();
                system("pause");
            break;
            case 5:
                cout << "\n***Profesores***" << endl;
                showProfessor();
                system("pause");
            break;
            case 6:
                cout << "\n***Asignaturas***" << endl;
                showSubject();
                system("pause");
            break;
            case 7:
                cout << "\n***Asignaturas Descendentes***" << endl;
                showDescentSubject();
                system("pause");
            break;
            case 8:
                cout << "\n***Edificios***" << endl;
                graphShowMenu();
                system("pause");
            break;
            case 9:
                cout << "\n***Carreras***" << endl;
                showCareerMenu();
                system("pause");
            break;
            case 10:
                system("cls");
                cout << "\n***Disponibilidad***" << endl;
                showDisponibility();
                system("pause");
            break;
            case 11:
                system("cls");
                cout << "\n***Catalogo***" << endl;
                showCatalog();
                system("pause");
            break;
            case 12:
                system("cls");
                ///cout << "\n***Catalogo***" << endl;
                showOffer();
                system("pause");
            break;
        }
    }while(opc != 13);
}

void SuperUser::showProfile()
{
    cin.ignore();

    std::string myStr;
    char name[100], code[100];
    int n,c;

    ifstream myFile;
    myFile.open("Perfiles.txt",ios::in);

    if(!myFile.good()){
        cout << "Error";

    }
    else{

        while(!myFile.eof()){

            myFile.read((char*)&n,sizeof(int));
            myFile.read((char*)name,n);
            name[n]='\0';

            myFile.read((char*)&c,sizeof(int));
            myFile.read((char*)code,c);
            code[c]='\0';

            if(myFile.eof()){break; }
                cout << "Nombre: " << name << endl;
                cout << "Codigo: " << code << endl;
                cout << endl << endl;
        }
    }
    myFile.close();
}

void SuperUser::showUser()
{
    cin.ignore();

    std::string myStr;
    char name[100], code[100], password[100], id[100];
    int n,c,p,i;

    ifstream myFile;
    myFile.open("Usuarios.txt",ios::in);

    if(!myFile.good()){
        cout << "Error";
    }
    else{
        while(!myFile.eof()){
            myFile.read((char*)&n,sizeof(int));
            myFile.read((char*)name,n);
            name[n]='\0';

            myFile.read((char*)&c,sizeof(int));
            myFile.read((char*)code,c);
            code[c]='\0';

            myFile.read((char*)&p,sizeof(int));
            myFile.read((char*)password,p);
            password[p]='\0';

            myFile.read((char*)&i,sizeof(int));
            myFile.read((char*)id,i);
            id[i]='\0';

            if(myFile.eof()){break; }
                cout << "Nombre: " << name << endl;
                cout << "Codigo: " << code << endl;
                cout << "Password: " << password << endl;
                cout << "Id de Perfil: " << id << endl;
                cout << endl << endl;
        }
    }
    myFile.close();
}

void SuperUser::showGroup()
{
    ifstream myFile;
    myFile.open("Grupos.txt", std::ios::binary | std::ios::in);

    if(!myFile.good()){
        cout << "Error";
    }
    else{
        while(!myFile.eof()){
            myFile.read((char *)&myGroup,sizeof(myGroup));

            if(myFile.eof()){break;}

            if(myGroup.getStatus() == "activo"){
                cout << "Codigo: " << myGroup.getCode() << endl;
                cout << "Nombre: " << myGroup.getName() << endl;
                cout << "Grado: " << myGroup.getGrade() << endl << endl;

            }
        }
    }
    myFile.close();
}

void SuperUser::showPeriod()
{
    ifstream myFile;
    myFile.open("Periodos.txt",ios::in);

    if(!myFile.good()){
        cout << "Error";
    }
    else{
        while(!myFile.eof()){
            myFile.read((char *)&myPeriod,sizeof(myPeriod));

            if(myFile.eof()){break;}

            if(myPeriod.getStatus() == "activo"){
                cout << "Codigo: " << myPeriod.getCode() << endl;
                cout << "Nombre: " << myPeriod.getName() << endl;
                cout << "Fecha Inicio: " << myPeriod.getDateBegin() << endl;
                cout << "Fecha Fin: " << myPeriod.getDateFinish() << endl << endl;
            }
        }
    }
    myFile.close();
}

void SuperUser::showProfessor()
{
    std::string myName, myCode, myEmail, myPhone;

    ifstream myFile;
    myFile.open("Maestros.txt",ios::in);

    if(!myFile.good()){
        cout << "Error";
    }
    else{
        while(!myFile.eof()){

           getline(myFile,myCode,'|');
           getline(myFile,myName,'|');
           getline(myFile,myEmail,'|');
           getline(myFile,myPhone,'|');

           if(myFile.eof()) break;
           cout << endl;


           cout << "Codigo Del Maestro: " << myCode << endl;
           cout << "Nombre Del Profesor: " << myName << endl;
           cout << "Email Del Maestro: " << myEmail << endl;
           cout << "Telefono Del Maestro: " << myPhone << endl;

           cout << endl;
        }
    }
    myFile.close();
}

void SuperUser::showSubject()
{
    ifstream myFile;
    myFile.open("Asignaturas.txt");
    myFile.seekg(ios::beg);
    if(!myFile.good()){
        cout << "Error";
    }
    else{
        while(!myFile.eof()){
            myFile.read((char *)&mySubject,sizeof(mySubject));

            if(myFile.eof()){break;}

                if(mySubject.getStatus() == "activo"){
                    cout << "Codigo: " << mySubject.getCode() << endl;
                    cout << "Creditos: " << mySubject.getCredit() << endl;
                    cout << "Nombre: " << mySubject.getName() << endl;
                    cout << "Carrera: " << mySubject.getProgram() << endl << endl;
                }
        }
    }
    myFile.close();
}

void SuperUser::graphShowMenu()
{
    int opc;

    do{
            system("cls");
        cout << "Mostrar" << endl;
        cout << "1) Edificios\n2) Grafo\n3) Rutas\n4) Recorridos\n5) Regresar" << endl;
        cout << "opcion: ";
        cin >> opc;
        switch(opc){
            case 1:
                system("cls");
                cout << "Edificios" << endl;
                showBuilding();
                system("pause");
            break;
            case 2:
                system("cls");
                cout << "Grafo" << endl;
                myGraph.toString();
                system("pause");
            break;
            case 3:
                system("cls");
                cout << "Rutas" << endl;
                route();
                system("pause");
            break;
            case 4:
                system("cls");
                cout << "Recorridos" << endl;
                parse();
                system("pause");
            break;
        }
    }while(opc != 5);
}

void SuperUser::showBuilding()
{
    std::string myName, myId, myDivision, myStatus;

    ifstream myFile;
    myFile.open("Edificios.txt",ios::in);

    if(!myFile.good()){
        cout << "Error";
    }
    else{
        while(!myFile.eof()){

           getline(myFile,myId,'|');
           getline(myFile,myName,'|');
           getline(myFile,myDivision,'|');
           getline(myFile,myStatus,'|');

           if(myFile.eof()) break;

           if(myStatus == "activo"){
                cout << endl;

                cout << "ID Del Edificio: " << myId << endl;
                cout << "Nombre Del Edificio: " << myName << endl;
                cout << "Division Del Edificio: " << myDivision << endl;
                cout << "Estatus Del Edificio: " << myStatus << endl;

                cout << endl;
           }
        }
    }
    myFile.close();

}

void SuperUser::showDescentSubject()
{
    ifstream myFile;
    myFile.open("Asignaturas.txt",ios::in);

    if(!myFile.good()){
        cout << "Error";
    }
    else{
        while(!myFile.eof()){
            myFile.read((char *)&mySubject,sizeof(mySubject));

            if(myFile.eof()){break;}
            ///Le manda todo el archivo de mascota a la lista
            if(mySubject.getStatus() ==  "activo"){
                 myListSubject.insertData(myListSubject.getLastPos(), mySubject);
            }
        }

    }
    myFile.close();
    myListSubject.quickSort();
    myListSubject.toString();
    myListSubject.deleteAll();
}

void SuperUser::showCareerMenu()
{
    int opc;

    do{
            system("cls");
        cout << "Mostrar" << endl;
        cout << "1) Carrera\n2) Lista Invertida\n3) Regresar" << endl;
        cout << "opcion: ";
        cin >> opc;
        switch(opc){
            case 1:
                system("cls");
                cout << "Carreras" << endl;
                myCareerList.toString();
                system("pause");
            break;
            case 2:
                system("cls");
                cout << "Lista Invertida" << endl;
                myInvertList.toString();
                system("pause");
            break;
        }
    }while(opc != 3);
}

void SuperUser::showDisponibility()
{
    myHashing.showDisponibility();
}

void SuperUser::showCatalog()
{
    ifstream myFile;
    myFile.open("Catalogo.txt",ios::in);

    if(!myFile.good()){
        cout << "Error";
    }
    else{
        while(!myFile.eof()){
            myFile.read((char *)&myCatalog,sizeof(myCatalog));

            if(myFile.eof()){break;}

            ///if(myPeriod.getStatus() == "activo"){
                cout << "Maestro: " << reatriveTeacher(myCatalog.getTeacherCode());
                cout << "\tMateria: " << reatriveSubject(myCatalog.getSubjectCode());
                cout << "\tGrado: " << reatriveGroup(myCatalog.getGrade()) << endl;
                ///cout << "Fecha Fin: " << myPeriod.getDateFinish() << endl << endl;
            ////}
        }
    }
    myFile.close();
}

void SuperUser::showOffer()
{
    std::string period, career, group, grade, subject, teacher,origen="0",anterior="0";
    cout << "********************************************************************************************************" << endl;
    cout << "               *           ***********    *********    ******       ************        **             *" << endl;
    cout << "             *    *        *              *            *     *           **            *  *            *" << endl;
    cout << "            *       *      *              *            *      *          **           *    *           *" << endl;
    cout << "           *         *     *              *            *       *         **          *      *          *" << endl;
    cout << "          *           *    ***********    *********    *      *          **         *        *         *" << endl;
    cout << "          *           *    *              *            * * * *           **        *          *        *" << endl;
    cout << "           *         *     *              *            *      *          **       **************       *" << endl;
    cout << "            *       *      *              *            *       *         **      *              *      *" << endl;
    cout << "              *    *       *              *            *        *        **     *                *     *" << endl;
    cout << "                *          *              *********    *         *       **    *                  *    *" << endl;
    cout << "                                                                                                       *" << endl;
    cout << "********************************************************************************************************" << endl;

    ifstream myFile;
        myFile.open("Oferta.txt",ios::in);

        if(!myFile.good()){
            cout << "Error";
        }
        else{
            while(!myFile.eof()){
                myFile.read((char *)&myOffer,sizeof(myOffer));

                if(myFile.eof()){break;}
                    cout << "Periodo: " << myOffer.getPeriod() << endl;
                    cout << "\tCarrera: " << myCareerList.showCareer(myOffer.getCareer()) << endl;
                    cout << "\tNo. Grupos: " << myOffer.getGroups() << endl;

                    ifstream maestros;
                    maestros.open("Auxiliar.txt",ios::in);

                    if(!maestros.good()){
                        cout << "Error";
                    }
                    else{
                        while(!maestros.eof()){

                           getline(maestros,period,'|');
                           getline(maestros,career,'|');
                           getline(maestros,group,'|');
                           getline(maestros,grade,'|');
                           getline(maestros,subject,'|');
                           getline(maestros,teacher,'|');

                           if(maestros.eof()) break;

                            if(period == myOffer.getPeriod() && career == myOffer.getCareer()){
                                if(anterior!=grade){
                                    anterior=grade;
                                    if(origen!=group){
                                    cout << "\tGrupo: " << group <<"-"<<grade << endl;
                                    origen=group;
                                    }
                                    else{
                                    cout << "\tGrupo: " << group <<"-"<<grade << endl;
                                    origen=group;
                                    }
                                }

                               cout << "\t\tMateria: " << reatriveSubject(subject);
                               cout << "\tImpartida Por El Maestro: " << reatriveTeacher(teacher) << endl;

                            }
                        }
                    }
                    maestros.close();
            }
        }
        myFile.close();
}

void SuperUser::findData()
{
    int opc;
    do{
        system("cls");
        cout << "Que Desea Buscar?" << endl;
        cout << "1) Perfil\n2) Usuario\n3) Grupo\n4) Periodo \n5) Profesores \n6) Asignatura \n7) Edificios \n8) Regresar" << endl;
        cout << "opcion: ";
        cin >> opc;
        switch(opc){
            case 1:
                system("cls");
                cout << "\n***Perfil***" << endl;
                findProfile();
                system("pause");
            break;
            case 2:
                system("cls");
                cout << "\n***Usuario***" << endl;
                findUser();
                system("pause");
            break;
             case 3:
                system("cls");
                cout << "\n***Grupos***" << endl;
                findGroup();
                system("pause");
            break;
            case 4:
                system("cls");
                cout << "\n***Periodos***" << endl;
                findPeriod();
                system("pause");
            break;
            case 5:
                system("cls");
                cout << "\n***Profesores***" << endl;
                findProfessor();
                system("pause");
            break;
            case 6:
                system("cls");
                cout << "\n***Asignaturas***" << endl;
                findSubject();
                system("pause");
            break;
             case 7:
                system("cls");
                cout << "\n***Edificios***" << endl;
                findBuilding();
                system("pause");
            break;
        }
    }while(opc != 8);
}

void SuperUser::findProfile()
{
    char myStr[15];
    char name[100], code[100];
    int n,c, res = 0;

    cout << "Codigo de Perfil: ";
    cin >> myStr;

    ifstream myFile;
    myFile.open("Perfiles.txt",ios::in);

    if(!myFile.good()){
        cout << "Error";
    }
    else{
        while(!myFile.eof()){
            myFile.read((char*)&n,sizeof(int));
            myFile.read((char*)name,n);
            name[n]='\0';

            myFile.read((char*)&c,sizeof(int));
            myFile.read((char*)code,c);
            code[c]='\0';

            if((strcmp(myStr,code)) == 0){
                cout << "Nombre: " << name << endl;
                cout << "Codigo: " << code << endl;
                res = 1;
                break;
            }
        }
        if(res == 0){
            cout << "Perfil NO Encontrado o Perfil Invalido. . ." << endl;
        }
    }
    myFile.close();

}

void SuperUser::findUser()
{
    char myStr[15];
    char name[100], code[100], password[100], id[100];
    int n,c,p,i, res = 0;

    cout << "Codigo de Usuario: ";
    cin >> myStr;

    ifstream myFile;
    myFile.open("Usuarios.txt",ios::in);

    if(!myFile.good()){
        cout << "Error";
    }
    else{
        while(!myFile.eof()){
            myFile.read((char*)&n,sizeof(int));
            myFile.read((char*)name,n);
            name[n]='\0';

            myFile.read((char*)&c,sizeof(int));
            myFile.read((char*)code,c);
            code[c]='\0';

            myFile.read((char*)&p,sizeof(int));
            myFile.read((char*)password,p);
            password[p]='\0';

            myFile.read((char*)&i,sizeof(int));
            myFile.read((char*)id,i);
            id[i]='\0';

            if((strcmp(myStr,code)) == 0){
                cout << "Nombre: " << name << endl;
                cout << "Codigo: " << code << endl;
                cout << "Password: " << password << endl;
                cout << "Id de Perfil: " << id << endl;
                res = 1;
                break;
            }
        }
        if(res == 0){
            cout << "Perfil NO Encontrado o Perfil Invalido. . ." << endl;
        }
    }
    myFile.close();
}

void SuperUser::findGroup()
{
    string myCode;
    int flag=0;

    cout << "Ingrese Codigo del Grupo" << endl;
    cin >> myCode;

    ifstream myFile;
    myFile.open("Grupos.txt", std::ios::binary | std::ios::in);

    if(!myFile.good()){
        cout << "Error";
    }
    else{
        while(!myFile.eof()){
            myFile.read((char *)&myGroup,sizeof(myGroup));

            if(myFile.eof()) {
                break;
                }

            if(myCode == myGroup.getCode()){
                    if(myGroup.getStatus() == "activo"){
                        cout << "Id: " << myGroup.getCode() << endl;
                        cout << "Nombre: " << myGroup.getName() << endl;
                        cout << "Grado: " << myGroup.getGrade() << endl;
                        flag = 1;
                        break;
                    }
                    else{
                        cout << "Grupo Inactivo, Favor de Activar Para Buscar. . ." << endl;
                        system("pause");
                    }
            }
        }
        if(flag==0){
            cout << "Grupo Inexistente" << endl;
        }
    }
    myFile.close();
}

void SuperUser::findPeriod()
{
    string myCode;
    int flag=0;

    cout << "Ingrese Codigo del Grupo" << endl;
    cin >> myCode;

    ifstream myFile;
    myFile.open("Periodos.txt",ios::in);

    if(!myFile.good()){
        cout << "Error";
    }
    else{
        while(!myFile.eof()){
            myFile.read((char *)&myPeriod,sizeof(myPeriod));

            if(myCode == myPeriod.getCode()){
                if(myPeriod.getStatus() == "activo"){
                    cout << "Id: " << myPeriod.getCode() << endl;
                    cout << "Nombre: " << myPeriod.getName() << endl;
                    cout << "Fecha Inicio: " << myPeriod.getDateBegin() << endl;
                    cout << "Fecha Fin: " << myPeriod.getDateFinish() << endl;
                    flag = 1;
                    break;
                }
                else{
                    cout << "Periodo Inactivo, Favor de Activarlo Para Buscar. . ." << endl;
                    system("pause");
                }
            }
        }
        if(flag==0){
            cout << "Periodo Inexistente" << endl;
        }
    }
    myFile.close();
}

void SuperUser::findProfessor()
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

void SuperUser::findSubject()
{
    fstream myFile;
    ifstream indexFile;
    std::string myStr;
    int flag = 0;
    cin.get();

    cout << "Ingrese Codigo a Buscar: ";
    getline(cin,myStr,'\n');

    indexFile.open("Indices.txt");

    if(!indexFile.good()){
        cout << "Error";
    }
    else{
        while(!indexFile.eof()){
            indexFile.read((char*)&myIndex,sizeof(myIndex));

            if(indexFile.eof()) break;

            if(myStr == myIndex.getIndexId()){
                    indexFile.close();

                    myFile.open("Asignaturas.txt");
                    myFile.seekp(myIndex.getIdxReference());
                    myFile.read((char *)&mySubject,sizeof(mySubject));
                    if(mySubject.getStatus() == "activo"){
                        cout << "Codigo: " << mySubject.getCode() << endl;
                        cout << "Creditos: " << mySubject.getCredit() << endl;
                        cout << "Nombre: " << mySubject.getName() << endl;
                        cout << "Carrera: " << mySubject.getProgram() << endl << endl;
                        flag = 1;
                        break;
                    }
                    else{
                        cout << "Asignatura Inactiva, Favor de Activarla Para Buscar. . ." << endl;
                        system("pause");
                    }
            }
        }
        if(flag == 0){
            cout << "Asignatura Inexistente o Invalida. . ." << endl;
        }
    myFile.close();
    }
}

void SuperUser::findBuilding()
{
     bool encontrado = false;
    string myStr, myName, myCode, myDivision, myStatus;

    ifstream myFile("Edificios.txt");

    cout << "Ingrese el ID Del Edificio a Buscar: ";
    cin >> myStr;

    while(!myFile.eof()){
        getline(myFile,myCode,'|');
        getline(myFile,myName,'|');
        getline(myFile,myDivision,'|');
        getline(myFile,myStatus,'|');


        if(myFile.eof()) break;

        if(myStr == myCode){
            encontrado = true;
            if(myStatus == "activo"){

                cout << endl;

                cout << "Id Del Edificio: " << myCode << endl;
                cout << "Nombre Del Edificio: " << myName << endl;
                cout << "Division Del Edificio: " << myDivision << endl;
                cout << "Estatus Del Edificio: " << myStatus << endl;

                cin.ignore();
            }
            else{
                cout << "Edificio Desactivado, Favor De Activar Para Buscar. . ." << endl;
                system("pause");
            }

        }
    }
    if(encontrado == false){
        cout << "Edificio NO Encontrado. . ." << endl;
    }

    myFile.close();
}

void SuperUser::modifyData()
{
    int opc;
    do{
        system("cls");
        cout << "Que Desea Modificar?" << endl;
        cout << "1) Perfil\n2) Usuario\n3) Grupo\n4) Periodo \n5) Profesores \n6) Asignatura \n7) Edificios \n8) Disponibilidad \n9) Oferta \n10) Regresar \n" << endl;
        cout << "opcion: ";
        cin >> opc;
        switch(opc){
            case 1:
                system("cls");
                cout << "\n***Perfil***" << endl;
                modifyProfile();

                system("pause");
            break;
            case 2:
                system("cls");
                cout << "\n***Usuario***" << endl;
                modifyUser();

                system("pause");
            break;
            case 3:
                system("cls");
                cout << "\n***Grupo***" << endl;
                modifyGroup();
                system("pause");
            break;
            case 4:
                system("cls");
                cout << "\n***Periodo***" << endl;
                modifyPeriod();
                system("pause");
            break;
            case 5:
                system("cls");
                cout << "\n***Profesor***" << endl;
                modifyProfessor();
                system("pause");
            break;
            case 6:
                system("cls");
                cout << "\n***Asignatura***" << endl;
                modifySubject();
                system("pause");
            break;
            case 7:
                system("cls");
                cout << "\n***Edificios***" << endl;
                modifyBuilding();
                system("pause");
            break;
            case 8:
                system("cls");
                cout << "\n***Disponibilidad***" << endl;
                modifyDisponibility();
                system("pause");
            break;
            case 9:
                system("cls");
                cout << "\n***Oferta***" << endl;
                modifyOffer();
                system("pause");
            break;
        }
    }while(opc != 10);
}

void SuperUser::modifyProfile()
{
    string myStr2;
    char myStr[15];
    char name[100], code[100];
    int n,c, res = 0;


    cout << "Codigo de Perfil: ";
    cin >> myStr;

    cin.get();

    ifstream myFile("Perfiles.txt",ios::in);
    ofstream temp("Temporal.txt",ios::app);

    if(!myFile.good()){
        cout << "Error";
    }
    else{
        while(!myFile.eof()){
            myFile.read((char*)&n,sizeof(int));
            myFile.read((char*)name,n);
            name[n]='\0';

            myFile.read((char*)&c,sizeof(int));
            myFile.read((char*)code,c);
            code[c]='\0';

            if(myFile.eof()) break;

            if((strcmp(myStr,code)) == 0){
                cout << "Ingrese El Nombre Del Perfil: ";
                getline(cin,myStr2);
                myProfile.setName(myStr2);

                cout << "Ingrese El Codigo Del Perfil: ";
                getline(cin,myStr2);
                myProfile.setCode(myStr2);

                n = strlen(myProfile.getName().c_str());
                c = strlen(myProfile.getCode().c_str());

                temp.write((char*)&n,sizeof(int));
                temp.write((char*)myProfile.getName().c_str(),n);

                temp.write((char*)&c,sizeof(int));
                temp.write((char*)myProfile.getCode().c_str(),c);
                res = 1;
                ///break;
                cout << "\n Perfil Modificado!" << endl;
            }
            else{
                n = strlen(name);
                c = strlen(code);

                temp.write((char*)&n,sizeof(int));
                temp.write((char*)name,n);

                temp.write((char*)&c,sizeof(int));
                temp.write((char*)code,c);

            }
        }
        if(res == 0){
            cout << "Perfil NO Encontrado o Perfil Invalido. . ." << endl;
        }
    }
    myFile.close();
    temp.close();
    remove("Perfiles.txt");
    rename("Temporal.txt","Perfiles.txt");
}

void SuperUser::modifyUser()
{
    string myStr2;
    char myStr[15];
    char name[100], code[100], password[100], id[100];
    int n,c,p,i, res = 0;
    bool flag;


    cout << "Codigo de Usuario: ";
    cin >> myStr;

    cin.get();

    ifstream myFile("Usuarios.txt",ios::in);
    ofstream temp("Temporal.txt",ios::app);

    if(!myFile.good()){
        cout << "Error";
    }
    else{
        while(!myFile.eof()){
            myFile.read((char*)&n,sizeof(int));
            myFile.read((char*)name,n);
            name[n]='\0';

            myFile.read((char*)&c,sizeof(int));
            myFile.read((char*)code,c);
            code[c]='\0';

            myFile.read((char*)&p,sizeof(int));
            myFile.read((char*)password,p);
            password[p]='\0';

            myFile.read((char*)&i,sizeof(int));
            myFile.read((char*)id,i);
            id[i]='\0';

            if(myFile.eof()) break;

            if((strcmp(myStr,code)) == 0){
                cout << "Ingrese El Nombre Del Usuario: ";
                getline(cin,myStr2);
                myUser.setName(myStr2);

                cout << "Ingrese El Codigo Del Usuario: ";
                getline(cin,myStr2);
                myUser.setUserCode(myStr2);

                cout << "Ingrese El Password Del Usuario: ";
                getline(cin,myStr2);
                myUser.setPassword(myStr2);

                cout << "Ingrese El ID Del Perfil Para Ligarlo: ";
                getline(cin,myStr2);

                flag = existUser(myStr2);
                if(flag == false){
                    cout << "El Perfil Elegido No Puede Ser Asignado, Favor de Verificarlo. . ." << endl;
                    ///exit(1);
                    return ;
                }


                myUser.setIdProfile(myStr2);

                n = strlen(myUser.getName().c_str());
                c = strlen(myUser.getUserCode().c_str());
                p = strlen(myUser.getPassword().c_str());
                i = strlen(myUser.getIdProfile().c_str());

                temp.write((char*)&n,sizeof(int));
                temp.write((char*)myUser.getName().c_str(),n);

                temp.write((char*)&c,sizeof(int));
                temp.write((char*)myUser.getUserCode().c_str(),c);

                temp.write((char*)&p,sizeof(int));
                temp.write((char*)myUser.getPassword().c_str(),p);

                temp.write((char*)&i,sizeof(int));
                temp.write((char*)myUser.getIdProfile().c_str(),i);
                res = 1;
                ///break;
                cout << "\n Usuario Modificado!" << endl;
            }
            else{
                n = strlen(name);
                c = strlen(code);
                p = strlen(password);
                i = strlen(id);

                temp.write((char*)&n,sizeof(int));
                temp.write((char*)name,n);

                temp.write((char*)&c,sizeof(int));
                temp.write((char*)code,c);

                temp.write((char*)&p,sizeof(int));
                temp.write((char*)password,p);

                temp.write((char*)&i,sizeof(int));
                temp.write((char*)id,i);

            }
        }
        if(res == 0){
            cout << "Perfil NO Encontrado o Perfil Invalido. . ." << endl;
        }
    }
    myFile.close();
    temp.close();
    remove("Usuarios.txt");
    rename("Temporal.txt","Usuarios.txt");
}

void SuperUser::modifyGroup()
{
    fstream myFile;
    std::string myCode;
    std::string myTempCode;
    std::string myName;
    int myInt,flag=0;
    cin.ignore();

    cout << "Ingrese Codigo de Grupo" << endl;
    cin >> myInt;

    cin.ignore();
    myFile.open("Grupos.txt", std::ios::in | std::ios::out | std::ios::binary);

    if(!myFile.good()) {
        cout << "No se pudo abrir\n";
        }
    else {

        while(!myFile.eof()) {

            myFile.read((char*)&myGroup,sizeof(Group));

            if(myFile.eof()) {
                break;
                }

            if(to_string(myInt) == myGroup.getCode()) {

                myGroup.setCode(to_string(myInt));

                if(myGroup.getStatus() == "activo"){
                    cout << "Ingrese Nuevo Nombre" << endl;
                    getline(cin,myName);
                    myGroup.setName(myName);
                    myGroup.setGrade("3");

                    myFile.seekp(size_t(myFile.tellg()) - sizeof(myGroup));

                    myFile.write((char*)& myGroup, sizeof(myGroup));
                    flag = 1;
                    break;
                }
                else{
                    cout << "Grupo Inactivo, Favor de Activarlo Para Modificarlo. . ." << endl;
                    system("pause");
                }
            }
        }
    }
    if(flag == 1){
        cout << "Grupo Modificado. . ." << endl;
    }
    else{
        cout << "Grupo No Encontrado. . ." << endl;
    }

    myFile.close();
}

void SuperUser::modifyPeriod()
{
    fstream myFile;
    std::string myCode;
    std::string myTempCode;
    std::string myName;
    std::string myDateBeg;
    std::string myDateFin;
    int myInt,flag=0;
    cin.ignore();

    cout << "Ingrese Codigo de Periodo" << endl;
    cin >> myInt;

    cin.ignore();
    myFile.open("Periodos.txt", std::ios::in | std::ios::out | std::ios::binary);

    if(!myFile.good()) {
        cout << "No se pudo abrir\n";
        }
    else {

        while(!myFile.eof()) {

            myFile.read((char*)&myPeriod,sizeof(Period));

            if(myFile.eof()) {
                break;
                }

            if(to_string(myInt) == myPeriod.getCode()) {

                if(myPeriod.getStatus() == "activo"){
                    myPeriod.setCode(to_string(myInt));

                    cout << "Ingrese Nuevo Nombre" << endl;
                    getline(cin,myName);
                    myPeriod.setName(myName);

                    cout << "Ingrese Nueva Fecha de Inicio" << endl;
                    getline(cin,myDateBeg);
                    myPeriod.setDateBegin(myDateBeg);

                    cout << "Ingrese Nueva Fecha de Fin" << endl;
                    getline(cin,myDateFin);
                    myPeriod.setDateFinish(myDateFin);

                    myFile.seekp(size_t(myFile.tellg()) - sizeof(myPeriod));

                    myFile.write((char*)& myPeriod, sizeof(myPeriod));
                    flag = 1;
                    break;
                }
                else{
                    cout << "Periodo Desactivado, Favor De Activar Para Modificar. . ." << endl;
                    system("pause");
                }

                }
            }
        }
        if(flag == 1){
            cout << "Periodo Modificado. . ." << endl;
        }
        else{
            cout << "Periodo No Encontrado. . ." << endl;
        }

    myFile.close();
}

void SuperUser::modifyProfessor()
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

            /*cout << "Ingrese Codigo: ";
            getline(cin,myCode);
            myTeacher.setCode(myCode);*/

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

void SuperUser::modifySubject()
{
    int flag = 0;
    fstream myFile;
    ifstream indexFile;
    std::string myStr,myStr2,myCode,myProgram;
    cin.get();
    cout << "Ingrese Codigo a Modificar: ";
    getline(cin,myStr,'\n');

    indexFile.open("Indices.txt");

    if(!indexFile.good()){
        cout << "Error";
    }
    else{
        while(!indexFile.eof()){
            indexFile.read((char*)&myIndex,sizeof(myIndex));

            if(indexFile.eof()) break;

            if(myStr == myIndex.getIndexId()){
                    indexFile.close();
                    myFile.open("Asignaturas.txt");
                    myFile.seekg(myIndex.getIdxReference());
                    myFile.read((char *)&mySubject,sizeof(mySubject));
                    if(mySubject.getStatus() == "activo"){

                         myInvertList.deleteData(myInvertList.reatrieveData(myStr));
                        if(myInvertList.existCareer(myCareerList.reatriveLabel(mySubject.getProgram())) == false){
                            myCareerList.deleteData(myCareerList.findDataLinear(mySubject.getProgram()));
                        }
                        cout << "Ingrese Creditos: ";
                        getline(cin,myStr2);
                        mySubject.setCredit(myStr2);

                        cout << "Ingrese Nombre: ";
                        cin >> myStr2;
                        mySubject.setName(myStr2);

                        cin.get();
                        cout << "Ingrese Carrera: ";
                        std::getline(cin, myStr2);
                        mySubject.setProgram(myStr2);
                        myCareer.setName(myStr2);

                        myCareer.setLabel(myCareerList.getLast());


                        myFile.seekp(myIndex.getIdxReference());
                        myFile.write((char *)&mySubject,sizeof(mySubject));

                        if(!myCareerList.findDataLinear(myCareer.getName())){
                            myCareerList.InsertData(myCareerList.getLastPost(),myCareer);
                        }
                        myInvert.setCode(myIndex.getIndexId());
                        myInvert.setLabel(myCareerList.reatriveLabel(myCareer.getName()));

                        myInvertList.inserData(myInvertList.getLastPos(),myInvert);
                        flag = 1;
                        break;

                }
                else{
                    cout << "Asignatura Desactivada, Favor De Activar Para Modificar. . ." << endl;
                    system("pause");
                }
            }
        }
    }
    if(flag == 1){
        cout << "Asignatura Modificada. . ." << endl;
    }
    else{
        cout << "Asignatura No Encontrada. . ." << endl;
    }
    myFile.close();
    ///myListIndex.deleteAll();
    ///myListSubject.deleteAll();
    ///fromDiskToList();
}

void SuperUser::modifyBuilding()
{
    bool encontrado = false;
    string myStr, myName, newName, myCode, myDivision, myStatus;


    ofstream temp("Temporal.txt",ios::app);
    ifstream myFile("Edificios.txt");

    cout << "Ingrese el codigo del Edificio a Modificar: ";
    cin >> myStr;

    while(!myFile.eof()){
        getline(myFile,myCode,'|');
        getline(myFile,myName,'|');
        getline(myFile,myDivision,'|');
        getline(myFile,myStatus,'|');

        if(myFile.eof()) break;

        if(myStr == myCode){
            encontrado = true;
            if(myStatus == "activo"){
                cin.ignore();

                myBuilding.setId(myCode);

                cout << "Ingrese Nombre: ";
                getline(cin,newName);
                myBuilding.setName(newName);

                cout << "Ingrese Division: ";
                getline(cin,myDivision);
                myBuilding.setDivision(myDivision);

                myBuilding.setExists(myStatus);
                cout << "Edificio Modificado!. . ." << endl;
                myGraph.modifyVertex(myName,newName);
            }
            else{
                cout << "Edificio Desactivado, Favor De Activar Para Modificar. . ." << endl;
                system("pause");
            }
            temp << myCode << '|' << newName << '|' << myDivision << '|' << myStatus << '|';
        }
        else{
             temp << myCode << '|' << myName << '|' << myDivision << '|' << myStatus << '|';
        }
    }
    if(encontrado==false){
        cout << "Edificio NO Encontrado. . ." << endl;
    }

    myFile.close();
    temp.close();
    remove("Edificios.txt");
    rename("Temporal.txt","Edificios.txt");
}

void SuperUser::modifyDisponibility()
{
    string teacherName, subjectName, idMaestro, idMateria, myStr,myStr1;
     time_t curr_time;
	tm * curr_tm;
	char date_string[100];
	char time_string[100];
	time(&curr_time);
	curr_tm = localtime(&curr_time);
    strftime(date_string, 50, "%d-%m-%Y", curr_tm);
	strftime(time_string, 50, "%H:%M:%S", curr_tm);

	string date, time;
	date = date_string;
	time = time_string;
    cin.get();

        cout << "Ingresa el HashCode a modificar: ";
        getline(cin, myStr1);

        if(myHashing.existHashingCode(myStr1)){
            ///Validar si el hashCode es valido///

            cout << "Ingresa el Nuevo Codigo del Maestro: ";
            getline(cin, idMaestro);
            if(teacherValid(idMaestro)==false){
                cout << "Id de Maestro invalido, favor de revisarlo. . ." << endl;
                return;
            }

            cout << "Ingresa el Nuevo Codigo de la Materia: ";
            getline(cin, idMateria);
            if(subjectValid(idMateria)==false){
                cout << "Id de la Materia invalida, favor de revisarla. . ." << endl;
                return;
            }

            myStr = idMaestro + idMateria;
            myDisponibility.setHashingCode(myStr);
            myDisponibility.setDate(date);
            myDisponibility.setHour(time);
            myHashing.modifyDisponibility(myStr1, myDisponibility);
        }
        else{
            cout << "HashingCode Invalido. . ." << endl;
            system("pause");
        }


}

void SuperUser::modifyOffer()
{
    std::string periodName,careerName,grade,group,subjectName,teacherName;
    ///bool encontrado = false;
    string myPeriod, myCareer, myGrade, myGroup, mySubject, myTeacher;
    ofstream temp("Temporal.txt",ios::app);
    ifstream myFile("Auxiliar.txt");
    cin.ignore();

    cout << "Ingresa el Periodo de la Oferta que va a Modificar: ";
    getline(cin,periodName);
    myCareerList.toString();
    cout << "Seleccione la Carrera: ";
    getline(cin,careerName);
    reatriveOfferGroup(periodName,careerName);
    cout << "Seleccione el Grado: ";
    getline(cin,grade);

    cout << "Seleccione el Grupo: ";
    getline(cin,group);
    showSpecificOfferSubject(myCareerList.showCareer(careerName),grade);
    cout << "Seleccione la Materia a Modificar: ";
    getline(cin,subjectName);
    reatriveDisponibility(subjectName);
    cout << "Seleccione al nuevo Maestro que dara la Materia: ";
    getline(cin,teacherName);
    while(myHashing.verifyDisponibility(teacherName,subjectName)==false){
        cout << "Seleccione al nuevo Maestro que dara la Materia: ";
        getline(cin,teacherName);
    }

    while(!myFile.eof()){
        getline(myFile,myPeriod,'|');
        getline(myFile,myCareer,'|');
        getline(myFile,myGrade,'|');
        getline(myFile,myGroup,'|');
        getline(myFile,mySubject,'|');
        getline(myFile,myTeacher,'|');

        if(myFile.eof()) break;

        if(myPeriod == periodName && myCareer == careerName && myGrade == grade && myGroup == group && mySubject == subjectName){
            temp << myPeriod << '|' << myCareer << '|' << myGrade << '|' << myGroup << '|' << mySubject << '|' << teacherName << '|';
        }
        else{
             temp << myPeriod << '|' << myCareer << '|' << myGrade << '|' << myGroup << '|' << mySubject << '|' << myTeacher << '|';
        }
    }
    myFile.close();
    temp.close();
    remove("Auxiliar.txt");
    rename("Temporal.txt","Auxiliar.txt");
}

void SuperUser::deleteData()
{
    int opc;
    do{
        system("cls");
        cout << "Que Desea Eliminar?" << endl;
        cout << "1) Perfil\n2) Usuario\n3) Grupo\n4) Periodo \n5) Profesores \n6) Asignatura \n7) Edificios \n8) Arista \n9) Disponibilidad \n10) Oferta \n11) Regresar" << endl;
        cout << "opcion: ";
        cin >> opc;
        switch(opc){
            case 1:
                cout << "\n***Perfil***" << endl;
                deleteProfile();
                system("pause");
            break;
            case 2:
                cout << "\n***Usuario***" << endl;
                deleteUser();
                system("pause");
            break;
            case 3:
                cout << "\n***Grupo***" << endl;
                deleteGroup();
                system("pause");
            break;
            case 4:
                cout << "\n***Periodo***" << endl;
                deletePeriod();
                system("pause");
            break;
            case 5:
                cout << "\n***Profesor***" << endl;
                deleteProfessor();
                system("pause");
            break;
            case 6:
                cout << "\n***Asignatura***" << endl;
                deleteSubject();
                system("pause");
            break;
             case 7:
                cout << "\n***Edificios***" << endl;
                deleteBuilding();
                system("pause");
            break;
            case 8:
                cout << "\n***Arista***" << endl;
                deleteEdge();
                system("pause");
            break;
            case 9:
                system("cls");
                cout << "\n***Disponibilidad***" << endl;
                deleteDisponibility();
                system("pause");
            break;
            case 10:
                system("cls");
                cout << "\n***Oferta***" << endl;
                deleteOffer();
                system("pause");
            break;
        }
    }while(opc != 11);
}

void SuperUser::deleteProfile()
{
    string myStr2;
    char myStr[15];
    char name[100], code[100];
    bool flag;
    int n,c, res = 0;


    cout << "Codigo de Perfil: ";
    cin >> myStr;

    flag = verifyDelete(myStr);

    if(flag == true){
        cout << "El Perfil Elegido No Puede Ser Eliminado, Favor de Verificarlo. . ." << endl;
        ///exit(1);
        return ;
    }

    cin.get();

    ifstream myFile("Perfiles.txt");
    ofstream temp("Temporal.txt",ios::app);

    if(!myFile.good()){
        cout << "Error";
    }
    else{
        while(!myFile.eof()){
            myFile.read((char*)&n,sizeof(int));
            myFile.read((char*)name,n);
            name[n]='\0';

            myFile.read((char*)&c,sizeof(int));
            myFile.read((char*)code,c);
            code[c]='\0';

            if(myFile.eof()){break; }

            if((strcmp(myStr,code)) == 0){
                cout << "Nombre: " << name << endl;
                cout << "Codigo: " << code << endl;
                cout << "Perfil Eliminado!" << endl;
                res = 1;
                ///break;
            }
            else{
                n = strlen(name);
                c = strlen(code);

                temp.write((char*)&n,sizeof(int));
                temp.write((char*)name,n);

                temp.write((char*)&c,sizeof(int));
                temp.write((char*)code,c);

            }
        }
        if(res == 0){
            cout << "Perfil NO Encontrado o Perfil Invalido. . ." << endl;
        }
    }
    myFile.close();
    temp.close();
    remove("Perfiles.txt");
    rename("Temporal.txt","Perfiles.txt");
}

void SuperUser::deleteUser()
{
    char myStr[15];
    char name[100], code[100], password[100], id[100];
    int n,c,p,i, res = 0;


    cout << "Codigo de Usuario: ";
    cin >> myStr;

    cin.get();

    ifstream myFile("Usuarios.txt",ios::in);
    ofstream temp("Temporal.txt",ios::app);

    if(!myFile.good()){
        cout << "Error";
    }
    else{
        while(!myFile.eof()){
            myFile.read((char*)&n,sizeof(int));
            myFile.read((char*)name,n);
            name[n]='\0';

            myFile.read((char*)&c,sizeof(int));
            myFile.read((char*)code,c);
            code[c]='\0';

            myFile.read((char*)&p,sizeof(int));
            myFile.read((char*)password,p);
            password[p]='\0';

            myFile.read((char*)&i,sizeof(int));
            myFile.read((char*)id,i);
            id[i]='\0';

            if(myFile.eof()) break;

            if((strcmp(myStr,code)) == 0){
                cout << "Nombre: " << name << endl;
                cout << "Codigo: " << code << endl;
                cout << "Password: " << password << endl;
                cout << "Id de Perfil: " << id << endl;
                cout << "\n Usuario Eliminado!" << endl;
                res = 1;
                ///break;
            }
            else{
                n = strlen(name);
                c = strlen(code);
                p = strlen(password);
                i = strlen(id);

                temp.write((char*)&n,sizeof(int));
                temp.write((char*)name,n);

                temp.write((char*)&c,sizeof(int));
                temp.write((char*)code,c);

                temp.write((char*)&p,sizeof(int));
                temp.write((char*)password,p);

                temp.write((char*)&i,sizeof(int));
                temp.write((char*)id,i);

            }
        }
        if(res == 0){
            cout << "Perfil NO Encontrado o Perfil Invalido. . ." << endl;
        }
    }
    myFile.close();
    temp.close();
    remove("Usuarios.txt");
    rename("Temporal.txt","Usuarios.txt");
}

void SuperUser::deleteGroup()
{
    fstream myFile;
    std::string myCode;
    std::string myTempCode;
    std::string myName;
    int myInt,flag=0, flag2 =0;
    cin.ignore();

    cout << "Ingrese Codigo de Grupo" << endl;
    cin >> myInt;

    cin.ignore();
    ofstream temp("Temporal.txt",ios::app);
    myFile.open("Grupos.txt", std::ios::in | std::ios::out | std::ios::binary);

    if(!myFile.good()) {
        cout << "No se pudo abrir\n";
        }
    else {

        while(!myFile.eof()) {

            myFile.read((char*)&myGroup,sizeof(Group));

            if(myFile.eof()) {
                break;
                }

            if(to_string(myInt) == myGroup.getCode()) {

                if(myGroup.getStatus() == "activo"){
                    cout << "Grupo Eliminado!. . ." << endl;
                    flag = 1;
                    flag2 = 1;
                }
                else{
                    /*cout << "Grupo Inactivo, Favor De Activar Para Eliminar. . ." << endl;
                    system("pause");*/
                }
            }
            else{
                temp.write((char*)& myGroup, sizeof(myGroup));
            }
        }
        if(flag == 0){
            cout << "Registro Invalido. . ." << endl;
        }
    }
    if(flag2 == 1){
        myFile.close();
        temp.close();
        remove("Grupos.txt");
        rename("Temporal.txt","Grupos.txt");
    }
    else{
        cout << "Grupo Inactivo, Favor De Activar Para Eliminar. . ." << endl;
        system("pause");
        myFile.close();
        temp.close();
        remove("Temporal.txt");
        ///rename("Temporal.txt","Grupos.txt");
    }

}

void SuperUser::deletePeriod()
{
    fstream myFile;
    std::string myCode;
    std::string myTempCode;
    std::string myName;
    int myInt,flag=0,flag2 = 0;
    cin.ignore();

    cout << "Ingrese Codigo de Periodo" << endl;
    cin >> myInt;

    cin.ignore();
    ofstream temp("Temporal.txt",ios::app);
    myFile.open("Periodos.txt", std::ios::in | std::ios::out | std::ios::binary);

    if(!myFile.good()) {
        cout << "No se pudo abrir\n";
        }
    else {

        while(!myFile.eof()) {

            myFile.read((char*)&myPeriod,sizeof(Period));

            if(myFile.eof()) {
                break;
                }

            if(to_string(myInt) == myPeriod.getCode()) {

                if(myPeriod.getStatus() == "activo"){
                    cout << "Periodo Eliminado!. . ." << endl;
                    flag = 1;
                    flag2 = 1;
                }


            }
            else{
                temp.write((char*)& myPeriod, sizeof(myPeriod));
            }
        }
        if(flag == 0){
            cout << "Periodo Invalido. . ." << endl;
        }
    }
    if(flag2 == 1){
        myFile.close();
        temp.close();
        remove("Periodos.txt");
        rename("Temporal.txt","Periodos.txt");
    }
    else{
        cout << "Grupo Inactivo, Favor De Activar Para Eliminar. . ." << endl;
        system("pause");
        myFile.close();
        temp.close();
        remove("Temporal.txt");
        ///rename("Temporal.txt","Grupos.txt");
    }
    /*myFile.close();
    temp.close();
    remove("Periodos.txt");
    rename("Temporal.txt","Periodos.txt");*/
}

void SuperUser::deleteProfessor()
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

void SuperUser::deleteSubject()
{
    std::string myName;
    string myCode;
    ///bool encontrado = false;
    int flag = 0;
    fstream SubFile;
    ifstream indexFile;
    ofstream SubTemp;
    ofstream indicesTemp;
    cin.get();
    cout << "Ingrese el Codigo a Eliminar: ";
    getline(cin,myCode,'\n');

    SubTemp.open("AsignaturasTemporal.txt", ios::app);
    indicesTemp.open("IndicesTemporal.txt", ios::app);
    indexFile.open("Indices.txt");
    SubFile.open("Asignaturas.txt");

    if(!indexFile.good()){
        cout << "Error";
    }
    else{
        while(!indexFile.eof()){
            indexFile.read((char*)&myIndex,sizeof(myIndex));

            if(indexFile.eof()) break;

            if(myCode == myIndex.getIndexId()){
                ///encontrado = true;
                SubFile.seekg(myIndex.getIdxReference());
                SubFile.read((char *)&mySubject,sizeof(Subject));
                if(mySubject.getStatus() == "activo"){
                    cout << "Codigo: " << mySubject.getCode() << endl;
                    cout << "Creditos: " << mySubject.getCredit() << endl;
                    cout << "Nombre: " << mySubject.getName() << endl;
                    cout << "Carrera: " << mySubject.getProgram() << endl;
                    cout << "Eliminado!" << endl << endl;
                    flag = 1;
                    myInvertList.deleteData(myInvertList.reatrieveData(myCode));
                    if(myInvertList.existCareer(myCareerList.reatriveLabel(mySubject.getProgram())) == false){
                        myCareerList.deleteData(myCareerList.findDataLinear(mySubject.getProgram()));
                    }
                }
            }
            else{
                SubFile.seekg(myIndex.getIdxReference());
                SubFile.read((char *)&mySubject,sizeof(Subject));

                SubTemp.seekp(myIndex.getIdxReference());
                SubTemp.write((char*)&mySubject, sizeof(Subject));
                indicesTemp.write((char*)&myIndex, sizeof(Index));
            }
        }
    }
    if(flag == 1){
        indexFile.close();
        SubFile.close();
        SubTemp.close();
        indicesTemp.close();
        remove("Asignaturas.txt");
        rename("AsignaturasTemporal.txt","Asignaturas.txt");
        remove("Indices.txt");
        rename("IndicesTemporal.txt","Indices.txt");
    }
    else{
        cout << "Asignatura Inactiva, Favor De Activar Para Eliminar. . ." << endl;
        system("pause");
        indexFile.close();
        SubFile.close();
        SubTemp.close();
        indicesTemp.close();
        remove("IndicesTemporal.txt");
        remove("AsignaturasTemporal.txt");

    }
}

void SuperUser::deleteBuilding()
{
    system("cls");
    bool encontrado = false;
     string myStr, myName, myCode, myDivision, myStatus;

    ofstream temp("Temporal.txt",ios::app);
    ifstream myFile("Edificios.txt");

    cout << "Ingrese el codigo del Edificio a Eliminar: ";
    cin >> myStr;

    while(!myFile.eof()){
        getline(myFile,myCode,'|');
        getline(myFile,myName,'|');
        getline(myFile,myDivision,'|');
        getline(myFile,myStatus,'|');

        if(myFile.eof()) break;

        if(myCode == myStr){
            encontrado=true;
            if(myStatus == "activo"){
                cout << "ID Del Edificio: " << myCode << endl;
                cout << "Nombre Del Edificio: " << myName << endl;
                cout << "Division Del Edificio: " << myDivision << endl;
                cout << "Estatus: " << myStatus << endl;
                cout << "Eliminado!.." << endl;
                myGraph.deleteVertex(myName);
            }
            else{
                cout << "Edificio Desactivado, Favor De Activar Para Eliminar. . ." << endl;
                system("pause");
                temp << myCode << '|' << myName << '|' << myDivision << '|' << myStatus << '|';
            }
        }
        else{
             temp << myCode << '|' << myName << '|' << myDivision << '|' << myStatus << '|';
        }
    }
    if(encontrado==false){
        cout<<"Edificio No Encontrado"<<endl;
    }

    myFile.close();
    temp.close();
    remove("Edificios.txt");
    rename("Temporal.txt","Edificios.txt");
}

void SuperUser::deleteEdge()
{
    cin.get();
    std::string myStr, myStr2;
    cout << "Inserte Origen: ";
    getline(cin,myStr);

    cout << "Inserte Destino: ";
    getline(cin,myStr2);

    myGraph.deleteEdge(myStr,myStr2);
}

void SuperUser::deleteDisponibility()
{
    string auxString;
    cin.get();

    cout << "Ingresa el HashCode de la Disponibilidad a Eliminar: ";
    getline(cin, auxString);

     if(myHashing.existHashingCode(auxString)){
        myHashing.deleteDisponibility(auxString);
     }
     else{
        cout << "HashingCode Invalido. . ." << endl;
            system("pause");
     }
}

void SuperUser::deleteOffer()
{
    fstream myFile;
    ifstream myAux("Auxiliar.txt");
    ofstream tempAux("Temporal.txt",ios::app);
    std::string myStr, periodName, career, grade, group, subjectName, teacherName;
    int flag=0;
    cin.ignore();

    cout << "Ingresa el Periodo de la Oferta a Eliminar: ";
    getline(cin,myStr);

    ofstream temp("Copia.txt",ios::app);
    myFile.open("Oferta.txt", std::ios::in | std::ios::out | std::ios::binary);

    if(!myFile.good()) {
        cout << "No se pudo abrir\n";
        }
    else {

        while(!myFile.eof()) {

            myFile.read((char*)&myOffer,sizeof(AcademicOffer));

            if(myFile.eof()) {break;}

            if(myOffer.getPeriod() == myStr){
                ///cout << "Oferta " << myStr << " Eliminado!. . ." << endl;
                flag = 1;
            }
            else{
                temp.write((char*)&myOffer,sizeof(AcademicOffer));
            }
        }
        if(flag == 0){
            cout << "Periodo Invalido. . ." << endl;
        }
    }

    myFile.close();
    temp.close();
    remove("Oferta.txt");
    rename("Copia.txt","Oferta.txt");


    while(!myAux.eof()){
        getline(myAux,periodName,'|');
        getline(myAux,career,'|');
        getline(myAux,grade,'|');
        getline(myAux,group,'|');
        getline(myAux,subjectName,'|');
        getline(myAux,teacherName,'|');

        if(myAux.eof()) break;

        if(!(periodName == myStr)){
            tempAux << periodName << '|' << career << '|' << grade << '|' << group << '|' << subjectName << '|' << teacherName << '|';

        }
        /*else{
            cout << "Oferta Academica: " << periodName << endl;
            cout << "Eliminado!.." << endl;
        }*/
    }

    myAux.close();
    tempAux.close();
    remove("Auxiliar.txt");
    rename("Temporal.txt","Auxiliar.txt");
}

void SuperUser::logicDelete()
{
    int opc;
    do{
        system("cls");
        cout << "Que Desea Dar de Baja?" << endl;
        cout << "1) Grupo\n2) Periodo \n3) Asignatura \n4) Edificios \n5) Aristas \n6) Regresar" << endl;
        cout << "opcion: ";
        cin >> opc;
        switch(opc){
            case 1:
                cout << "\n***Grupo***" << endl;
                logicDeleteGroup();
                system("pause");
            break;
            case 2:
                cout << "\n***Periodo***" << endl;
                logicDeletePeriod();
                system("pause");
            break;
            case 3:
                cout << "\n***Asignatura***" << endl;
                logicDeleteSubject();
                system("pause");
            break;
            case 4:
                cout << "\n***Edificios***" << endl;
                logicDeleteBuilding();
                system("pause");
            break;
            case 5:
                cout << "\n***Aristas***" << endl;
                logicDeleteEdge();
                system("pause");
            break;
        }
    }while(opc != 6);
}

void SuperUser::logicDeleteGroup()
{
    fstream myFile;
    std::string myCode;
    std::string myTempCode;
    std::string myName;
    std::string myDateBeg;
    std::string myDateFin;
    int myInt,flag=0;
    cin.ignore();

    cout << "Ingrese Codigo de Grupo" << endl;
    cin >> myInt;

    cin.ignore();
    myFile.open("Grupos.txt", std::ios::in | std::ios::out | std::ios::binary);

    if(!myFile.good()) {
        cout << "No se pudo abrir\n";
        }
    else {

        while(!myFile.eof()) {

            myFile.read((char*)&myGroup,sizeof(Group));

            if(myFile.eof()) {
                break;
                }

            if(to_string(myInt) == myGroup.getCode()) {

                myGroup.setCode(to_string(myInt));

                myGroup.setStatus("inactivo");

                myFile.seekp(size_t(myFile.tellg()) - sizeof(myGroup));

                myFile.write((char*)& myGroup, sizeof(myGroup));
                flag = 1;
                break;
                }
            }
        }
        if(flag == 1){
            cout << "Grupo Inactivo. . ." << endl;
        }
        else{
            cout << "Grupo No Existente O Ya Inactivado. . ." << endl;
        }

    myFile.close();
}

void SuperUser::logicDeletePeriod()
{
    fstream myFile;
    std::string myCode;
    std::string myTempCode;
    std::string myName;
    std::string myDateBeg;
    std::string myDateFin;
    int myInt,flag=0;
    cin.ignore();

    cout << "Ingrese Codigo de Periodo" << endl;
    cin >> myInt;

    cin.ignore();
    myFile.open("Periodos.txt", std::ios::in | std::ios::out | std::ios::binary);

    if(!myFile.good()) {
        cout << "No se pudo abrir\n";
        }
    else {

        while(!myFile.eof()) {

            myFile.read((char*)&myPeriod,sizeof(Period));

            if(myFile.eof()) {
                break;
                }

            if(to_string(myInt) == myPeriod.getCode()) {

                myPeriod.setCode(to_string(myInt));

                /*cout << "Ingrese Nuevo Nombre" << endl;
                getline(cin,myName);
                myPeriod.setName(myName);

                cout << "Ingrese Nueva Fecha de Inicio" << endl;
                getline(cin,myDateBeg);
                myPeriod.setDateBegin(myDateBeg);

                cout << "Ingrese Nueva Fecha de Fin" << endl;
                getline(cin,myDateFin);
                myPeriod.setDateFinish(myDateFin);*/

                myPeriod.setStatus("inactivo");

                myFile.seekp(size_t(myFile.tellg()) - sizeof(myPeriod));

                myFile.write((char*)& myPeriod, sizeof(myPeriod));
                flag = 1;
                break;
                }
            }
        }
        if(flag == 1){
            cout << "Periodo Inactivo. . ." << endl;
        }
        else{
            cout << "Periodo No Existente O Ya Inactivado. . ." << endl;
        }

    myFile.close();
}

void SuperUser::logicDeleteSubject()
{
     fstream myFile;
    std::string myCode;
    int myInt,flag=0;
    cin.ignore();

    cout << "Ingrese Codigo de Asignatura" << endl;
    cin >> myInt;

    cin.ignore();
    myFile.open("Asignaturas.txt", std::ios::in | std::ios::out | std::ios::binary);

    if(!myFile.good()) {
        cout << "No se pudo abrir\n";
        }
    else {

        while(!myFile.eof()) {

            myFile.read((char*)&mySubject,sizeof(Subject));

            if(myFile.eof()) {
                break;
                }

            if(to_string(myInt) == mySubject.getCode()) {

                mySubject.setCode(to_string(myInt));

                mySubject.setStatus("inactivo");

                myFile.seekp(size_t(myFile.tellg()) - sizeof(mySubject));

                myFile.write((char*)& mySubject, sizeof(mySubject));
                flag = 1;
                break;
                }
            }
        }
        if(flag == 1){
            cout << "Asignatura Inactivo. . ." << endl;
        }
        else{
            cout << "Asignatura No Existente O Ya Inactivada. . ." << endl;
        }

    myFile.close();
}

void SuperUser::logicDeleteBuilding()
{
    bool encontrado = false;
    string myStr, myName, myCode, myDivision, myStatus;


    ofstream temp("Temporal.txt",ios::app);
    ifstream myFile("Edificios.txt");

    cout << "Ingrese el codigo del Edificio a Dar de Baja: ";
    cin >> myStr;

    while(!myFile.eof()){
        getline(myFile,myCode,'|');
        getline(myFile,myName,'|');
        getline(myFile,myDivision,'|');
        getline(myFile,myStatus,'|');

        if(myFile.eof()) break;

        if(myStr == myCode){
            encontrado = true;
            cin.ignore();

            myStatus = "inactivo";

            myBuilding.setExists(myStatus);
            myGraph.logicalVertexDelete(myName);

            temp << myCode << '|' << myName << '|' << myDivision << '|' << myStatus << '|';
        }
        else{
             temp << myCode << '|' << myName << '|' << myDivision << '|' << myStatus << '|';
        }
    }
    if(encontrado==false){
        cout << "Edificio No Existente O Ya Inactivado. . ." << endl;
    }
    else{
        cout << "Edificio Inactivo!. . ." << endl;
    }

    myFile.close();
    temp.close();
    remove("Edificios.txt");
    rename("Temporal.txt","Edificios.txt");
}

void SuperUser::logicDeleteEdge()
{
    cin.get();
    std::string myStr, myStr2;
    cout << "Inserte Origen: ";
    getline(cin,myStr);

    cout << "Inserte Destino: ";
    getline(cin,myStr2);

    myGraph.logicalEdgeDelete(myStr,myStr2);
}

void SuperUser::logicActivation()
{
    int opc;
    do{
        system("cls");
        cout << "Que Desea Dar Activar?" << endl;
        cout << "1) Grupo\n2) Periodo \n3) Asignaturas \n4) Edificios \n5) Aristas \n6) Regresar" << endl;
        cout << "opcion: ";
        cin >> opc;
        switch(opc){
            case 1:
                cout << "\n***Grupo***" << endl;
                logicActivationGroup();
                system("pause");
            break;
            case 2:
                cout << "\n***Periodo***" << endl;
                logicActivationPeriod();
                system("pause");
            break;
            case 3:
                cout << "\n***Asignaturas***" << endl;
                logicActivationSubject();
                system("pause");
            break;
            case 4:
                cout << "\n***Edificios**" << endl;
                logicActivationBuilding();
                system("pause");
            break;
            case 5:
                cout << "\n***Aristas**" << endl;
                logicActivationEdge();
                system("pause");
            break;
        }
    }while(opc != 6);
}

void SuperUser::logicActivationGroup()
{
    fstream myFile;
    std::string myCode;
    std::string myTempCode;
    std::string myName;
    std::string myDateBeg;
    std::string myDateFin;
    int myInt,flag=0;
    cin.ignore();

    cout << "Ingrese Codigo de Grupo" << endl;
    cin >> myInt;

    cin.ignore();
    myFile.open("Grupos.txt", std::ios::in | std::ios::out | std::ios::binary);

    if(!myFile.good()) {
        cout << "No se pudo abrir\n";
        }
    else {

        while(!myFile.eof()) {

            myFile.read((char*)&myGroup,sizeof(Group));

            if(myFile.eof()) {
                break;
                }

            if(to_string(myInt) == myGroup.getCode()) {

                myGroup.setCode(to_string(myInt));

                myGroup.setStatus("activo");

                myFile.seekp(size_t(myFile.tellg()) - sizeof(myGroup));

                myFile.write((char*)& myGroup, sizeof(myGroup));
                flag = 1;
                break;
                }
            }
        }
        if(flag == 1){
            cout << "Grupo Activo. . ." << endl;
        }
        else{
            cout << "Grupo No Existente O Ya Inactivado. . ." << endl;
        }

    myFile.close();
}

void SuperUser::logicActivationPeriod()
{
    fstream myFile;
    std::string myCode;
    std::string myTempCode;
    std::string myName;
    std::string myDateBeg;
    std::string myDateFin;
    int myInt,flag=0;
    cin.ignore();

    cout << "Ingrese Codigo de Periodo" << endl;
    cin >> myInt;

    cin.ignore();
    myFile.open("Periodos.txt", std::ios::in | std::ios::out | std::ios::binary);

    if(!myFile.good()) {
        cout << "No se pudo abrir\n";
        }
    else {

        while(!myFile.eof()) {

            myFile.read((char*)&myPeriod,sizeof(Period));

            if(myFile.eof()) {
                break;
                }

            if(to_string(myInt) == myPeriod.getCode()) {

                myPeriod.setCode(to_string(myInt));

                /*cout << "Ingrese Nuevo Nombre" << endl;
                getline(cin,myName);
                myPeriod.setName(myName);

                cout << "Ingrese Nueva Fecha de Inicio" << endl;
                getline(cin,myDateBeg);
                myPeriod.setDateBegin(myDateBeg);

                cout << "Ingrese Nueva Fecha de Fin" << endl;
                getline(cin,myDateFin);
                myPeriod.setDateFinish(myDateFin);*/

                myPeriod.setStatus("activo");

                myFile.seekp(size_t(myFile.tellg()) - sizeof(myPeriod));

                myFile.write((char*)& myPeriod, sizeof(myPeriod));
                flag = 1;
                break;
                }
            }
        }
        if(flag == 1){
            cout << "Periodo Activo. . ." << endl;
        }
        else{
            cout << "Periodo No Existente O Ya Inactivado. . ." << endl;
        }

    myFile.close();
}

void SuperUser::logicActivationSubject()
{
     fstream myFile;
    int myInt,flag=0;
    cin.ignore();

    cout << "Ingrese Codigo de Asignatura" << endl;
    cin >> myInt;

    cin.ignore();
    myFile.open("Asignaturas.txt", std::ios::in | std::ios::out | std::ios::binary);

    if(!myFile.good()) {
        cout << "No se pudo abrir\n";
        }
    else {

        while(!myFile.eof()) {

            myFile.read((char*)&mySubject,sizeof(Subject));

            if(myFile.eof()) {
                break;
                }

            if(to_string(myInt) == mySubject.getCode()) {

                mySubject.setCode(to_string(myInt));

                mySubject.setStatus("activo");

                myFile.seekp(size_t(myFile.tellg()) - sizeof(mySubject));

                myFile.write((char*)& mySubject, sizeof(mySubject));
                flag = 1;
                break;
                }
            }
        }
        if(flag == 1){
            cout << "Asignatura Activa. . ." << endl;
        }
        else{
            cout << "Asignatura No Existente O Ya Inactivada. . ." << endl;
        }

    myFile.close();
}

void SuperUser::logicActivationBuilding()
{
     bool encontrado = false;
    string myStr, myName, myCode, myDivision, myStatus;


    ofstream temp("Temporal.txt",ios::app);
    ifstream myFile("Edificios.txt");

    cout << "Ingrese el codigo del Edificio a Activar: ";
    cin >> myStr;

    while(!myFile.eof()){
        getline(myFile,myCode,'|');
        getline(myFile,myName,'|');
        getline(myFile,myDivision,'|');
        getline(myFile,myStatus,'|');

        if(myFile.eof()) break;

        if(myStr == myCode){
            encontrado = true;
            cin.ignore();

            myStatus = "activo";

            myBuilding.setExists(myStatus);
            myGraph.logicalVertexActivation(myName);

            temp << myCode << '|' << myName << '|' << myDivision << '|' << myStatus << '|';
        }
        else{
             temp << myCode << '|' << myName << '|' << myDivision << '|' << myStatus << '|';
        }
    }
    if(encontrado==false){
        cout << "Edificio No Existente O Ya activado. . ." << endl;
    }
    else{
        cout << "Edificio Activo!. . ." << endl;
    }

    myFile.close();
    temp.close();
    remove("Edificios.txt");
    rename("Temporal.txt","Edificios.txt");
}

void SuperUser::logicActivationEdge()
{
    cin.get();
     std::string myStr, myStr2;
    cout << "Inserte Origen: ";
    getline(cin,myStr);

    cout << "Inserte Destino: ";
    getline(cin,myStr2);

    myGraph.logicalEdgeActivation(myStr,myStr2);
}

bool SuperUser::existUser(const std::string& myStr)
{
    char name[100], code[100],myStr2[100];
    int n,c;
    strcpy(myStr2,myStr.c_str());

    ifstream myFile;
    myFile.open("Perfiles.txt",ios::in);

    if(!myFile.good()){
        ///Pendiente
    }
    else{
        while(!myFile.eof()){
            myFile.read((char*)&n,sizeof(int));
            myFile.read((char*)name,n);
            name[n]='\0';

            myFile.read((char*)&c,sizeof(int));
            myFile.read((char*)code,c);
            code[c]='\0';

            if((strcmp(myStr2,code)) == 0 ){
                return true;
            }
        }
        ///return false;
    }
    myFile.close();
    return false;

}

bool SuperUser::verifyDelete(const std::string& myStr)
{
    char name[100], code[100], password[100], id[100];
    int n,c,p,i;

    ifstream myFile;
    myFile.open("Usuarios.txt",ios::in);

    if(!myFile.good()){
        ///Pendiente
    }
    else{
        while(!myFile.eof()){
            myFile.read((char*)&n,sizeof(int));
            myFile.read((char*)name,n);
            name[n]='\0';

            myFile.read((char*)&c,sizeof(int));
            myFile.read((char*)code,c);
            code[c]='\0';

            myFile.read((char*)&p,sizeof(int));
            myFile.read((char*)password,p);
            password[p]='\0';

            myFile.read((char*)&i,sizeof(int));
            myFile.read((char*)id,i);
            id[i]='\0';

            if((strcmp(myStr.c_str(),id)) == 0){
                return true;
            }
        }
    }
    myFile.close();
    return false;
}

void SuperUser::writeToId(const int& id)
{
    ofstream myFile("IdUsuario.txt",ios::app);
    ofstream temp("Temporal.txt",ios::app);
    myFile << id << '|';
    temp << id << '|';

    myFile.close();
    temp.close();
    remove("IdUsuario.txt");
    rename("Temporal.txt","IdUsuario.txt");
}

int SuperUser::increaseUserId()
{
    std::string myCode;

    ifstream myFile;
    myFile.open("IdUsuario.txt",ios::in);

    if(!myFile.good()){
        return 0;
    }
    else{
        while(!myFile.eof()){

           getline(myFile,myCode,'|');

           if(myFile.eof()) break;

           return stoi(myCode);
        }
    }
    myFile.close();
    return 0;

}

int SuperUser::increaseGroupId()
{
    std::string myCode;

    ifstream myFile;
    myFile.open("IdGrupo.txt",ios::in);

    if(!myFile.good()){
        return 0;
    }
    else{
        while(!myFile.eof()){

           getline(myFile,myCode,'|');

           if(myFile.eof()) break;

           return stoi(myCode);
        }
    }
    myFile.close();
    return 0;

}

void SuperUser::writeToGroupId(const int& id)
{
    ofstream myFile("IdGrupo.txt",ios::app);
    ofstream temp("Temporal.txt",ios::app);
    myFile << id << '|';
    temp << id << '|';

    myFile.close();
    temp.close();
    remove("IdGrupo.txt");
    rename("Temporal.txt","IdGrupo.txt");
}

int SuperUser::increasePeriodId()
{
    std::string myCode;

    ifstream myFile;
    myFile.open("IdPeriodo.txt",ios::in);

    if(!myFile.good()){
        return 0;
    }
    else{
        while(!myFile.eof()){

           getline(myFile,myCode,'|');

           if(myFile.eof()) break;

           return stoi(myCode);
        }
    }
    myFile.close();
    return 0;
}

void SuperUser::writeToPeriodId(const int& id)
{
    ofstream myFile("IdPeriodo.txt",ios::app);
    ofstream temp("Temporal.txt",ios::app);
    myFile << id << '|';
    temp << id << '|';

    myFile.close();
    temp.close();
    remove("IdPeriodo.txt");
    rename("Temporal.txt","IdPeriodo.txt");
}

int SuperUser::increaseSubjectId()
{
    std::string myCode;

    ifstream myFile;
    myFile.open("IdAsignaturas.txt",ios::in);

    if(!myFile.good()){
        return 0;
    }
    else{
        while(!myFile.eof()){

           getline(myFile,myCode,'|');

           if(myFile.eof()) break;

           return stoi(myCode);
        }
    }
    myFile.close();
    cout << "Incrementando" <<endl;
    return 0;
}

void SuperUser::writeToSubjectId(const int& id)
{
    ofstream myFile("IdAsignaturas.txt",ios::app);
    ofstream temp("Temporal.txt",ios::app);
    myFile << id << '|';
    temp << id << '|';

    myFile.close();
    temp.close();
    remove("IdAsignaturas.txt");
    rename("Temporal.txt","IdAsignaturas.txt");
}

int SuperUser::increaseBuildingId()
{
     std::string myCode;

    ifstream myFile;
    myFile.open("IdEdificios.txt",ios::in);

    if(!myFile.good()){
        return 0;
    }
    else{
        while(!myFile.eof()){

           getline(myFile,myCode,'|');

           if(myFile.eof()) break;

           return stoi(myCode);
        }
    }
    myFile.close();
    cout << "Incrementando" <<endl;
    return 0;
}

void SuperUser::writeToBuildingId(const int& id)
{
    ofstream myFile("IdEdificios.txt",ios::app);
    ofstream temp("Temporal.txt",ios::app);
    myFile << id << '|';
    temp << id << '|';

    myFile.close();
    temp.close();
    remove("IdEdificios.txt");
    rename("Temporal.txt","IdEdificios.txt");
}

int SuperUser::increaseProfessorId()
{
    std::string myCode;

    ifstream myFile;
    myFile.open("IdProfesores.txt",ios::in);

    if(!myFile.good()){
        return 0;
    }
    else{
        while(!myFile.eof()){

           getline(myFile,myCode,'|');

           if(myFile.eof()) break;

           return stoi(myCode);
        }
    }
    myFile.close();

    return 0;
}

void SuperUser::writeToProfessorId(const int& id)
{
    ofstream myFile("IdProfesores.txt",ios::app);
    ofstream temp("Temporal.txt",ios::app);
    myFile << id << '|';
    temp << id << '|';

    myFile.close();
    temp.close();
    remove("IdProfesores.txt");
    rename("Temporal.txt","IdProfesores.txt");
}

bool SuperUser::verifyEmail(const std::string& email)
{
    auto beg=email.begin(), _end=email.end();

    if((beg=find(beg, _end, '@')) != _end && find(beg, _end, '.') != _end){
        return true;
    }
    return false;
}

void SuperUser::fromDiskToList()
{


    ifstream indexFile;
    indexFile.open("Indices.txt",ios::in);

    if(!indexFile.good()){
        ///cout << "Error";
    }
    else{
        while(!indexFile.eof()){
            indexFile.read((char *)&myIndex,sizeof(myIndex));

            if(indexFile.eof()){break;}
            ///Le manda todo el archivo de mascota a la lista
            ///if(myPet.getStatus() != 2 ){
                 myListIndex.insertData(myListIndex.getLastPos(), myIndex);
            ///}
        }

    }
    ///myList.quickSort();
    ///myListIndex.toString();
    ///system("pause");
    ///myList.deleteAll();
    indexFile.close();
}

void SuperUser::fromListToDisk()
{
    myListIndex.fromListToDisk();
}

void SuperUser::selfSaved()
{
     std::this_thread::sleep_for (std::chrono::milliseconds(1000));
     fromListToDisk();
     cout << "Archivos Autoguardados. . ." << endl;
     Sleep(2000);
    ///system("pause");
}

void SuperUser::parse()
{
    cin.get();
    std::string myStr1;

    cout<<"Ingresa un origen: ";
    getline(cin, myStr1);

    myGraph.parseInBreath(myStr1);

    myGraph.parseInDepth(myStr1);
}

void SuperUser::route()
{
    cin.get();
    std::string myStr1,myStr2;

    cout<<"Ingresa un origen: ";
    getline(cin, myStr1);

    cout<<"Ingresa un destino: ";
    getline(cin, myStr2);

    myGraph.routeInBreath(myStr1,myStr2);

    myGraph.routeInDepth(myStr1,myStr2);
}

void SuperUser::fromDiskToInvertList()
{

    ifstream careerFile("Carreras.txt", ios::in);
    if(!careerFile.good()) {
        //cout << "Error" << endl;
        }
    else {
        while(!careerFile.eof()) {
            careerFile.read((char*)&myCareer, sizeof(Career));
            if(careerFile.eof())
                break;

            myCareerList.InsertData(myCareerList.getLastPost(), myCareer);
            }
        }
    careerFile.close();
    remove("Carreras.txt");

    ifstream invertFile("ListaInvertida.txt", ios::in);
    if(!invertFile.good()) {
        //cout << "Error" << endl;
        }
    else {
        while(!invertFile.eof()) {
            invertFile.read((char*)&myInvert, sizeof(InvertData));
            if(invertFile.eof())
                break;

            myInvertList.inserData(myInvertList.getLastPos(), myInvert);
            }
        }
    invertFile.close();
    remove("ListaInvertida.txt");
}

bool SuperUser::subjectValid(const std::string& myStr)
{
    int flag=0;
    fstream myFile;
    myFile.open("Asignaturas.txt");
    myFile.seekg(ios::beg);
    if(!myFile.good()){
        cout << "Error";
    }
    else{
        while(!myFile.eof()){
            myFile.read((char *)&mySubject,sizeof(mySubject));

            if(myFile.eof()){break;}

                if(mySubject.getStatus() == "activo"){
                    if(myStr == mySubject.getCode()){
                        flag = 1;
                    }
                }
        }
    }
    myFile.close();
    if(flag==1){
        return true;
    }
    else{
        return false;
    }
}

bool SuperUser::teacherValid(const std::string& myStr)
{
    std::string myCode,myName,myEmail,myPhone;
    int flag=0;

    ifstream myFile;
    myFile.open("Maestros.txt",ios::in);

    if(!myFile.good()){
        cout << "Error";
    }
    else{
        while(!myFile.eof()){


           getline(myFile,myCode,'|');
           getline(myFile,myName,'|');
           getline(myFile,myEmail,'|');
           getline(myFile,myPhone,'|');

           if(myFile.eof()) break;

           if(myStr == myCode){
                flag = 1;
           }
        }
    }
    myFile.close();
    if(flag==1){
        return true;
    }
    else{
        return false;
    }
}

void SuperUser::increaseTable()
{
    int myInt;
    myHashing.increaseColumns();

    cout << "Ingrese el numero de Filas: ";
    cin >> myInt;
    myHashing.setColumns(myInt);

    cout << "Ingrese el numero de Columnas: ";
    cin >> myInt;
    myHashing.setRows(myInt);

    myHashing.drawFile();
    myHashing.retrieveDisponibility();

    cout << "Tabla Modificada A Su Conveniencia!" << endl;
}

string SuperUser::reatriveTeacher(const std::string& teacher)
{
    bool encontrado = false;
    string myStr, myName, myCode, myEmail, myPhone;

    ifstream myFile("Maestros.txt");

    while(!myFile.eof()){

        getline(myFile,myCode,'|');
        getline(myFile,myName,'|');
        getline(myFile,myEmail,'|');
        getline(myFile,myPhone,'|');

        if(myFile.eof()) break;

        if(teacher == myCode){
            encontrado = true;
            break;
        }
    }
    myFile.close();
    if(encontrado == true){
        return myName;
    }
    return "asdsad";
}

string SuperUser::reatriveSubject(const std::string& subject)
{
    fstream myFile;
    ifstream indexFile;
    std::string myStr;
    int flag = 0;
    cin.get();

    indexFile.open("Indices.txt");

    if(!indexFile.good()){
        cout << "Error";
    }
    else{
        while(!indexFile.eof()){
            indexFile.read((char*)&myIndex,sizeof(myIndex));

            if(indexFile.eof()) break;

            if(subject == myIndex.getIndexId()){
                    indexFile.close();

                    myFile.open("Asignaturas.txt");
                    myFile.seekp(myIndex.getIdxReference());
                    myFile.read((char *)&mySubject,sizeof(mySubject));
                    if(mySubject.getStatus() == "activo"){
                        flag = 1;
                        break;
                    }
                    else{
                        cout << "Asignatura Inactiva, Favor de Activarla Para Buscar. . ." << endl;
                        system("pause");
                    }
            }
        }
    myFile.close();
    }
    if(flag == 1){
            return mySubject.getName();
    }
    return "no";
}

string SuperUser::reatriveGroup(const std::string& myCode)
{
    std::string result;
    int flag=0;
    ifstream myFile;
    myFile.open("Grupos.txt", std::ios::binary | std::ios::in);

    if(!myFile.good()){
        cout << "Error";
    }
    else{
        while(!myFile.eof()){
            myFile.read((char *)&myGroup,sizeof(myGroup));

            if(myFile.eof()) {
                break;
                }
            ///cout << myCode << myGroup.getCode() << endl;
            if(myCode == myGroup.getCode()){
                    ///if(myGroup.getStatus() == "activo"){
                        result = myGroup.getName();
                        flag = 1;
                        break;
                    ///}
                    /*else{
                        cout << "Grupo Inactivo, Favor de Activar Para Buscar. . ." << endl;
                        system("pause");
                    }*/
            }
        }
    }
    myFile.close();
    if(flag==1){
            ///cout << "Grupo Inexistente" << endl;
            return result;
        }
        return "no";
}

void SuperUser::reatriveOfferGroup(const std::string& periodo,const std::string& carrera)
{
    std::string period, career, group, grade, subject, teacher,origen="0",anterior="0";
    ifstream myFile;
    myFile.open("Auxiliar.txt",ios::in);

    if(!myFile.good()){
        cout << "Error";
    }
    else{
        while(!myFile.eof()){

           getline(myFile,period,'|');
           getline(myFile,career,'|');
           getline(myFile,group,'|');
           getline(myFile,grade,'|');
           getline(myFile,subject,'|');
           getline(myFile,teacher,'|');

           if(myFile.eof()) break;

            if(period == periodo && career == carrera){
                if(anterior!=grade){
                    anterior=grade;
                    if(origen!=group){
                    cout << "\tGrupo: " << group <<"-"<<grade << endl;
                    origen=group;
                    }
                    else{
                    cout << "\tGrupo: " << group <<"-"<<grade << endl;
                    origen=group;
                    }
                }

               ///cout << "\t\tMateria: " << reatriveSubject(subject);
               ///cout << "\tImpartida Por El Maestro: " << reatriveTeacher(teacher) << endl;

            }
        }
    }
    myFile.close();
}

bool SuperUser::verifyTeacher(const std::string& myStr)
{
    bool encontrado = false;
    string myName, myCode, myEmail, myPhone;

    ifstream myFile("Maestros.txt");

    while(!myFile.eof()){

        getline(myFile,myCode,'|');
        getline(myFile,myName,'|');
        getline(myFile,myEmail,'|');
        getline(myFile,myPhone,'|');

        if(myFile.eof()) break;

        if(myStr == myName){
            encontrado = true;
            break;
        }
    }
    myFile.close();
    if(encontrado == true){
        return true;
    }
    return false;
}

bool SuperUser::verifySubject(const std::string& myStr)
{
    fstream myFile;
    ifstream indexFile;
    bool flag = false;
    cin.get();

    indexFile.open("Indices.txt");

    if(!indexFile.good()){
        cout << "Error";
    }
    else{
        while(!indexFile.eof()){
            indexFile.read((char*)&myIndex,sizeof(myIndex));

            if(indexFile.eof()) break;

            if(myStr == myIndex.getIndexId()){
                    indexFile.close();

                    myFile.open("Asignaturas.txt");
                    myFile.seekp(myIndex.getIdxReference());
                    myFile.read((char *)&mySubject,sizeof(mySubject));
                    if(mySubject.getStatus() == "activo"){
                        flag = true;
                        break;
                    }
                    else{
                        flag = false;
                    }
            }
        }
    myFile.close();
    }
    if(flag == true){
            return true;
    }
    return false;
}

bool SuperUser::verifyGroup(const std::string& myStr)
{
     std::string result;
    bool flag = false;
    ifstream myFile;
    myFile.open("Grupos.txt", std::ios::binary | std::ios::in);

    if(!myFile.good()){
        cout << "Error";
    }
    else{
        while(!myFile.eof()){
            myFile.read((char *)&myGroup,sizeof(myGroup));

            if(myFile.eof()) {
                break;
                }
            ///cout << myCode << myGroup.getCode() << endl;
            if(myStr == myGroup.getCode()){
                    if(myGroup.getStatus() == "activo"){
                        result = myGroup.getName();
                        flag = true;
                        break;
                    }
                    else{
                        flag=false;
                    }
            }
        }
    }
    myFile.close();
    if(flag==true){
            ///cout << "Grupo Inexistente" << endl;
            return true;
        }
        return false;
}

int SuperUser::showSpecificSubject(const std::string& name, int grade)
{
    int cont=0;
    ifstream myFile;
    myFile.open("Asignaturas.txt");
    myFile.seekg(ios::beg);
    if(!myFile.good()){
        cout << "Error";
    }
    else{
        while(!myFile.eof()){
            myFile.read((char *)&mySubject,sizeof(mySubject));

            if(myFile.eof()){break;}

                if(mySubject.getProgram() == name && mySubject.getGroup() == to_string(grade)){
                    cout << "Codigo: " << mySubject.getCode();
                    ///cout << "Creditos: " << mySubject.getCredit() << endl;
                    cout << "\tNombre: " << mySubject.getName() << endl << endl;
                    ///cout << "Carrera: " << mySubject.getProgram() << endl << endl;
                    cont++;
                }
        }
    }
    myFile.close();
    return cont;
}

void SuperUser::showSpecificOfferSubject(const std::string& name, const std::string& grade)
{
    ifstream myFile;
    myFile.open("Asignaturas.txt");
    myFile.seekg(ios::beg);
    if(!myFile.good()){
        cout << "Error";
    }
    else{
        while(!myFile.eof()){
            myFile.read((char *)&mySubject,sizeof(mySubject));

            if(myFile.eof()){break;}

                if(mySubject.getProgram() == name && mySubject.getGroup() == grade){
                    cout << "Codigo: " << mySubject.getCode();
                    cout << "\tNombre: " << mySubject.getName() << endl << endl;
                }
        }
    }
    myFile.close();
}

void SuperUser::reatriveDisponibility(const std::string& name)
{
    myHashing.showTeacher(name);
}
