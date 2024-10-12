#ifndef REDNACIONAL_H
#define REDNACIONAL_H
#include <iostream>
#include <string.h>
#include "estacion.h"
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
    short int capacidadEstaciones = 0;
    short int estacionesNorte = 0;
    short int estacionesSur = 0;
    short int estacionesCentro = 0;

public:
    redNacional();//constructor por defecto
    redNacional(string);//constructor
    void agregarEstacion(estacion,string);
    void eliminarEstacion(estacion,string);
    void establecerPrecio(unsigned int, unsigned int&);
    void calcularVentas();
    ~redNacional();//Destructor
};

#endif // REDNACIONAL_H
