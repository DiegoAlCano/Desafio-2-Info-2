#include <iostream>
#include "venta.h"
#include "surtidor.h"
#include "estacion.h"
using namespace std;

int main()
{
    string id;

    estacion estacion1("La Grande","5840","Diego","Centro","13975449076");
    surtidor surtidor1("ABC123", "ModeloX", true);
    surtidor surtidor2("ABC321","MODELY",true);
    surtidor surtidor3("ABC312","MODELZ",true);
    Venta venta1("9/10/2024","9:28",3.4,"Regular","Efectivo","1002969042",45000);
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


    estacion1.consultarTransacciones();
    estacion1.cantidadesVendidas();
    cout<<"Ingrese el codigo identificador del surtidor: ";
    cin>>id;
    estacion1.eliminarSurtidor(id);

    cout<<"Ingrese el codigo identificador del surtidor: ";
    cin>>id;
    estacion1.desactivarSurtidor(id);
    estacion1.consultarTransacciones();

    return 0;
}
