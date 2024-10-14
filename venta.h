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
    short unsigned int cantidadCombustibleVendido;
    string categoriaCombustible;
    string metodoPago;
    string documentoCliente;
    unsigned int cantidadDinero;
public:

    short unsigned int getCantidadCombustibleVendido() const;
    string getCategoriaCombustible() const;
    unsigned int getCantidadDinero() const;

    void setCantidadCombustibleVendido(float _cantidadCombustibleVendido);
    void setCantidadDinero(unsigned int _cantidadDinero);
    void setFechaVenta(string _fechaVenta);
    void setHoraVenta(string _horaVenta);
    void setCategoriaCombustible(string _categoriaCombustible);
    void setDocumentoCliente(string _documentoCliente);
    void setMetodoPago(string _metodoPago);

    void mostrarVenta();


    ~Venta();
    Venta(); //Constructor por defecto
    Venta(string _fechaVenta, string _horaVenta, float _cantidadCombustibleVendido, string _categoriaCombustible,
          string _metodoPago, string documentoCliente, unsigned int _cantidadDinero); //Constructor por defectos
};

#endif // VENTA_H
