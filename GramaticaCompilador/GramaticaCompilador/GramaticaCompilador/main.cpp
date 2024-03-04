#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "lexico.h"
#include "pila.h"

using namespace std;

int idReglas[2] = { 2, 2 };
int lonReglas[2] = { 3, 0 };

// Funcion para leer el archivo crear la matriz
vector<vector<int>> leerArchivoYCrearMatriz(const string& nombreArchivo, int lineaInicio) {
    vector<vector<int>> matriz;
    ifstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        string linea;
        int numeroLinea = 1;

        // Leer cada liena hasta llegar a la de la matriz
        while (getline(archivo, linea) && numeroLinea < lineaInicio) {
            numeroLinea++;
        }

        // Leer las lineas restantes del archivo y crear la matriz
        while (getline(archivo, linea)) {
            vector<int> fila;
            stringstream ss(linea);
            int valor;

            // Leer cada elemento de la linea y agregarlo a la fila
            while (ss >> valor) {
                fila.push_back(valor);
            }

            // Agregar la fila a la matriz
            matriz.push_back(fila);
        }

        archivo.close();
    }
    else {
        cerr << "No se pudo abrir el archivo." << endl;
    }

    return matriz;
}

vector<vector<int>> tablaLR = leerArchivoYCrearMatriz("compilador.lr", 55);

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