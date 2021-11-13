/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jhenny Cervera Vargas
 * Codigo: 20182841
 * Created on 11 de noviembre de 2021, 04:33 PM
 */


#include <iostream>
#include <iomanip>        
using namespace std;
#include "Conductor.h"
#include "Falta.h"
#include "Infraccion.h"
#include "FuncAuxpreg2.h"

/*
 * 
 */
int main(int argc, char** argv) {
    
    Conductor conductor[200];
    leerConductores(conductor);
    leerRegitroFaltas(conductor);
    leerInfracciones(conductor);
    calcularMontoInfracciones(conductor);
    imprimirReporteConductor(conductor, "ReporteConductor.txt");
    aplicarAmnistiaCOnductor(conductor);
    imprimirReporteConductor(conductor, "ReporteConductor_ConAministia.txt");
    
    return 0;
}

