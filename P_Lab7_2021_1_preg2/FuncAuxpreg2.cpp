/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



/* 
 * File:   FuncAuxpreg2.cpp
 * Author: Jhenny Aydee Cervera Vargas
 * Codigo: 20182841
 * Created on 11 de noviembre de 2021, 04:42 PM
 */

#include "FuncAuxpreg2.h"
#include <iostream>        
#include <iomanip>
#include <fstream>
#include <cstring>        
using namespace std;
#include "Conductor.h"
#include "FuncAux.h"
#include "Falta.h"
#include "Infraccion.h"


 void leerConductores(Conductor conductor[]){
     
    ifstream arch= abrirArchL("Conductores.csv");
     
    int numCond=0;
    while(1){
        arch>>conductor[numCond];
        if(arch.eof()) break;
        numCond++;
    } 
     
 }

 void leerRegitroFaltas( Conductor conductor[]){
     
    ifstream arch= abrirArchL("RegistroDeFaltas.csv");
     
    Falta falta;
    while(1){
         arch>>falta;
         if(arch.eof()) break;
        for(int i=0; conductor[i].GetLicencia()!= 0; i++ ){
            if(conductor[i].GetLicencia() == falta.GetLicencia()){
                conductor[i]+falta;
                break; //si le asigno ya no sigo buscando
            }
        }
    }
 }
 
 void leerInfracciones(Conductor c[]){
     
     ifstream arch= abrirArchL("Infracciones.csv");
     Infraccion infrac;
     while(1){
         arch>>infrac;
         if(arch.eof()) break;

         for(int i=0; c[i].GetLicencia()!=0; i++){
             c[i]+infrac;
         }
     }
 }

 void calcularMontoInfracciones(Conductor conductor[]){
     
    for(int i=0; conductor[i].GetLicencia()!= 0; i++){
         conductor[i]++;
    }
 }

 void imprimirReporteConductor(Conductor conductor[], const char* nombrArch){
     
     ofstream arch(nombrArch);
     
    for(int i=0; conductor[i].GetLicencia()!= 0; i++){
         arch<<conductor[i];
    }
 }
 
 void ingresoDeFecha(int &fechaI) {

    int dd, mm, aa;
    char c;
    cout << "Ingresar fecha" << endl;
    cin >> dd >> c >> mm >> c>>aa;
    fechaI = dd + mm * 100 + aa * 10000;
}
 
 void aplicarAmnistiaCOnductor(Conductor conductor []){
     
     int fechaI;
     ingresoDeFecha(fechaI);
     
     for(int i=0; conductor[i].GetLicencia()!= 0; i++){
         conductor[i]*fechaI;
    }
 }

