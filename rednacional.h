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
    void eliminarEstacion(estacion);
    void establecerPrecio(unsigned int, unsigned int&);
    void calcularVentas();
    void redimensionar(estacion*&, unsigned short int&, unsigned short int);
    void mostrarEstaciones() const;
    void montoVentasNacional();
    void fijarPreciosCombustible();
    estacion encontarEstacion(estacion,bool &encontrado);

    ~redNacional();//Destructor
};

#endif // REDNACIONAL_H
