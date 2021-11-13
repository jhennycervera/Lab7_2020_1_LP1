/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



/* 
 * File:   FuncAux.cpp
 * Author: Jhenny Aydee Cervera Vargas
 * Codigo: 20182841
 * Created on 11 de noviembre de 2021, 04:05 PM
 */

#include "FuncAux.h"
#include <iostream>        
#include <iomanip>
#include <fstream>
#include <cstring>        
using namespace std;

void imprimirLinea(ofstream &Rep, char c, int cant) {
    Rep.fill(c);
    Rep << setw(cant) << c << endl;
    Rep.fill(' ');
}

ifstream abrirArchL(const char *nombre) {
    ifstream arch;
    arch.open(nombre, ios::in);
    if (!arch) {
        cout << "ERROR: no se pudo abrir el archivo " << nombre << endl;
        exit(1);
    }
    return arch;
}

ofstream abrirArchE(const char *nombre) {
    ofstream arch;
    arch.open(nombre, ios::out);
    if (!arch) {
        cout << "ERROR: no se pudo abrir el archivo " << nombre << endl;
        exit(1);
    }
    return arch;
}

void fSepararFecha(int fecha, int &dd, int &mm, int &aa) {

    aa = fecha / 10000;
    fecha %= 10000;
    mm = fecha / 100;
    dd = fecha % 100;

}


