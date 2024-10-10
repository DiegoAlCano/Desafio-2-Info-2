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
    string categoriaCombistible;
    string metodoPago;
    string documentoCliente;
    unsigned int cantidadDinero;
public:

    float getCantidadCombustibleVendido() const;
    string getCategoriaCombustible() const;
    unsigned int getCantidadDinero() const;
    void mostrarVenta();

    ~Venta();
    Venta();
};

#endif // VENTA_H
