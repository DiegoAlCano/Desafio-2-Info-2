#include "surtidor.h"
#include <iostream>
#include <string.h>
#include "venta.h"
using namespace std;

surtidor::surtidor(){
    codigoIdentificador = "";
    modelo = "";
    activo = false;
    capacidad = 15;
    numVentas = 0;
    ventas = new Venta[capacidad];
}

surtidor::surtidor(string _codigoIdentificador,string _modelo,bool _activo)
{
    codigoIdentificador = _codigoIdentificador;
    modelo = _modelo;
    activo = _activo;
    capacidad = 15;
    numVentas = 0;
    ventas = new Venta[capacidad];
}

void surtidor::setcambiarEstado()
{
    if(activo==true)
    {
        activo= false;
    }
    else
    {
        activo=true;
    }
}

string surtidor::getCodigoIdentificador(){
    return codigoIdentificador;
}

Venta* surtidor::getVentas(){
    return ventas;
}

int surtidor::getCapacidad(){
    return capacidad;
}

int surtidor::getNumVentas(){
    return numVentas;
}


void surtidor::mostrarVentas(){
    if(numVentas==0){
        cout<<"No hay ventas registradas"<<endl;
        cout<<endl;
    }

    else{
        for(int i = 0;i<numVentas;i++){
            cout<<"VENTA "<<i+1<<endl;
            ventas[i].mostrarVenta();
            cout<<endl;
        }
    }

}

void surtidor::redimensionar() {

    int nuevaCapacidad = capacidad + 10;
    Venta* nuevoArreglo = new Venta[nuevaCapacidad];

    for (int i = 0; i<numVentas; i++) {
        nuevoArreglo[i] = ventas[i];
    }

    delete[] ventas;

    ventas = nuevoArreglo;
    capacidad = nuevaCapacidad;
}

void surtidor::agregarVenta(const Venta& nuevaVenta) {
    if (numVentas == capacidad) {
        redimensionar();
    }
    ventas[numVentas] = nuevaVenta;
    numVentas++;
}

surtidor::~surtidor(){
    delete[] ventas;
}
