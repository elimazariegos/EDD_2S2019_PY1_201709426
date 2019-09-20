/* 
 * File:   Nodo_Capa.cpp
 * Author: Samuel
 * 
 * Created on 6 de septiembre de 2019, 09:14 PM
 */

#include "Nodo_Capa.h"

#include <cstdlib>
#include<sstream>
#include<stdlib.h>
#include<iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <cstring>
using namespace std;

Nodo_Capa::Nodo_Capa() {
}

Nodo_Capa::Nodo_Capa(int fila_, int columna_, string color_) {
    this->fila = fila_;
    this->columna = columna_;
    this->color = color_;

    if (color_ != "x" and color_ !="") {
        int i = 0;
        string rgb = "";
        while (color_[i] != ',') {
            rgb = rgb + color_[i];
            i++;
        }
        i++;
        this->r = atoi(rgb.c_str());
        rgb = "";
        while (color_[i] != ',') {
            rgb = rgb + color_[i];
            i++;
        }
        i++;
        this->g = atoi(rgb.c_str());
        rgb = "";
        while (i < color_.size()) {
            rgb = rgb + color_[i];
            i++;
        }
        this->b = atoi(rgb.c_str());
    }
    
}

