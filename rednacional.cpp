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

}
