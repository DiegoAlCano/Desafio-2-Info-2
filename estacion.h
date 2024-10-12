#ifndef ESTACION_H
#define ESTACION_H
#include <iostream>
#include <string.h>
#include <surtidor.h>
#include "venta.h"
#include "surtidor.h"
using namespace std;


class estacion
{
private://Atributos
    string nombre;
    string identificador;
    string gerente;
    string region;
    string ubicacionGPS;
    short int cantidadSurtidores;
    surtidor* Surtidores;
    float tanque[6] = {0,0,0,0,0,0};
public://Metodos
    estacion(string _nombre,string _identificador,string _gerente, string _region,string _ubicacionGPS);//Constructor
    estacion();
    ~estacion();//Destructor

    void agregarSurtidor(const surtidor& nuevoSurtidor);
    void capacidadTanque();
    void eliminarSurtidor(string _codigoIdentificador);
    void consultarTransacciones();
    void desactivarSurtidor(string _codigoIdentificador);
    void cantidadesVendidas();
    void realizarVenta();
//    void menuEstacion();
};

#endif // ESTACION_H
