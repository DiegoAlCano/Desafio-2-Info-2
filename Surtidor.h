#ifndef SURTIDOR_H
#define SURTIDOR_H
#include <iostream>
#include <string.h>
#include "venta.h"
using namespace std;


class surtidor
{
private://Atributos
    string codigoIdentificador;
    string modelo;
    bool activo;
    int numVentas;     // Cantidad actual de ventas
    int capacidad;     // Capacidad actual del arreglo
    Venta *ventas;

public://Metodos
    surtidor(string, string, bool);//Constructor
    surtidor();
    ~surtidor();//Destructor
    
    string getCodigoIdentificador();
    void redimensionar();
    void setcambiarEstado();
    void agregarVenta(const Venta& nuevaVenta);
};

#endif // SURTIDOR_H
