#include "venta.h"

Venta::Venta(string _fechaVenta, string _horaVenta, float _cantidadCombustibleVendido, string _categoriaCombustible,
             string _metodoPago, string _documentoCliente, unsigned int _cantidadDinero){

    fechaVenta = _fechaVenta;
    horaVenta = _horaVenta;
    cantidadCombustibleVendido = _cantidadCombustibleVendido;
    categoriaCombustible = _categoriaCombustible;
    metodoPago = _metodoPago;
    documentoCliente = _documentoCliente;
    cantidadDinero = _cantidadDinero;


}

Venta::Venta(){
    fechaVenta="";
    horaVenta="";
    cantidadCombustibleVendido=0.0;
    categoriaCombustible="";
    metodoPago="";
    documentoCliente="";
    cantidadDinero=0;
}

float Venta::getCantidadCombustibleVendido() const{
    return cantidadCombustibleVendido;
}

string Venta::getCategoriaCombustible() const{
    return categoriaCombustible;
}

unsigned int Venta::getCantidadDinero() const{
    return cantidadDinero;
}

void Venta::setCantidadCombustibleVendido(float _cantidadCombustibleVendido){
    cantidadCombustibleVendido = _cantidadCombustibleVendido;
}

void Venta::setCantidadDinero(unsigned int _cantidadDinero){
    cantidadDinero = _cantidadDinero;
}

Venta::~Venta(){
    fechaVenta = "";
    horaVenta = "";
    cantidadCombustibleVendido = 0.0;
    categoriaCombustible = "";
    metodoPago = "";
    documentoCliente = "";
    cantidadDinero = 0;
}

void Venta::mostrarVenta(){
    cout<<"INFORMACION DE LA VENTA"<<endl;
    cout<<"Fecha: "<<fechaVenta<<endl;
    cout<<"Hora: "<<horaVenta<<endl;
    cout<<"Cantidad de combustible vendido: "<<cantidadCombustibleVendido<<endl;
    cout<<"Categoria de combustible vendido: "<<categoriaCombustible<<endl;
    cout<<"Metodo de pago: "<<metodoPago<<endl;
    cout<<"Documento del cliente: "<<documentoCliente<<endl;
    cout<<"Valor de la venta: "<<cantidadDinero<<endl;
}


