/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Infraccion.cpp
 * Author: Jhenny Cervera Vargas
 * Codigo: 20182841
 * Created on 11 de noviembre de 2021, 12:07 AM
 */

#include "Infraccion.h"
#include <fstream>
#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;

Infraccion::Infraccion() {
    descripcion= nullptr;
    gravedad= nullptr;
}

Infraccion::Infraccion(int rcodigo, char* rdescripcion,
        char* rgravedad, double rmulta) {
    descripcion= nullptr;
    gravedad= nullptr;
    
    SetMulta(rmulta);
    SetCodigo(rcodigo);
    SetDescripcion(rdescripcion);
    SetGravedad(rgravedad);
}


Infraccion::~Infraccion() {
    if(descripcion!= nullptr) delete descripcion;
    if(gravedad!= nullptr) delete gravedad;
}

void Infraccion::SetMulta(double multa) {
    this->multa = multa;
}

double Infraccion::GetMulta() const {
    return multa;
}

void Infraccion::SetGravedad(const char* cad) {
   if (cad == nullptr) return;
   if (gravedad != nullptr) delete gravedad;
   gravedad = new char[strlen(cad) + 1];
   strcpy(gravedad, cad);
}

void Infraccion::GetGravedad( char* cad) const {
  if (gravedad == nullptr) cad[0] = 0;
   else strcpy(cad, gravedad);
}

void Infraccion::SetDescripcion(const char* cad ) {
   if (cad == nullptr) return;
    if (descripcion != nullptr) delete descripcion;
    descripcion = new char[strlen(cad) + 1];
    strcpy(descripcion, cad);
}

void Infraccion::GetDescripcion( char* cad) const {
    if (descripcion == nullptr) cad[0] = 0;
    else strcpy(cad, descripcion);
    
}

void Infraccion::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Infraccion::GetCodigo() const {
    return codigo;
}


ifstream & operator >> (ifstream& arch, Infraccion& i){
    
    int rcod;
    char rdes[200], grav[200];
    double rmulta;
    
    arch>>rcod;
    if(arch.eof()) return arch;
    arch.get();
    arch.getline(rdes, 200, ',');
    arch.getline(grav, 200, ',');
    arch>>rmulta;
    
    i.SetCodigo(rcod);
    i.SetDescripcion(rdes);
    i.SetGravedad(grav);
    i.SetMulta(rmulta);
    
    return arch;
    
    
}
