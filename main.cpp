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

#include "Cubo.h"

using namespace std;

/*
 * 
 */
Cubo* cubo_disperso = new Cubo();

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

string abrir_archivo(string direccion) {
    string cadena = "";
    ifstream fe(direccion);
    while (!fe.eof()) {
        string linea = "";
        getline(fe, linea);
        cadena = cadena + linea;
    }
    fe.close();
    return cadena;
}

Capa* crear_capa(string cadena) {

    int x = 1;
    int y = 1;
    string color = "";
    cadena = cadena + "\r";
    Capa* capa = new Capa("Body");
    for (int i = 0; i < cadena.size(); i++) {
        while (cadena[i] != '\r') {
            
            while (cadena[i] != ',') {
                color = color + cadena[i];
                i++;
                if(cadena[i] == '\r'){
                    break;
                }
            }
            if(cadena[i] == ','){
                i++;
            }
            capa->insertar_nodo(y,x,color);
            x++;
            color = "";
        }
        x=1;
        y++;
    }
    capa->imprimir();
}

void principal() {
    int opcion = -1;

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

    string dirs;
    cin>>dirs;
    string cadenas;
    cadenas = abrir_archivo(dirs);
    crear_capa(cadenas);
    
}

int main(int argc, char** argv) {
    principal();
    return 0;
}

