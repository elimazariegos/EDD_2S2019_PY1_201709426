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


class Generador_Imagen {
public:
    Generador_Imagen();
    void generar_imagen(Cubo* cubo, int ph, int pw, int iw , int ih);
private:

};

#endif	/* GENERADOR_IMAGEN_H */

