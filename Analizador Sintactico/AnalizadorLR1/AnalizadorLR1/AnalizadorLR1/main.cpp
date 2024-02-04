#include <cstdlib>
#include <iostream>
#include <string>

#include "lexico.h"
#include "pila.h"

using namespace std;

int idReglas[2] = { 2, 2 };
int lonReglas[2] = { 3, 0 };

int tablaLR[5][4]={
    2,0,0,1,
    0,0,-1,0,
    0,3,0,0,
    4,0,0,0,
    0,0,-2,0
};

int tablaLR2[5][4] = {
    2,0,0,1,
    0,0,-1,0,
    0,3,-3,0,
    2,0,0,4,
    0,0,-2,0
};

void funcionEj1() {
    Pila pila;
    int fila, columna, accion;
    bool aceptacion = false;
    Lexico lexico("a+b");

    pila.push(TipoSimbolo::PESOS);
    pila.push(0);

    lexico.sigSimbolo();

    fila = pila.top();
    columna = lexico.tipo;
    accion = tablaLR[fila][columna];

    pila.muestra();
    cout << "entrada: "<< lexico.simbolo << endl;
    cout << "accion: " << accion << endl;

    pila.push(lexico.tipo);
    pila.push(accion);
    lexico.sigSimbolo();

    fila = pila.top();
    columna = lexico.tipo;
    accion = tablaLR[fila][columna];

    pila.muestra();
    cout << "entrada: " << lexico.simbolo << endl;
    cout << "accion: " << accion << endl;

    pila.push(lexico.tipo);
    pila.push(accion);
    lexico.sigSimbolo();

    fila = pila.top();
    columna = lexico.tipo;
    accion = tablaLR[fila][columna];

    pila.muestra();
    cout << "entrada: " << lexico.simbolo << endl;
    cout << "accion: " << accion << endl;

    pila.push(lexico.tipo);
    pila.push(accion);
    lexico.sigSimbolo();

    fila = pila.top();
    columna = lexico.tipo;
    accion = tablaLR[fila][columna];

    pila.muestra();
    cout << "entrada: " << lexico.simbolo << endl;
    cout << "accion: " << accion << endl;
    pila.pop();
    pila.pop();
    pila.pop();
    pila.pop();
    pila.pop();

    fila = pila.top();
    columna = 3; //El no terminal que representa E
    accion = tablaLR[fila][columna];

    
    //transición
    pila.push(3); //el 2 es el entero que representa el no terminal E
    pila.push(accion);
    pila.muestra();
    cout << "entrada: " << lexico.simbolo << endl;
    cout << "accion: " << accion << endl << endl;
    //estado de acptacion -1
    fila = pila.top();
    columna = lexico.tipo;
    accion = tablaLR[fila][columna];

    pila.muestra();
    cout << "entrada: " << lexico.simbolo << endl;
    cout << "accion: " << accion << endl << endl;
    aceptacion = accion == -1;
    if (aceptacion) cout << "aceptacion" << endl;
    
}


void funcionEj2() {
    Pila pila;
    int fila, columna, accion;
    bool aceptacion = false;
    Lexico lexico("a+b");

    pila.push(TipoSimbolo::PESOS);
    pila.push(0);

    lexico.sigSimbolo();

    fila = pila.top();
    columna = lexico.tipo;
    accion = tablaLR[fila][columna];

    pila.muestra();
    cout << "entrada: " << lexico.simbolo << endl;
    cout << "accion: " << accion << endl;



    pila.push(lexico.tipo);
    pila.push(accion);
    lexico.sigSimbolo();

    fila = pila.top();
    columna = lexico.tipo;
    accion = tablaLR[fila][columna];

    pila.muestra();
    cout << "entrada: " << lexico.simbolo << endl;
    cout << "accion: " << accion << endl;

    pila.push(lexico.tipo);
    pila.push(accion);
    lexico.sigSimbolo();

    fila = pila.top();
    columna = lexico.tipo;
    accion = tablaLR[fila][columna];

    pila.muestra();
    cout << "entrada: " << lexico.simbolo << endl;
    cout << "accion: " << accion << endl;

    pila.push(lexico.tipo);
    pila.push(accion);
    lexico.sigSimbolo();

    fila = pila.top();
    columna = lexico.tipo;
    accion = tablaLR[fila][columna];

    pila.muestra();
    cout << "entrada: " << lexico.simbolo << endl;
    cout << "accion: " << accion << endl;
    pila.pop();
    pila.pop();
    pila.pop();
    pila.pop();
    pila.pop();

    fila = pila.top();
    columna = 3; //El no terminal que representa E
    accion = tablaLR[fila][columna];


    //transición
    pila.push(3); //el 2 es el entero que representa el no terminal E
    pila.push(accion);
    pila.muestra();
    cout << "entrada: " << lexico.simbolo << endl;
    cout << "accion: " << accion << endl << endl;
    //estado de acptacion -1
    fila = pila.top();
    columna = lexico.tipo;
    accion = tablaLR[fila][columna];

    pila.muestra();
    cout << "entrada: " << lexico.simbolo << endl;
    cout << "accion: " << accion << endl << endl;
    aceptacion = accion == -1;
    if (aceptacion) cout << "aceptacion" << endl;

}


int main(int argc, char *argv[]){

    


    funcionEj1();

    return 0;
}