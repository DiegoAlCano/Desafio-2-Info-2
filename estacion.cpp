#include "surtidor.h"
#include <iostream>
#include <string.h>
#include "venta.h"
#include "estacion.h"
#include <stdlib.h>
using namespace std;

estacion::estacion(){
    nombre = "";
    identificador = "";
    gerente = "";
    region = "";
    ubicacionGPS = "";
    cantidadSurtidores = 0;
    Surtidores = new surtidor[12];
}

estacion::estacion(string _nombre,string _identificador,string _gerente, string _region,string _ubicacionGPS){
    nombre = _nombre;
    identificador = _identificador;
    gerente = _gerente;
    region = _region;
    ubicacionGPS = _ubicacionGPS;
    cantidadSurtidores = 0;
    Surtidores = new surtidor[12];
}

void estacion::agregarSurtidor(const surtidor& nuevoSurtidor){

    if(cantidadSurtidores==11){
        cout<<"No se pueden agregar mas surtidores a la estacion "<<nombre<<endl;
    }
    else{
        Surtidores[cantidadSurtidores]= nuevoSurtidor;
        cantidadSurtidores++;
    }
}


void estacion::eliminarSurtidor(string _codigoIdentificador) {
    if (cantidadSurtidores == 0) {
        cout << "No hay surtidores para eliminar." << endl;
        return;
    }

    surtidor *newSurtidores = new surtidor[12];  // Crear nuevo arreglo dinámico

    bool encontrado = false;  // Para saber si el surtidor fue encontrado

    for (int i = 0, j = 0; i < cantidadSurtidores; i++) {
        if (Surtidores[i].getCodigoIdentificador() == _codigoIdentificador) {
            // No copiar el surtidor que queremos eliminar
            encontrado = true;
        } else {
            newSurtidores[j] = Surtidores[i];  // Copiar los demás surtidores
            j++;
        }
    }

    if (encontrado) {
        cantidadSurtidores--;
        delete[] Surtidores;  // Liberar memoria del arreglo antiguo
        Surtidores = newSurtidores;  // Asignar el nuevo arreglo
        cout << "Surtidor eliminado." << endl;
    } else {
        delete[] newSurtidores;  // Si no se encontró, no necesitamos este nuevo arreglo
        cout << "Surtidor con identificador " << _codigoIdentificador << " no encontrado." << endl;
    }

    cout << endl;
}

void estacion::consultarTransacciones(){

    for(int i=0;i<cantidadSurtidores;i++){
        cout<<"Ventas del surtidor con codigo: "<<Surtidores[i].getCodigoIdentificador()<<endl;
        Surtidores[i].mostrarVentas();
    }
}


void estacion::capacidadTanque(){
    srand(time(NULL));
    for(int i = 0;i<3;i++){
        tanque[1][i]= rand() % 101 + 100;
        tanque[2][i]=tanque[1][i];
    }
}

estacion::~estacion(){
    delete[] Surtidores;
    cout << "Memoria del arreglo de ventas liberada correctamente." << endl;
}
