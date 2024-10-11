#include "surtidor.h"
#include "venta.h"
using namespace std;

surtidor::surtidor(){
    codigoIdentificador = "";
    modelo = "";
    activo = "";
    capacidad = 0;
    numVentas = 0;
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
    delete [] ventas;
}
