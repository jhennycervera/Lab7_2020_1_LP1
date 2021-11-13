/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Falta.h
 * Author: Jhenny Cervera Vargas
 * Codigo: 20182841
 * Created on 11 de noviembre de 2021, 12:07 AM
 */

#ifndef FALTA_H
#define FALTA_H
#include <fstream>
using namespace std;

class Falta {
private:
    int licencia;
    char* placa;
    int codInf;
    int fecha;
public:
    Falta();
    Falta(int, char* , int, int);
    virtual ~Falta();
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetCodInf(int codInf);
    int GetCodInf() const;
    void SetPlaca(const char* );
    void GetPlaca(char*) const;
    void SetLicencia(int licencia);
    int GetLicencia() const;

};

ifstream & operator >> (ifstream &,Falta & ) ; 


#endif /* FALTA_H */

