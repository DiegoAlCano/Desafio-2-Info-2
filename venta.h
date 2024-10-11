#ifndef VENTA_H
#define VENTA_H
#include <iostream>
#include <string>
using namespace std;

class Venta
{
private:
    string fechaVenta;
    string horaVenta;
    float cantidadCombustibleVendido;
    string categoriaCombustible;
    string metodoPago;
    string documentoCliente;
    unsigned int cantidadDinero;
public:

    float getCantidadCombustibleVendido() const;
    string getCategoriaCombustible() const;
    unsigned int getCantidadDinero() const;

    void setCantidadCombustibleVendido(float _cantidadCombustibleVendido);
    void setCantidadDinero(unsigned int _cantidadDinero);

    void mostrarVenta();


    ~Venta();
    Venta(); //Constructor por defecto
    Venta(string _fechaVenta, string _horaVenta, float _cantidadCombustibleVendido, string _categoriaCombustible,
          string _metodoPago, string documentoCliente, unsigned int _cantidadDinero); //Constructor por defectos
};

#endif // VENTA_H
