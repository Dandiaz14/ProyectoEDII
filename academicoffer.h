#ifndef ACADEMICOFFER_H_INCLUDED
#define ACADEMICOFFER_H_INCLUDED

#include <string.h>
#include <iostream>
using namespace std;

class AcademicOffer {
    private:
        char period[15];  ///Nombre del periodo
        char career[25];  ///Nombre de la Carrera
        char groups[5];   ///Cuantos grupos pide para insertar
        ///char subject[5];  ///Llave para buscar en materias e insertarla en un nuevo archivo
        ///char teacher[5];  ///Llave para buscar en maestros e insertarlo en un nuevo archivo


    public:
        std::string getPeriod();
        std::string getCareer();
        std::string getGroups();
        ///std::string getSubject();
        ///std::string getTeacher();

        void setPeriod(const std::string&);
        void setCareer(const std::string&);
        void setGroups(const std::string&);
        ///void setSubject(const std::string&);
        ///void setTeacher(const std::string&);
};



#endif // ACADEMICOFFER_H_INCLUDED
