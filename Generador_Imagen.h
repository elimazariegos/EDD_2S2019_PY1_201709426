/* 
 * File:   Generador_Imagen.h
 * Author: Samuel
 *
 * Created on 8 de septiembre de 2019, 01:13 AM
 */

#ifndef GENERADOR_IMAGEN_H
#define	GENERADOR_IMAGEN_H
#include "Cubo.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<windows.h>
#include<sstream>
#include<string>

using namespace std;

class Generador_Imagen {
public:
    
    ofstream file_html;
    ofstream file_css ;
    int index_mosacio = 1;
    int ph  = 0, pw = 0, iw = 0, ih = 0;
    
    Generador_Imagen();
    string convertir_rgb(string color1,string color2);
 
    template <typename T>
string to_string(T n) {
    ostringstream os;
    os << n;
    return os.str();
}

    void generar_imagen(Cubo* cubo, string filtro);
    string generar_mosaico(Cubo* cubo, string matriz);
private:

};

#endif	/* GENERADOR_IMAGEN_H */

