#include "surtidor.h"
#include <iostream>
#include <string.h>
#include "venta.h"
#include "estacion.h"
#include <stdlib.h>
using namespace std;

estacion::estacion(){
    nombre = "";
    identificador = "";
    gerente = "";
    region = "";
    ubicacionGPS = "";
    cantidadSurtidores = 0;
    Surtidores = new surtidor[12];
}

estacion::estacion(string _nombre,string _identificador,string _gerente, string _region,string _ubicacionGPS){
    nombre = _nombre;
    identificador = _identificador;
    gerente = _gerente;
    region = _region;
    ubicacionGPS = _ubicacionGPS;
    cantidadSurtidores = 0;
    Surtidores = new surtidor[12];
}

void estacion::agregarSurtidor(const surtidor& nuevoSurtidor){

    if(cantidadSurtidores==11){
        cout<<"No se pueden agregar mas surtidores a la estacion "<<nombre<<endl;
    }
    else{
        Surtidores[cantidadSurtidores]= nuevoSurtidor;
        cantidadSurtidores++;
    }
}


void estacion::eliminarSurtidor(string _codigoIdentificador){

    string id;
    bool encontrado=false;

    for(int i=0;i<cantidadSurtidores;i++){
        id = Surtidores[i].getCodigoIdentificador();
        if(id ==_codigoIdentificador){
            encontrado = true;
            Surtidores[i].~surtidor();
            for(int k=i;k<cantidadSurtidores-1;k++){
                Surtidores[k]=Surtidores[k+1];
            }
            Surtidores[cantidadSurtidores].~surtidor();
            i = cantidadSurtidores;
        }
    }

    if(encontrado){
        cantidadSurtidores--;

        cout<<"Surtidor eliminado"<<endl;
        cout<<endl;
    }

    else{
        cout<<"El codigo ingresado no pertenece a un surtidor de la estacion"<<endl;
        cout<<endl;
    }
}

void estacion::desactivarSurtidor(string _codigoIdentificador){
    string id;
    bool encontrado = false;

    for(int i=0;i<cantidadSurtidores;i++){
        id = Surtidores[i].getCodigoIdentificador();
        if(id ==_codigoIdentificador){
            encontrado = true;
            Surtidores[i].setcambiarEstado();
            i = cantidadSurtidores;
            cout<<"Surtidor desactivado"<<endl;
            cout<<endl;
        }

    }

    if(!encontrado){
        cout<<"El codigo ingresado no corresponde a un surtidor de la estacion"<<endl;
        cout<<endl;
    }
}

void estacion::cantidadesVendidas(){
    float regular=0,premium=0,extra=0,vendida=0,numVentas;
    string tipo;

    for(int i=0;i<cantidadSurtidores;i++){
        numVentas = (Surtidores[i].getNumVentas());
        for(int k = 0;k<numVentas;k++){
            vendida = (Surtidores[i].getVentas())[k].getCantidadCombustibleVendido();
            tipo = (Surtidores[i].getVentas())[k].getCategoriaCombustible();
            if(tipo=="Regular"){
                regular += vendida;
            }
            else if(tipo=="Premium"){
                premium += vendida;
            }
            else{
                extra += vendida;
            }
        }
    }

    cout<<"Cantidad de combustible Regular vendido: "<<regular<<endl;
    cout<<"Cantidad de combustible Premium vendido: "<<premium<<endl;
    cout<<"Cantidad de combustible EcoExtra vendido: "<<extra<<endl;
    cout<<endl;
}

void estacion::consultarTransacciones(){

    for(int i=0;i<cantidadSurtidores;i++){
        cout<<"Ventas del surtidor con codigo: "<<Surtidores[i].getCodigoIdentificador()<<endl;
        Surtidores[i].mostrarVentas();
    }
}


void estacion::capacidadTanque(){
    srand(time(NULL));
    for(int i = 0;i<3;i++){
        tanque[i]= rand() % 101 + 100;
        tanque[3+i]=tanque[i];
    }
}

void estacion::realizarVenta(){

    string texto, textoAux;
    float combustibleVendido;
    unsigned int valorVenta;
    char tipo;
    Venta nuevaVenta;

    cout<<"Ingrese el dia de la venta: ";
    cin>>textoAux;
    texto += textoAux;
    texto += '/';
    cout<<"Ingrese el mes de la venta: ";
    cin>>textoAux;
    texto += textoAux;
    texto += '/';
    cout<<"Ingrese el anio de la venta: ";
    cin>>textoAux;
    texto += textoAux;

    nuevaVenta.setFechaVenta(texto);
    texto="";

    cout<<"Ingrese la hora del dia de la venta: ";
    cin>>textoAux;
    texto += textoAux;
    texto += ':';
    cout<<"Ingrese el minuto del dia de la venta: ";
    cin>>textoAux;
    texto += textoAux;

    nuevaVenta.setHoraVenta(texto);
    texto = "";

    cout<<"Ingrese la cantidad de combustible vendida: ";
    cin>>combustibleVendido;

    nuevaVenta.setCantidadCombustibleVendido(combustibleVendido);

    cout<<"Ingrese 1 para tipo de combustible Regular"<<endl;
    cout<<"Ingrese 2 para tipo de combustible Premium"<<endl;
    cout<<"Ingrese 3 para tipo de combustible EcoExtra"<<endl;
    cout<<"Tipo de combustible: ";
    cin>>tipo;

    if(tipo=='1'){
        nuevaVenta.setCategoriaCombustible("Regular");
    }
    else if(tipo=='2'){
        nuevaVenta.setCategoriaCombustible("Premium");
    }
    else{
        nuevaVenta.setCategoriaCombustible("EcoExtra");
    }

    cout<<"Ingrese 1 para metodo de pago Efectivo"<<endl;
    cout<<"Ingrese 2 para metodo de pago TDebito"<<endl;
    cout<<"Ingrese 3 para metodo de pago TCredito"<<endl;
    cout<<"Metodo de Pago: ";
    cin>>tipo;

    if(tipo=='1'){
        nuevaVenta.setMetodoPago("Efectivo");
    }
    else if(tipo=='2'){
        nuevaVenta.setMetodoPago("TDebito");
    }
    else{
        nuevaVenta.setMetodoPago("TCredito");
    }

    cout<<"Ingrese el numero de documento del cliente: ";
    cin>>textoAux;

    nuevaVenta.setDocumentoCliente(textoAux);

    cout<<"Ingrese el valor de la venta: ";
    cin>>valorVenta;

    nuevaVenta.setCantidadDinero(valorVenta);

    cout<<"Ingrese el codigo identificador del surtidor que realizo la venta: ";
    cin>>textoAux;

    for(int i = 0;i<cantidadSurtidores;i++){
        texto = Surtidores[i].getCodigoIdentificador();
        if(texto==textoAux){
            Surtidores[i].agregarVenta(nuevaVenta);
            cout<<"Venta ingresada exitosamente"<<endl;
        }
    }
    cout<<endl;
}

estacion::~estacion(){
    delete[] Surtidores;
}
