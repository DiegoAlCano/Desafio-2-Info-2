#include "rednacional.h"
#include "surtidor.h"
#include "venta.h"
#include "estacion.h"

redNacional::redNacional(string _nombre)
{
    nombre = _nombre;
    capacidadEstaciones = 100;
    Norte =  new estacion[capacidadEstaciones];
    Sur = new estacion[capacidadEstaciones];
    Centro = new estacion[capacidadEstaciones];
    estacionesNorte = 0;
    estacionesSur = 0;
    estacionesCentro = 0;
    precioNorte = nullptr;
    precioSur = nullptr;
    precioCentro = nullptr;

}

void redNacional::agregarEstacion(estacion nuevaEstacion,string regionEstacion)
{
    if(regionEstacion == "Norte"){
        if (estacionesNorte == capacidadEstaciones) {
            redimensionar(Norte,capacidadEstaciones,estacionesNorte);
        }
        Norte[estacionesNorte] =nuevaEstacion;
        estacionesNorte++;
        cout<< "La estacion fue agregada correctamente."<< endl;
    }
    else if(regionEstacion == "Sur"){
        if (estacionesSur == capacidadEstaciones) {
            redimensionar(Sur,capacidadEstaciones,estacionesSur);
        }
        Sur[estacionesSur] =nuevaEstacion;
        estacionesSur++;
        cout<< "La estacion fue agregada correctamente."<< endl;
    }
    else{
        if (estacionesCentro == capacidadEstaciones) {
            redimensionar(Centro,capacidadEstaciones,estacionesCentro);
        }
        Centro[estacionesCentro] =nuevaEstacion;
        estacionesCentro++;
        cout<< "La estacion fue agregada correctamente."<< endl;
    }
}

void redNacional::eliminarEstacion(estacion estacionEliminar, string regionEstacion) {
    if (regionEstacion == "Norte") {
        for (int i = 0; i < estacionesNorte; i++) {
            if (Norte[i] == estacionEliminar) {
                for (int j = i; j < estacionesNorte - 1; j++) {
                    Norte[j] = Norte[j + 1];  // Desplaza todas las estaciones una posición a la izquierda
                }
                estacionesNorte--;
                cout << "La estacion ha sido eliminada correctamente." << endl;
                return;
            }
        }
    }
    else if (regionEstacion == "Sur") {
        for (int i = 0; i < estacionesSur; i++) {
            if (Sur[i] == estacionEliminar) {
                for (int j = i; j < estacionesSur - 1; j++) {
                    Sur[j] = Sur[j + 1];
                }
                estacionesSur--;
                cout << "La estacion ha sido eliminada correctamente." << endl;
                return;
            }
        }
    }
    else {  // Región Centro
        for (int i = 0; i < estacionesCentro; i++) {
            if (Centro[i] == estacionEliminar) {
                for (int j = i; j < estacionesCentro - 1; j++) {
                    Centro[j] = Centro[j + 1];
                }
                estacionesCentro--;
                cout << "La estacion ha sido eliminada correctamente." << endl;
                return;
            }
        }
    }

    cout << "La estación no se encontra registrada." << endl;
}



void redNacional::mostrarEstaciones() const {
    // Imprimir estaciones en la región Norte
    cout<<"-----------------------------" << endl;
    cout << "Estaciones en la region Norte: "<< estacionesNorte<< endl;
    for (int i = 0; i < estacionesNorte; i++) {
        Norte[i].mostrarInformacion(); // Supongo que tienes un método para mostrar la info en la clase 'estacion'
    }
    cout<<"-----------------------------" << endl;
    // Imprimir estaciones en la región Sur
    cout << "Estaciones en la region Sur: "<< estacionesSur << endl;
    for (int i = 0; i < estacionesSur; i++) {
        Sur[i].mostrarInformacion();
    }
    cout<<"-----------------------------" << endl;
    // Imprimir estaciones en la región Centro
    cout << "Estaciones en la region Centro: "<< estacionesCentro << endl;
    for (int i = 0; i < estacionesCentro; i++) {
        Centro[i].mostrarInformacion();
    }
    cout<<"-----------------------------" << endl;
}

void redNacional::redimensionar(estacion*& arreglo, unsigned short int& capacidadEstaciones,unsigned short int estaciones)
{

    int nuevaCapacidad = capacidadEstaciones + 10;
    estacion* nuevoArreglo = new estacion[nuevaCapacidad];
    for(int i= 0;i < estaciones;i++)
    {
        nuevoArreglo[i] = arreglo[i];
    }
    delete[] arreglo;
    arreglo = nuevoArreglo;
    capacidadEstaciones = nuevaCapacidad;
}

redNacional::~redNacional(){
    delete[] Norte;
    delete[] Sur;
    delete[] Centro;
}
