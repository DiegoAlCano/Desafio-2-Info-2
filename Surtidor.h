#ifndef SURTIDOR_H
#define SURTIDOR_H
#include <iostream>
#include <string.h>
using namespace std;


class surtidor
{
    private://Atributos
        string codigoIdentificador;
        string modelo;
        bool activo;
    public://Metodos
        surtidor(string, string, bool);//Constructor
        ~surtidor();//Destructor
        void setcambiarEstado(bool);
};

#endif // SURTIDOR_H
