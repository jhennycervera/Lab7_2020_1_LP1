/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncAux.h
 * Author: Jhenny Aydee Cervera Vargas
 *
 * Created on 11 de noviembre de 2021, 04:05 PM
 */

#ifndef FUNCAUX_H
#define FUNCAUX_H

#include <iostream>        
#include <fstream>
using namespace std;

void imprimirLinea(ofstream &, char, int);
ifstream abrirArchL(const char *nombre);
ofstream abrirArchE(const char *nombre);
void fSepararFecha( int fecha, int &dd, int &mm, int &aa);

#endif /* FUNCAUX_H */
