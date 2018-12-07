#include "menu.h"
#include "superuser.h"
#include "teacherMenu.h"

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <limits>
#include <vector>
#include <conio.h>

SuperUser mySuperUser;
TeacherMenu menuTeacher;

int Menu::login(){
    string user, password;
    int check;
    ///int attemps = 5;
    system("cls");
    cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t-------------------" << endl;
    cout << "\t\t\t\t\t\t******LOG IN******" << endl;
    cout << "\t\t\t\t\t\tUsuario: ";
    getline(cin,user);
    cout << "\t\t\t\t\t\tPassword: ";

    char carac;
    carac = getch();
    password = "";

    while(carac != 13){
        if(carac != 8){
            password.push_back(carac);
            cout << "*";
        }
        else{
            if(password.length() > 0){
                cout << "\b \b";
                password = password.substr(0, password.length() - 1);
            }
        }
        carac = getch();
    }

    check = verifyLogin(user,password);
    ///strcpy(check,verifyLogin(user,password));

    if(user == "admin" && password == "admin123"){
        mySuperUser.adminMenu();
        return 1;
    }
    else if(check == 1){
        mySuperUser.adminMenu();
        return 1;
    }
    else if(check == 2){
        system("cls");
        menuTeacher.coordinatorMenu(user);
        system("pause");
        return 1;
    }
    else if(check == 3){
        system("cls");
        menuTeacher.asistentMenu(user);
        system("pause");
        return 1;
    }
    else if(check == 4){
        menuTeacher.teacherMenu(user);
        system("cls");
        return 1;
    }
    else{
        ///_attemps-1;
        cout << endl;
        cout << "\n\n\t\t\t\t\tUsuario o Password Equivocado" << endl;
        ///cout << "\t\t\t\t\tUsted Solo Tiene: " << _attemps << " Intentos" << endl;
        cin.ignore();
        system("cls");
        login();
    }
    return 0;
}

int Menu::verifyLogin(const std::string& keyUser, const std::string& keyPassword)
{
    char name[100], code[100], password[100], id[100], myStr[100], myStr2[100];
    int n,c,p,i;
    bool flag = false;
    strcpy(myStr,keyUser.c_str());
    strcpy(myStr2,keyPassword.c_str());

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

            if((strcmp(myStr,name)) == 0 && (strcmp(myStr2,password) == 0) &&  (strcmp(id,"1"))== 0 ){
                return 1;
                flag = true;
            }
            else if((strcmp(myStr,name)) == 0 && (strcmp(myStr2,password) == 0) &&  (strcmp(id,"2"))== 0 ){
                return 2;
                flag = true;
            }
            else if((strcmp(myStr,name)) == 0 && (strcmp(myStr2,password) == 0) &&  (strcmp(id,"3"))== 0 ){
                return 3;
                flag = true;
            }
            else if((strcmp(myStr,name)) == 0 && (strcmp(myStr2,password) == 0) &&  (strcmp(id,"4"))== 0 ){
                return 4;
                flag = true;
            }
        }
        if(flag == false){
            return 0;
        }
    }
    myFile.close();
    return 0;

}

void Menu::mainMenu()
{
    login();
}

