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
    int *precioNorte;
    int *precioSur;
    int *precioCentro;

public:
    redNacional();//constructor por defecto
    redNacional(string);//constructor
    void agregarEstacion(estacion,string);
    void eliminarEstacion(estacion,string);
    void establecerPrecio(int,int*&);
    void calcularVentas();
};

#endif // REDNACIONAL_H
