/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Conductor.h
 * Author: Jhenny Cervera Vargas
 * Codigo: 20182841
 * Created on 11 de noviembre de 2021, 12:07 AM
 */

#ifndef CONDUCTOR_H
#define CONDUCTOR_H
#include <fstream>
#include "FaltaCond.h"
#include "Falta.h"
#include "Infraccion.h"
using namespace std;

class Conductor {
private:
    int licencia;
    char* nombre;
    FaltaCond lfaltas[200];
    int numFaltas;
    double montoTotal;
public:
    Conductor();
    Conductor(int , char*);
    ~Conductor();
    
    void SetMontoTotal(double montoTotal);
    double GetMontoTotal() const;
    void SetNombre(const char* );
    void GetNombre(char*) const;
    void SetLicencia(int licencia);
    int GetLicencia() const ;
     int GetNumFaltas() const;
    
    void imprimirConductor();
    void imprimirFaltas(ofstream &) cont;
    
    void operator + (const Falta  &);
    void operator +( const Infraccion &);
    void operator ++(int);
    void operator *(int);
    
    
};

ifstream & operator >> (ifstream &, Conductor &);
ofstream & operator << (ofstream &, const Conductor &);


#endif /* CONDUCTOR_H */

