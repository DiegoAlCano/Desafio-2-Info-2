#ifndef REDNACIONAL_H
#define REDNACIONAL_H
#include <iostream>
#include <string.h>
#include "estacion.h"
#include "venta.h"
#include "surtidor.h"
using namespace std;

class estacion;

class redNacional
{
private://Atributos
    string nombre;
    estacion *Estaciones;
    unsigned int preciosCombustible[9];
    unsigned short int capacidadEstaciones = 0;
    unsigned short int cantidadEstaciones = 0;

    friend class estacion;

public:

    redNacional(string);//constructor
    unsigned int* getPreciosCombustible();
    void agregarEstacion(estacion);
    void eliminarEstacion(int &indice);
    void redimensionar(estacion*&, unsigned short int&, unsigned short int);
    void mostrarEstaciones() const;
    void montoVentasNacional();
    void fijarPreciosCombustible();
    bool encontarEstacion(string _codigoIdentificador, int &indice);
    void modificarEstacion(int &indice, short unsigned int &opc1, redNacional& red);

    ~redNacional();//Destructor
};

#endif // REDNACIONAL_H
