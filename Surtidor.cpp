#include "surtidor.h"
#include <iostream>
#include <string.h>
using namespace std;


surtidor::surtidor(string _codigoIdentificador,string _modelo,bool _activo)
{
    codigoIdentificador = _codigoIdentificador;
    modelo = _modelo;
    activo = _activo;
}

void surtidor::setcambiarEstado()
{
    if(activo==true)
    {
        activo= false;
    }
    else
    {
        activo=true;
    }
}

