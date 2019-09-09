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
#include "Generador_Imagen.h"
#include "Arbol_ABB.h"

using namespace std;

/*
 * 
 */
Cubo* cubo_disperso = new Cubo();
Arbol_ABB* abb = new Arbol_ABB();

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
                if (cadena[i] == '-') {
                    cadena[i] = ',';
                }
                color = color + cadena[i];
                i++;
                if (cadena[i] == '\r') {
                    break;
                }
            }
            if (cadena[i] == ',') {
                i++;
            }
            capa->insertar_nodo(y, x, color);
            x++;
            color = "";
        }
        x = 1;
        y++;
    }
    return capa;
}

void menu_seleccionar_imagen() {

}

Cubo* crear_cubo(string config) {
    int i = 0;
    int index = 0;
    int iw, ih,pw,ph;
    iw = ih = pw = ph = 0;
    string cantidad = "";
    config = config + "\r";
    while(i < config.size()){
        
        if (config[i] == '\r') {i++;break;}
        
        while (config[i] != ',') {
            i++;
        }
        if (config[i] == ',') {
            i++;
        }
        
        while(config[i] != '\r'){
          cantidad = cantidad + config[i];
            i++;
        }
        if (config[i] == '\r') {i++;}
        if(index == 1){ iw = es_entero(cantidad);}
        if(index == 2){ ih = es_entero(cantidad);}
        if(index == 3){ pw = es_entero(cantidad);}
        if(index == 4){ ph = es_entero(cantidad);}
        index++;
        cantidad = "";
    }
    Cubo* cubo = new Cubo("",pw,ph,iw,ih);
    return cubo;
}

void menu_insertar_imagen() {
    Cubo* cubo = new Cubo();
    cout << "[************************************************]" << endl;
    cout << "BIENVENIDO AL SISTEMA PHOTOGEN++" << endl;
    cout << "[************************************************]" << endl;
    cout << "Ingrese el nombre del archivo [Sin extencion (sin el .csv)]" << endl;
    cout << "-->";
    string nombre;
    cin>>nombre;
    string direccion = "";
    direccion = nombre + ".csv";
    string init = abrir_archivo(direccion);
    init = init + "\r";
    int i = 0;
    int index = -1;
    string n_capa = "";
    while (i < init.size()) {
        
        if (init[i] == '\r') {
            i++;
            break;
        }
        while (init[i] != ',') {
            i++;
        }
        if (init[i] == ',') {
            i++;
        }
        while (init[i] != '\r') {
            n_capa = n_capa + init[i];
            i++;
        }
        if (init[i] == '\r') {
            i++;
        }
        
        if(index == 0){
            cubo =  crear_cubo(abrir_archivo(n_capa));
            cubo->nombre = nombre;
        }
        
        if (index > 0) {
            Capa* tmp = new Capa(n_capa);
            tmp = crear_capa(abrir_archivo(n_capa));
            cubo->insertar_capa(tmp);
        }
        index++;
        n_capa = "";
    }
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

        string op;
        cin>>op;
        opcion = es_entero(op);
        switch (opcion) {
            case 1:
                menu_insertar_imagen();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 0:
                opcion = 0;
                break;
            default:
                cout << "opcion incorrecta" << endl;
                break;
        }

    }

}

int main(int argc, char** argv) {
    principal();
    return 0;
}

