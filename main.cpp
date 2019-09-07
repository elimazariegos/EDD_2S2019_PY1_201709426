/* 
 * File:   main.cpp
 * Author: Samuel
 *
 * Created on 2 de septiembre de 2019, 10:20 PM
 */
#include <cstdlib>
#include<sstream>
#include<stdlib.h>
#include<iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <cstring>
using namespace std;

/*
 * 
 */
int es_entero(string ent) {
    int i = 0;
    string aux = "";
    while (i < ent.size()) {
        if (ent[i] > 47 and ent[i] < 58) {
            aux = aux + ent[i];
        } else {
            return -1;
        }
        i++;
    }
    i = atoi(aux.c_str());
    return i;
}

void principal() {
    int opcion = -1;
    while (opcion != 0) {

        cout << "[************************************************]" << endl;
        cout << "BIENVENIDO AL SISTEMA PHOTOGEN++" << endl;
        cout << "[************************************************]" << endl;
        cout << "[1] Insertar Imagen" << endl;
        cout << "[2] Seleccionar Imagen" << endl;
        cout << "[3] Aplicar Filtros" << endl;
        cout << "[4] Edicion Manual" << endl;
        cout << "[5] Exportar Imagen" << endl;
        cout << "[6] Reportes" << endl;
        cout << "[************************************************]" << endl;
        cout << "Seleccione una opcion" << endl;
        cout << "-->";

    }
}

int main(int argc, char** argv) {
    principal();
    return 0;
}

