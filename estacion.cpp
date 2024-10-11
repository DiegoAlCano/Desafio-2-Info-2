#include "surtidor.h"
#include <iostream>
#include <string>
#include "venta.h"
#include "estacion.h"
#include <stdlib.h>
using namespace std;

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

/*
void estacion::eliminarSurtidor(string _codigoIdentificador, ){
    
}
*/

void estacion::capacidadTanque(){
    srand(time(NULL));
    for(int i = 0;i<3;i++){
        tanque[1][i]= rand() % 101 + 100;
        tanque[2][i]=tanque[1][i];
    }
}

estacion::~estacion(){
    delete [] Surtidores;
}
