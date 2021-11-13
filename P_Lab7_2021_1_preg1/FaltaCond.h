/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FaltaCond.h
 * Author: Jhenny Cervera Vargas
 * Codigo: 20182841
 * Created on 11 de noviembre de 2021, 12:07 AM
 */

#ifndef FALTACOND_H
#define FALTACOND_H
#include <fstream>
using namespace std;

class FaltaCond {
private:
    char* placa;
    int fecha;
    int codInf;
    double multa;
    char* gravedad;
    
public:
    FaltaCond();
    FaltaCond(char* , int, int, double, char*);
    virtual ~FaltaCond();
    void SetGravedad(const char* );
    void GetGravedad(char*) const;
    void SetMulta(double multa);
    double GetMulta() const;
    void SetCodInf(int codInf);
    int GetCodInf() const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetPlaca(const char* );
    void GetPlaca(char* ) const;
};


#endif /* FALTACOND_H */

