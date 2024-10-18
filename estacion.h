#ifndef ESTACION_H
#define ESTACION_H
#include <iostream>
#include <string.h>
#include <surtidor.h>
#include "venta.h"
#include "surtidor.h"
using namespace std;

class redNacional;

class estacion
{
private://Atributos
    string nombre;
    string identificador;
    string gerente;
    string region;
    string ubicacionGPS;
    short unsigned int cantidadSurtidores;
    surtidor* Surtidores;
    short unsigned int tanque[6] = {0,0,0,0,0,0};

public://Metodos
    estacion(string _nombre,string _identificador,string _gerente, string _region,string _ubicacionGPS);//Constructor
    estacion();
    ~estacion();//Destructor
    string getNombre();
    string getIdentificador();
    string getUbicacionGPS();
    string getRegion();
    short unsigned int getCantidadSurtidores();
    surtidor* getSurtidores();
    void agregarSurtidor(surtidor& nuevoSurtidor);
    void capacidadTanque();
    void eliminarSurtidor(string _codigoIdentificador);
    void consultarTransacciones();
    void modificarSurtidor(string _codigoIdentificador);
    void cantidadesVendidas();
    void mostrarInformacion()const;
    void verificarFugas();
    void simularVenta(redNacional& red);

};

#endif // ESTACION_H
