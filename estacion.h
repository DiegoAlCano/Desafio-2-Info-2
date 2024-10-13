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

    string getRegion();
    short int getCantidadSurtidores();
    surtidor* getSurtidores();
    void agregarSurtidor(const surtidor& nuevoSurtidor);
    void capacidadTanque();
    void eliminarSurtidor(string _codigoIdentificador);
    void consultarTransacciones();
    void modificarSurtidor(string _codigoIdentificador);
    void activarSurtidor(string _codigoIdentificador);
    void cantidadesVendidas();
    void realizarVenta();
    void mostrarInformacion()const;
    void menuEstacion();
    // Sobrecarga del operador ==
    bool operator==(const estacion& otraEstacion) const {
        return (nombre == otraEstacion.nombre && identificador == otraEstacion.identificador);
    }

};

#endif // ESTACION_H
