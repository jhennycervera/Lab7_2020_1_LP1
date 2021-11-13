/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Falta.cpp
 * Author: Jhenny Cervera Vargas
 * Codigo: 20182841
 * Created on 11 de noviembre de 2021, 12:07 AM
 */

#include "Falta.h"
#include <fstream>
#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;

Falta::Falta() {
    placa = nullptr;
}


Falta::Falta(int rlic, char* rplaca, int rcodI, int rfecha) {
    
    placa=nullptr;
    SetCodInf(rcodI);
    SetFecha(rfecha);
    SetLicencia(rlic);
    SetPlaca(rplaca);
}

Falta::~Falta() {
    if (placa != nullptr) delete placa;
}

void Falta::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Falta::GetFecha() const {
    return fecha;
}

void Falta::SetCodInf(int codInf) {
    this->codInf = codInf;
}

int Falta::GetCodInf() const {
    return codInf;
}

void Falta::SetPlaca(const char* cad) {
    if (cad == nullptr) return;
    if (placa != nullptr) delete placa;
    placa = new char[strlen(cad) + 1];
    strcpy(placa, cad);
}

void Falta::GetPlaca(char* cad) const {
    if (placa == nullptr) cad[0] = 0;
    else strcpy(cad, placa);
}

void Falta::SetLicencia(int licencia) {
    this->licencia = licencia;
}

int Falta::GetLicencia() const {
    return licencia;
}





ifstream & operator >> (ifstream & arch,Falta &f ){
    
    int rlic, rfecha, rcodI, dd, mm, aa;
    char rplaca[200], c;
    
    arch>>rlic;
    if(arch.eof()) return arch;
    arch.get();
    arch.getline(rplaca, 200, ',');
    arch>>dd>>c>>mm>>c>>aa>>c>>rcodI;
    rfecha= dd+ mm*100 + aa*10000;
    
    f.SetCodInf(rcodI);
    f.SetFecha(rfecha);
    f.SetLicencia(rlic);
    f.SetPlaca(rplaca);
    return arch;
    
}