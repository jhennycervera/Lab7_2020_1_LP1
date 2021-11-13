/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jhenny Cervera Vargas
 * Codigo: 20182841
 * Created on 11 de noviembre de 2021, 12:00 AM
 */


#include <iostream>
#include <iomanip>      
#include "Conductor.h"
#include "Falta.h"
#include "FaltaCond.h"
#include "Infraccion.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    ifstream archC("Conductores.csv", ios::in);
    ifstream archI("Infracciones.csv", ios::in);
    ifstream archR("RegistroDeFaltas.csv", ios::in);
    ofstream archRep("ReportePrueba.txt", ios:: out);
    
    Conductor cond, cond1(123, "Luis");
    Infraccion infr, infr1(111, "mal", "Grave", 12.3);
    Falta regFal, falt1(123, "G3", 111, 20210120);

    archC>>cond;
    archI>>infr;
    archR>>regFal;
    cond.imprimirConductor();

    cond1 + falt1;
    cond1.imprimirConductor();

    cout << "==============" << endl;

    cond1 + infr1;
    cond1.imprimirConductor();
    cout << "==============" << endl;

    cond1++;
    cond1.imprimirConductor();

    cout << "==============" << endl;
    cond1 * 20210220;
    cond1.imprimirConductor();
    
    cout << "==============" << endl;
    archRep<<cond1;
    
    

    return 0;
}

