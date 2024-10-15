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
    short int cantidadSurtidores;
    surtidor* Surtidores;
    float tanque[6] = {0,0,0,0,0,0};

public://Metodos
    estacion(string _nombre,string _identificador,string _gerente, string _region,string _ubicacionGPS);//Constructor
    estacion();
    estacion(string nombre1,string identificador1);
    ~estacion();//Destructor
    string getNombre();
    string getIdentificador();
    string getUbicacionGPS();
    string getRegion();
    short int getCantidadSurtidores();
    surtidor* getSurtidores();
    void agregarSurtidor(surtidor& nuevoSurtidor);
    void capacidadTanque();
    void eliminarSurtidor(string _codigoIdentificador);
    void consultarTransacciones();
    void modificarSurtidor(string _codigoIdentificador);
    void cantidadesVendidas();
    void mostrarInformacion()const;
    void simularVenta(redNacional& red);
    void actualizarDisponible(short unsigned int _cantidadVendida, string _tipoCombustible);
    void verificarFugas();
    // Sobrecarga del operador ==
    bool operator==(const estacion& otraEstacion) const {
        return (nombre == otraEstacion.nombre && identificador == otraEstacion.identificador);
    }

};

#endif // ESTACION_H
