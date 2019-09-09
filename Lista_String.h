/* 
 * File:   Lista_String.h
 * Author: Samuel
 *
 * Created on 9 de septiembre de 2019, 12:35 AM
 */

#ifndef LISTA_STRING_H
#define	LISTA_STRING_H

#include "Nodo_String.h"

#include <cstdlib>
#include<sstream>
#include<stdlib.h>
#include<iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <cstring>

using namespace std;
class Lista_String {
public:
    Nodo_String* cabeza = 0;
    int size = 0;
    Lista_String();
    bool esta_vacia();
    void insertar(string dato);
    string buscar(int index);
private:

};

#endif	/* LISTA_STRING_H */

