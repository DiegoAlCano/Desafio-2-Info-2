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
    estacion *Norte;
    estacion *Sur;
    estacion *Centro;
    unsigned int *precioNorte;
    unsigned int *precioSur;
    unsigned int *precioCentro;
    unsigned short int capacidadEstaciones = 0;
    unsigned short int estacionesNorte = 0;
    unsigned short int estacionesSur = 0;
    unsigned short int estacionesCentro = 0;

public:

    redNacional(string);//constructor
    void agregarEstacion(estacion,string);
    void eliminarEstacion(estacion,string);
    void establecerPrecio(unsigned int, unsigned int&);
    void calcularVentas();
    void redimensionar(estacion*&, unsigned short int&, unsigned short int);
    void mostrarEstaciones() const;
    ~redNacional();//Destructor
};

#endif // REDNACIONAL_H
