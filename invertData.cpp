#include "invertData.h"

string InvertData::getCode() {
    return code;
    }

int InvertData::getLabel() {
    return label;
    }

void InvertData::setCode(const string& e) {
    strcpy(code,e.c_str());
    }

void InvertData::setLabel(const int& e) {
     label = e;
    }

/*string InvertData::toString() {
    string result;

    char auxSQU[11], auxLabel[11];

    sprintf(auxSQU, "%d", squ);
    sprintf(auxLabel, "%d", label);

    result = "\n SQU: " + string(auxSQU) + "\n";
    result = "Posicion de Genero: " + string(auxLabel) + "\n";

    return result;
    }*/
