#ifndef ESTACION_H
#define ESTACION_H
#include <iostream>
#include <string.h>
#include <surtidor.h>
using namespace std;


class estacion
{
    private://Atributos
        string nombre;
        string identificador;
        string gerente;
        string region;
        string ubicacionGPS;
        surtidor Surtidores[12]={0};
        int tanque[2][3];
    public://Metodos
        estacion(string, string, string, string);//Constructor
        ~estacion();//Destructor
        void setSurtidores(int indice, int valor);
};

#endif // ESTACION_H
