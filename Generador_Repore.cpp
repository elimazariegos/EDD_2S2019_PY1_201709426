/* 
 * File:   Generador_Repore.cpp
 * Author: Samuel
 * 
 * Created on 17 de septiembre de 2019, 02:19 PM
 */

#include "Generador_Repore.h"
#include "Generador_Imagen.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<windows.h>
#include<sstream>
#include<string>


Generador_Repore::Generador_Repore() {
}
void Generador_Repore::recorrer_arbol_imagen(Nodo_ABB* tmp){
    if(tmp != 0){
        recorrer_arbol_imagen(tmp->izquierdo);
        string label = "<f0>|<f1>" + to_string(tmp->cubo->nombre) + "|<f2>";
        texto = texto + "capa" + to_string(tmp->cubo->nombre) + "[label= \"" + label + "\"];" + "\n";
        if (tmp->derecho != 0) {
            texto = texto + "\"capa" + to_string(tmp->cubo->nombre) + "\":f2 -> \"capa" + to_string(tmp->derecho->cubo->nombre) + "\":f1;\n";
        }
        if (tmp->izquierdo != 0) {
            texto = texto + "\"capa" + to_string(tmp->cubo->nombre) + "\":f0 -> \"capa" + to_string(tmp->izquierdo->cubo->nombre) + "\":f1;\n";
        }
        recorrer_arbol_imagen(tmp->derecho);
    }
}
void Generador_Repore::imported_image_report(Nodo_ABB* tmp){
    ofstream file;
    file.open("im_img_rep.dot");
    texto = "digraph g{\n";
    texto = texto + "node [shape = record, heigth=.1];\n";
    recorrer_arbol_imagen(tmp);
    file << texto << endl;
    file << "}" << endl;
    system("dot -Tpng im_img_rep.dot -o im_img_rep.png");
    string titulo = "im_img_rep.png";
    ShellExecute(NULL, "open", titulo.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

