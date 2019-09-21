/* 
 * File:   Generador_Repore.cpp
 * Author: Samuel
 * 
 * Created on 17 de septiembre de 2019, 02:19 PM
 */

#include "Generador_Repore.h"
#include "Generador_Imagen.h"
#include "Arbol_ABB.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<windows.h>
#include<sstream>
#include<string>

Generador_Repore::Generador_Repore() {
}

Capa* Generador_Repore::clone(Nodo_Capa* tmp) {
    Capa* capa = new Capa("clone");
    Nodo_Capa* aux = tmp->abajo;
    while (aux != 0) {
        Nodo_Capa* aux_c = aux->sig;
        while (aux_c != 0) {
            if (aux_c->color != "x") {
                capa->insertar_nodo(aux_c->fila, aux_c->columna, aux_c->color);
            }
            aux_c = aux_c->sig;
        }
        aux = aux->abajo;
    }
    return capa;
}

void Generador_Repore::linealizacion_filas(Nodo_Capa* tmp) {
    Capa* capa = new Capa("clon");
    capa = clone(tmp);
    ofstream file;
    file.open("linealizacion_filas.dot");
    file << "digraph Grafica{\nrankdir=LR;" << endl;
    file << "node[shape=box]" << endl;
    file << "Cabecera [with=1.5];";

    Nodo_Capa * aux = capa->cabecera;
    aux = aux->sig;
    int i = 0;

    file << "Cabecera->f0" << endl;
    while (aux != 0) {
        Nodo_Capa* aux_c = aux->abajo;
        while (aux_c != 0) {
            file << "f" << i << "[label=\"" << "(" << aux_c->fila << "," << aux_c->columna << ") " << aux_c->color << "\"]" << endl;
            if (aux_c->abajo != 0) {
                file << "f" << i << "->f" << i + 1 << endl;
            }
            i++;
            aux_c = aux_c->abajo;
        }
        aux = aux->sig;
        if (aux != 0) {
            if (i - 1 >= 0) {
                file << "f" << i - 1 << "->f" << i << endl;
            }
        }
    }

    file << "}" << endl;




    system("dot -Tpng linealizacion_filas.dot -o linealizacion_filas.png");
    string title = "linealizacion_filas.png";
    ShellExecute(NULL, "open", title.c_str(), NULL, NULL, SW_SHOWNORMAL);

}

void Generador_Repore::linealizacion_columnas(Nodo_Capa* tmp) {
    Capa* capa = new Capa("clone");
    ofstream file;
    file.open("linealizacion_columnas.dot");
    file << "digraph Grafica{\nrankdir=LR;" << endl;
    file << "node[shape=box]" << endl;
    file << "Cabecera [with=1.5];";


    capa = clone(tmp);
    Nodo_Capa * aux = capa->cabecera;
    aux = aux->abajo;
    int i = 0;

    file << "Cabecera->f0" << endl;
    while (aux != 0) {
        Nodo_Capa* aux_c = aux->sig;
        while (aux_c != 0) {
            file << "f" << i << "[label=\"" << "(" << aux_c->fila << "," << aux_c->columna << ") " << aux_c->color << "\"]" << endl;
            if (aux_c->sig != 0) {
                file << "f" << i << "->f" << i + 1 << endl;
            }
            i++;
            aux_c = aux_c->sig;
        }
        aux = aux->abajo;
        if (aux != 0) {
            if (i - 1 >= 0) {
                file << "f" << i - 1 << "->f" << i << endl;
            }
        }
    }

    file << "}" << endl;


    system("dot -Tpng linealizacion_columnas.dot -o linealizacion_columnas.png");
    string title = "linealizacion_columnas.png";
    ShellExecute(NULL, "open", title.c_str(), NULL, NULL, SW_SHOWNORMAL);

}

void Generador_Repore::recorrer_arbol_imagen(Nodo_ABB* tmp) {
    if (tmp != 0) {
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

void Generador_Repore::imported_image_report(Nodo_ABB* tmp) {
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

void Generador_Repore::generar_capa(Nodo_Capa* tmp) {
    ofstream file;
    Capa* capa = new Capa("report");

    file.open("ca.dot");
    file << "digraph Grafica{" << endl;
    file << "node[shape=box]" << endl;
    file << "Cabecera [with=1.5, style=filled, fillcolor=green, group= 1];";

    file << "e0[shape=point, width= 0];";
    file << "e1[shape=point, width= 0];";

    Nodo_Capa* aux = tmp;

    capa = clone(tmp);
    aux = capa->cabecera;
    aux = aux->abajo;
    while (aux != 0) {
        file << "f" << aux->fila << "[label=\"" << aux->fila << "\"width = 1.5 style=filled, fillcolor=gray, group= 0 ]" << endl;
        if (aux->abajo != 0) {
            file << "f" << aux->abajo->fila << "[label=\"" << aux->abajo->fila << "\"width = 1.5 style=filled, fillcolor=gray, group= 0 ]" << endl;


            file << "f" << aux->fila << "->f" << aux->abajo->fila << endl;
            file << "f" << aux->abajo->fila << "->f" << aux->fila << endl;

        }
        aux = aux->abajo;
    }

    aux = capa->cabecera->sig;
    while (aux != 0) {
        file << "c" << aux->columna << "[label=\"" << aux->columna << "\"width = 1.5 style=filled, fillcolor=gray, group= " << aux->columna << " ]" << endl;
        if (aux->sig != 0) {
            file << "c" << aux->sig->columna << "[label=\"" << aux->sig->columna << "\"width = 1.5 style=filled, fillcolor=gray, group= " << aux->sig->columna << " ]" << endl;

            file << "c" << aux->columna << "->c" << aux->sig->columna << endl;
            file << "c" << aux->sig->columna << "->c" << aux->columna << endl;

        }
        aux = aux->sig;
    }
    aux = capa->cabecera->abajo;

    while (aux != 0) {
        Nodo_Capa* t = aux->sig;
        while (t != 0) {

            file << "F" << t->fila << "_C" << t->columna << "[width = 1.5 style=filled, fillcolor=gray, group= " << t->columna << ", rank = f" << t->fila << ";]" << endl;
            file << "F" << t->fila << "_C" << t->columna << "[label=\"" << t->color << "\"]" << endl;
            if (t->sig != 0) {
                file << "F" << t->fila << "_C" << t->columna << "->" << "F" << t->sig->fila << "_C" << t->sig->columna << endl;
            }
            if (t->abajo != 0) {
                file << "F" << t->fila << "_C" << t->columna << "->" << "F" << t->abajo->fila << "_C" << t->abajo->columna << endl;
            }
            if (t->arriba != 0 and t->arriba->fila) {
                file << "F" << t->fila << "_C" << t->columna << "->" << "F" << t->arriba->fila << "_C" << t->arriba->columna << endl;
            }
            if (t->ant != 0 and t->ant->columna != 0) {
                file << "F" << t->fila << "_C" << t->columna << "->" << "F" << t->ant->fila << "_C" << t->ant->columna << endl;
            }
            if (t->ant->columna == 0) {
                file << "f" << t->ant->fila << "->F" << t->fila << "_C" << t->columna << endl;
                file << "F" << t->fila << "_C" << t->columna << "->" << "f" << t->ant->fila << endl;
            }
            if (t->arriba->fila == 0) {
                file << "c" << t->arriba->columna << "->F" << t->fila << "_C" << t->columna << endl;
                file << "F" << t->fila << "_C" << t->columna << "->" << "c" << t->arriba->columna << endl;
            }

            t = t->sig;
        }
        aux = aux->abajo;
    }

    aux = capa->cabecera->abajo;
    while (aux != 0) {
        file << "{rank = same f" << aux->fila << ";";
        Nodo_Capa* t = aux->sig;
        while (t != 0) {
            file << "F" << t->fila << "_C" << t->columna << ";";
            t = t->sig;
        }
        file << "}";
        aux = aux->abajo;
    }
    file << "{rank = same;Cabecera;" << endl;
    aux = capa->cabecera->sig;
    while (aux != 0) {
        file << "c" << aux->columna << ";";
        aux = aux->sig;
    }
    file << "}" << endl;

    file << "Cabecera->f1" << endl;
    file << "Cabecera->c1" << endl;
    file << "}" << endl;

    system("dot -Tpng ca.dot -o ca.png");
    string title = "ca.png";
    ShellExecute(NULL, "open", title.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

void Generador_Repore::transversal_report(Arbol_ABB* abb, int recorrido) {
    ofstream file;
    file.open("transversal_report.dot");
    file << "digraph Grafica{\nrankdir=LR;" << endl;
    file << "node[shape=box]" << endl;

    if (recorrido == 1) {
        file << " INORDER [with=1.5];";
        recorrer_in_order(abb->raiz);
    } else if (recorrido == 2) {
        file << " PREORDER [with=1.5];";
        recorrer_pre_order(abb->raiz);
    } else if (recorrido == 3) {
        file << " POSTORDER [with=1.5];";
        recorrer_post_order(abb->raiz);
    }
    file << texto << endl;

    for (int i = 0; i < abb->size; i++) {
        if (i < abb->size - 1) {
            file << "abb" << i << "->" << "abb" << i + 1 << ";\n" << endl;
        }
    }
    file << "}" << endl;




    system("dot -Tpng transversal_report.dot -o transversal_report.png");
    string title = "transversal_report.png";
    ShellExecute(NULL, "open", title.c_str(), NULL, NULL, SW_SHOWNORMAL);

}

void Generador_Repore::recorrer_in_order(Nodo_ABB* tmp) {
    if (tmp != 0) {
        recorrer_in_order(tmp->izquierdo);
        texto = texto + "abb" + to_string(index) + "[label=\"" + tmp->cubo->nombre + "\"]\n";
        index++;
        recorrer_in_order(tmp->derecho);
    }
}

void Generador_Repore::recorrer_pre_order(Nodo_ABB* tmp) {

    if (tmp != 0) {
        texto = texto + "abb" + to_string(index) + "[label=\"" + tmp->cubo->nombre + "\"]\n";
        index++;
        recorrer_pre_order(tmp->izquierdo);
        recorrer_pre_order(tmp->derecho);

    }

}

void Generador_Repore::recorrer_post_order(Nodo_ABB* tmp) {
    if (tmp != 0) {
        recorrer_post_order(tmp->izquierdo);
        recorrer_post_order(tmp->derecho);

        texto = texto + "abb" + to_string(index) + "[label=\"" + tmp->cubo->nombre + "\"]\n";
        index++;

    }
}