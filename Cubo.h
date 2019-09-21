/* 
 * File:   Cubo.h
 * Author: Samuel
 *
 * Created on 6 de septiembre de 2019, 11:10 PM
 */

#ifndef CUBO_H
#define	CUBO_H

#include "Nodo_Cubo.h"

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<windows.h>
#include<sstream>
#include<string>
using namespace std;
class Cubo {
public:
    Cubo();
    Cubo(string nombre_, int pixel_w_, int pixel_h_, int imagen_w_, int imagen_h_);
    Nodo_Cubo* cabeza = 0;
    string nombre;
    int fila_mayor = 0;
    int columna_mayor = 0;
    int size = 0;
    int pixel_w = 0;
    int pixel_h = 0;
    int imagen_w = 0;
    int imagen_h = 0;
    bool esta_vacia();
    void insertar_capa(Capa* capa_);
    Capa* buscar(string nombre);
    Capa* buscar_index(int index_);
    void modificar(int x, int y, string capa, int r, int g, int b);
    
   template <typename T>
    string to_string(T n) {
        ostringstream os;
        os << n;
        return os.str();
    }
    
    
private:

};

#endif	/* CUBO_H */

