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
    for(int i=0;i<cantidadSurtidores;i++){
        id = Surtidores[i].getCodigoIdentificador();
        if(id ==_codigoIdentificador){
            Surtidores[i].~surtidor();
            for(int k=i;k<cantidadSurtidores-1;k++){
                Surtidores[k]=Surtidores[k+1];
            }
            i = cantidadSurtidores;
        }
    }
    cantidadSurtidores--;

    cout<<"Surtidor eliminado"<<endl;
    cout<<endl;
}

void estacion::desactivarSurtidor(string _codigoIdentificador){
    string id;

    for(int i=0;i<cantidadSurtidores;i++){
        id = Surtidores[i].getCodigoIdentificador();
        if(id ==_codigoIdentificador){
            Surtidores[i].setcambiarEstado();
        }

    }
    cout<<"Surtidor desactivado"<<endl;
    cout<<endl;
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
        tanque[1][i]= rand() % 101 + 100;
        tanque[2][i]=tanque[1][i];
    }
}

estacion::~estacion(){
    delete[] Surtidores;
}
