/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Conductor.cpp
 * Author: Jhenny Cervera Vargas
 * Codigo: 20182841
 * Created on 11 de noviembre de 2021, 12:07 AM
 */

#include "Conductor.h"
#include <fstream>
#include <cstring>
#include <iostream>
#include <iomanip>
#include "FuncAux.h"
using namespace std;

Conductor::Conductor() {
    nombre = nullptr;
    numFaltas = 0;
    montoTotal = 0;
    licencia=0;  //SE PUEDE PONER SI EN LA PREG 2, no puede  tener un numConducores en el caso se declare un arrego de esta clase
}

Conductor::Conductor(int rlic, char* rnombre) {
    nombre = nullptr;
    numFaltas = 0;
    montoTotal = 0;
    licencia=0;
    SetLicencia(rlic);
    SetNombre(rnombre);
}

Conductor::~Conductor() {
    if (nombre != nullptr) delete nombre;
}

void Conductor::SetMontoTotal(double montoTotal) {
    this->montoTotal = montoTotal;
}

double Conductor::GetMontoTotal() const {
    return montoTotal;
}

void Conductor::SetNombre(const char* cad) {
    if (cad == nullptr) return;
    if (nombre != nullptr) delete nombre;
    nombre = new char[strlen(cad) + 1];
    strcpy(nombre, cad);
}

void Conductor::GetNombre(char* cad) const {
    if (nombre == nullptr) cad[0] = 0;
    else strcpy(cad, nombre);
}

void Conductor::SetLicencia(int licencia) {
    this->licencia = licencia;
}

int Conductor::GetLicencia() const {
    return licencia;
}

void Conductor::imprimirConductor() {

    char grav[100];
    cout << left << "CodLic: " << setw(10) << licencia << "monto total: " << montoTotal << endl;

    for (int i = 0; i < numFaltas; i++) {
        lfaltas[i].GetGravedad(grav);
        cout << "codInfr: " << setw(10) << lfaltas[i].GetCodInf() <<
                "fecha: " << setw(10) << lfaltas[i].GetFecha() <<
                "multa " << setw(10) << lfaltas[i].GetMulta() <<
                "gravedad " << grav << endl;
    }
    cout << numFaltas << endl;
}

void Conductor::operator+(const Falta& f) {

    lfaltas[numFaltas].SetFecha(f.GetFecha());
    lfaltas[numFaltas].SetCodInf(f.GetCodInf());

    char placa[100];
    f.GetPlaca(placa);
    lfaltas[numFaltas].SetPlaca(placa);

    numFaltas++;
}

void Conductor::operator+(const Infraccion & in) {
    char grav[100];
    in.GetGravedad(grav);

    int cod = in.GetCodigo();

    for (int i = 0; i < numFaltas; i++) {
        if (lfaltas[i].GetCodInf() == cod) {

            lfaltas[i].SetGravedad(grav);
            lfaltas[i].SetMulta(in.GetMulta());
        }
    }

}

void Conductor::operator++(int) {  //si cacula toso debo poner un 0 al inicio
    
    montoTotal=0; //VER
    for (int i = 0; i < numFaltas; i++) {
        montoTotal += lfaltas[i].GetMulta();
    }
}

void Conductor::operator*(int rfecha) {
    char grav[100];
    double rmulta;
    for (int i = 0; i < numFaltas; i++) {
        lfaltas[i].GetGravedad(grav);
        rmulta = lfaltas[i].GetMulta();
        if (lfaltas[i].GetFecha() < rfecha) {
            if (strcmp(grav, "Grave") == 0)
                lfaltas[i].SetMulta(rmulta - (rmulta * 0.25));
            else if (strcmp(grav, "Muy Grave") == 0)
                lfaltas[i].SetMulta(rmulta - (rmulta * 0.1));
            else
                lfaltas[i].SetMulta(rmulta - (rmulta * 0.5));
        }
    }
    //volver a calcular el monto del consdutor
    (*this)++;
}

int Conductor::GetNumFaltas() const {
    return numFaltas;
}

void Conductor::imprimirFaltas(ofstream& arch) const{
    
    int dd,mm,aa;
    char rplaca[100], rgrav[100];
    arch<<left<<setw(10)<<"  N°"<<setw(20)<<"Fecha"<<
                setw(20)<<"Placa"<<setw(20)<<"Infraccion"<<
                setw(20)<<"Gravedad"<<"Multa"<<endl;
    for(int i=0; i<numFaltas; i++){
        lfaltas[i].GetPlaca(rplaca);
        lfaltas[i].GetGravedad(rgrav);
        fSepararFecha( lfaltas[i].GetFecha(), dd, mm, aa);
        arch<<right<<setw(3)<<i+1<<")"<<setw(5)<<' ';
        arch<< right << setfill('0') << setw(2) << dd << '/' << setw(2) << mm << '/' << aa << setfill(' ');
        arch<< left << setw(10) << ' ';
        arch<<setw(20)<<rplaca<<setw(20)<<lfaltas[i].GetCodInf()<<setw(20)
                      <<rgrav<<lfaltas[i].GetMulta()<<endl;
        
    }
}


ifstream & operator>>(ifstream & arch, Conductor & c) {
    int rlic;
    char rnombr[200];

    arch>>rlic;
    if (arch.eof()) return arch;
    arch.get();
    arch.getline(rnombr, 200);

    c.SetLicencia(rlic);
    c.SetNombre(rnombr);
    return arch;
}

ofstream & operator << (ofstream & arch, const Conductor & c){
    char rnombre[200];
    c.GetNombre(rnombre);
   
    arch<<left<<"Conductor  :"<< rnombre<<endl;
    arch<<left<<"Licencia N°:"<< c.GetLicencia()<<endl;
    imprimirLinea(arch, '=', 200);
    arch<<"Infracciones cometidas"<<endl;
    imprimirLinea(arch, '-', 200);
    
    c.imprimirFaltas(arch);
    
    imprimirLinea(arch, '=', 200);
    arch<<left<<"Total de infracciones:"<<setw(10) <<c.GetNumFaltas()<<c.GetMontoTotal()<<endl;
    
    return arch;
}
