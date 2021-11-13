/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncAuxpreg2.h
 * Author: Jhenny Aydee Cervera Vargas
 *
 * Created on 11 de noviembre de 2021, 04:42 PM
 */

#ifndef FUNCAUXPREG2_H
#define FUNCAUXPREG2_H

#include <iostream>        
#include <fstream>
#include "Conductor.h"
using namespace std;

 void leerConductores(Conductor conductor[]);
 void leerRegitroFaltas( Conductor conductor[]);
  void leerInfracciones(Conductor conductor[]);
   void calcularMontoInfracciones(Conductor conductor[]);
  void ingresoDeFecha(int &fechaI) ;
   void aplicarAmnistiaCOnductor(Conductor conductor []);
   void imprimirReporteConductor(Conductor conductor[], const char* nombrArch);
#endif /* FUNCAUXPREG2_H */
