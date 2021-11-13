/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Infraccion.h
 * Author: Jhenny Cervera Vargas
 * Codigo: 20182841
 * Created on 11 de noviembre de 2021, 12:07 AM
 */

#ifndef INFRACCION_H
#define INFRACCION_H
#include <fstream>
using namespace std;

class Infraccion {
private:
    int codigo;
    char* descripcion;
    char * gravedad;
    double multa;
public:
    Infraccion();
    Infraccion(int,char*, char*, double);
    virtual ~Infraccion();
    void SetMulta(double multa);
    double GetMulta() const;
    void SetGravedad(const char* );
    void GetGravedad( char* ) const;
    void SetDescripcion(const char* );
    void GetDescripcion(char* ) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;

};

ifstream & operator >> (ifstream&, Infraccion&);

#endif /* INFRACCION_H */

