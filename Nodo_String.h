/* 
 * File:   Nodo_String.h
 * Author: Samuel
 *
 * Created on 9 de septiembre de 2019, 12:35 AM
 */

#ifndef NODO_STRING_H
#define	NODO_STRING_H
#include <cstdlib>
#include<sstream>
#include<stdlib.h>
#include<iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <cstring>

using namespace std;

class Nodo_String {
public:
    Nodo_String* sig = 0;
    string dato = "";
    int index = 0;
    Nodo_String();
private:

};

#endif	/* NODO_STRING_H */

