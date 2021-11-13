/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FaltaCond.cpp
 * Author: Jhenny Cervera Vargas
 * Codigo: 20182841
 * Created on 11 de noviembre de 2021, 12:07 AM
 */

#include "FaltaCond.h"
#include <fstream>
#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;

FaltaCond::FaltaCond() {
    placa=nullptr;
    gravedad= nullptr;
    fecha=0;
    codInf=0;
    multa=0;
}

FaltaCond::FaltaCond(char* rplaca, int rfecha, int rcodInf, 
        double rmulta, char*rgrav ) {
    
    placa=nullptr;
    gravedad= nullptr;
    
    SetCodInf(rcodInf);
    SetFecha(rfecha);
    SetGravedad(rgrav);
    SetPlaca(rplaca);
    SetMulta(rmulta);
}


FaltaCond::~FaltaCond() {
    if(placa!= nullptr) delete placa;
    if(gravedad!= nullptr) delete gravedad;
}

void FaltaCond::SetGravedad(const char* cad) {
    if(cad== nullptr) return;
    if(gravedad!= nullptr) delete gravedad;
    gravedad= new char[strlen(cad) + 1];
    strcpy(gravedad, cad);
}

void FaltaCond::GetGravedad(char* cad) const {
    if(gravedad==nullptr) cad[0]=0;
    else strcpy(cad, gravedad); 
}

void FaltaCond::SetMulta(double multa) {
    this->multa = multa;
}

double FaltaCond::GetMulta() const {
    return multa;
}

void FaltaCond::SetCodInf(int codInf) {
    this->codInf = codInf;
}

int FaltaCond::GetCodInf() const {
    return codInf;
}

void FaltaCond::SetFecha(int fecha) {
    this->fecha = fecha;
}

int FaltaCond::GetFecha() const {
    return fecha;
}

void FaltaCond::SetPlaca(const char* cad) {
    if(cad== nullptr) return;
    if(placa!= nullptr) delete placa;
    placa= new char[strlen(cad) + 1];
    strcpy(placa, cad);
}

void FaltaCond::GetPlaca(char* cad) const {
    if(placa==nullptr) cad[0]=0;
    else strcpy(cad, placa); 
}

