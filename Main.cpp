#include <iostream>
#include "venta.h"
#include "surtidor.h"
#include "estacion.h"
#include <string.h>
#include "rednacional.h"
using namespace std;

int main()
{
    string nombre;
    cout<<"Ingrese el nombre de la red nacional: ";
    cin>> nombre;
    redNacional pais(nombre);

    estacion estacion1("La Grande","5840","Diego","Centro","13975449076");
    surtidor surtidor1("ABC123", "ModeloX", true);
    surtidor surtidor2("ABC321","MODELY",true);
    surtidor surtidor3("ABC312","MODELZ",true);
    Venta venta1("9/10/2024","9:28",3.4,"Regular","Efectivo","1002969042",666);
    Venta venta2("9/10/2024","10:28",1.5,"Premium","Efectivo","11112969042",30000);
    Venta venta3("10/10/2024","7:31",3,"EcoExtra","Efectivo","1002969042",50000);
    Venta venta4("11/10/2024","12:16",3,"EcoExtra","Efectivo","103681573",50000);

    surtidor1.agregarVenta(venta1);
    surtidor1.agregarVenta(venta4);
    surtidor3.agregarVenta(venta2);
    surtidor2.agregarVenta(venta3);

    estacion1.agregarSurtidor(surtidor1);
    estacion1.agregarSurtidor(surtidor2);
    estacion1.agregarSurtidor(surtidor3);
    estacion1.capacidadTanque();
    string infoRegion = estacion1.getRegion();
    pais.agregarEstacion(estacion1);
    //segunda estacion
    estacion estacion2("La Grande2","5840","Diego2","Norte","13975449076");
    surtidor surtidor4("ABC123", "ModeloX", true);
    surtidor surtidor5("ABC321","MODELY",true);
    surtidor surtidor6("ABC312","MODELZ",true);
    estacion2.agregarSurtidor(surtidor4);
    estacion2.agregarSurtidor(surtidor5);
    estacion2.agregarSurtidor(surtidor6);
    estacion2.capacidadTanque();
    string infoRegion2 = estacion2.getRegion();
    pais.agregarEstacion(estacion2);
    pais.mostrarEstaciones();
    pais.eliminarEstacion(estacion2);
    pais.mostrarEstaciones();

    pais.montoVentasNacional();

    pais.fijarPreciosCombustible();

    return 0;
}
