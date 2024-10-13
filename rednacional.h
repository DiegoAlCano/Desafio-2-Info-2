#ifndef REDNACIONAL_H
#define REDNACIONAL_H
#include <iostream>
#include <string.h>
#include "estacion.h"
#include "venta.h"
#include "surtidor.h"
using namespace std;

class redNacional
{
private://Atributos
    string nombre;
    estacion *Estaciones;
    unsigned int precioNorte[3];
    unsigned int precioSur[3];
    unsigned int precioCentro[3];
    unsigned short int capacidadEstaciones = 0;
    unsigned short int cantidadEstaciones = 0;

public:

    redNacional(string);//constructor
    void agregarEstacion(estacion);
    void eliminarEstacion(estacion);
    void establecerPrecio(unsigned int, unsigned int&);
    void calcularVentas();
    void redimensionar(estacion*&, unsigned short int&, unsigned short int);
    void mostrarEstaciones() const;
    void montoVentasNacional();
    void fijarPreciosCombustible();
    ~redNacional();//Destructor
};

#endif // REDNACIONAL_H
