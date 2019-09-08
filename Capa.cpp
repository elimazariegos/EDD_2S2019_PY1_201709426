/* 
 * File:   Capa.cpp
 * Author: Samuel
 * 
 * Created on 6 de septiembre de 2019, 09:40 PM
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

#include "Capa.h"

Capa::Capa() {
}

Capa::Capa(string nombre_) {
    cabecera = new Nodo_Capa();
    cabecera->fila = cabecera->columna = 0;
    cabecera->sig = cabecera->ant = cabecera->abajo = cabecera->arriba = 0;
    max_columna = 0;
    max_fila = 0;
    nombre = nombre_;
}

bool Capa::esta_vacia(){return cabecera ==0;}

Nodo_Capa* Capa::exist_fila(int y){
    if(esta_vacia()){return 0;}
    else{
        Nodo_Capa* aux = cabecera;
        while(aux != 0){if(aux->fila == y){return aux;}
            aux = aux->abajo;
        }
    }
}
Nodo_Capa* Capa::exist_columna(int x){
    if(esta_vacia()){return 0;}
    else{
        Nodo_Capa* aux = cabecera;
        while(aux != 0){if(aux->columna == x){return aux;}
            aux = aux->sig;
        }
    }
}

Nodo_Capa* Capa::crear_fila(int y){
    Nodo_Capa* tmp = cabecera;
    while(tmp->abajo !=0){tmp = tmp->abajo;}
    for(int i = max_fila; i < y; i++){
        Nodo_Capa* nuevo = new Nodo_Capa(i + 1, 0, "");
        nuevo->abajo = nuevo->sig = nuevo->ant = 0;
        tmp->abajo = nuevo;
        nuevo->arriba = tmp;
        tmp = nuevo;
    }
    max_fila = y;
    return tmp;
}
Nodo_Capa* Capa::crear_columna(int x) {
    Nodo_Capa* tmp = cabecera;
    while (tmp->sig != 0) {tmp = tmp->sig;}
    for (int i = max_columna; i < x; i++) {
        Nodo_Capa* nuevo = new Nodo_Capa(0, i + 1, "");
        nuevo->sig = nuevo->abajo = nuevo->arriba = 0;
        tmp->sig = nuevo;
        nuevo->ant = tmp;
        tmp = nuevo;
    }
    max_columna = x;
    return tmp;
}
void Capa::insertar_nodo(int y, int x, string color){
    Nodo_Capa* nuevo = new Nodo_Capa(y, x, color);
    Nodo_Capa* fila_b = exist_fila(y);
    Nodo_Capa* columna_b = exist_columna(x);

    if (fila_b == 0) { fila_b = crear_fila(y);}
    if (columna_b == 0) { columna_b = crear_columna(x);}
   
    Nodo_Capa* tmp = fila_b;
    
    while (tmp != 0) {
        if (tmp->columna > x) {
            tmp = tmp->ant;
            break;
        } else {
            if (tmp->sig == 0) {
                break;
            } else {
                tmp = tmp->sig;
            }
        }
    }
    nuevo->ant = tmp;
    nuevo->sig = tmp->sig;
    if (tmp->sig != 0) {
        tmp->sig->ant = nuevo;
    }
    tmp->sig = nuevo;
    
    tmp = columna_b;
    while (tmp != 0) {
        if (tmp->fila > y) {
            tmp = tmp->arriba;
            break;
        } else {
            if (tmp->abajo == 0) {
                break;
            } else {
                tmp = tmp->abajo;
            }
        }
    }
    nuevo->arriba = tmp;
    nuevo->abajo = tmp->abajo;
    if (tmp->abajo != 0) {
        tmp->abajo->arriba = nuevo;
    }
    tmp->abajo = nuevo;
}
void Capa::imprimir(){
    if(!esta_vacia()){
        Nodo_Capa* aux  = cabecera;
        while(aux != 0){
            Nodo_Capa* aux1 = aux;
            while(aux1 != 0){
                cout <<" "<< aux1->color<<" ["<<aux1->fila<<","<<aux1->columna<<"]";
                aux1 = aux1->sig;
            }
            aux = aux->abajo;
            cout<<""<<endl;
        }
    }
}