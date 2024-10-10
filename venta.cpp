#include "venta.h"

Venta::Venta() {

    string fecha,hora,_fechaVenta,_horaVenta,_documentoCliente;
    float _cantidadCombustibleVendido;
    unsigned int _cantidadDinero;
    short int tipoCombustible=0,tipoPago;


    cout<<"Ingrese el dia de la venta: ";
    cin>>fecha;
    _fechaVenta += fecha;
    _fechaVenta += '/';

    cout<<"Ingrese el mes de la venta: ";
    cin>>fecha;
    _fechaVenta += fecha;
    _fechaVenta += '/';

    cout<<"Ingrese el anio de la venta: ";
    cin>>fecha;
    _fechaVenta += fecha;

    fechaVenta = _fechaVenta;

    cout<<"La hora de la venta se debe almacenar en formato 24 horas"<<endl;
    cout<<"Ingrese la hora del dia: ";
    cin>>hora;
    _horaVenta += hora;
    _horaVenta += ':';
    cout<<"Ingrese el minuto del dia: ";
    cin>>hora;
    _horaVenta += hora;

    horaVenta = _horaVenta;

    cout<<"Ingrese la cantidad de combustible vendido: ";
    cin>>_cantidadCombustibleVendido;

    cantidadCombustibleVendido = _cantidadCombustibleVendido;

    cout<<"Ingrese 1 para Combustible Regular, 2 para Premium y 3 para EcoExtra: ";
    cin>>tipoCombustible;

    if(tipoCombustible=='1'){
        categoriaCombistible = "Regular";
    }
    else if(tipoCombustible=='2'){
        categoriaCombistible = "Premium";
    }

    else{
        categoriaCombistible = "EcoExtra";
    }

    cout<<"Ingrese 1 para pago en Efectivo, 2 para TDebito y 3 para TCredito: ";
    cin>>tipoPago;

    if(tipoPago=='1'){
        metodoPago = "Efectivo";
    }
    else if(tipoPago=='2'){
        metodoPago = "TDebito";
    }

    else{
        metodoPago = "TCredito";
    }

    cout<<"Ingrese el numero de documento del cliente: ";
    cin>>_documentoCliente;

    documentoCliente = _documentoCliente;

    cout<<"Ingrese la cantidad de Dinero de la venta: ";
    cin>>_cantidadDinero;

    cantidadDinero = _cantidadDinero;


}

float Venta::getCantidadCombustibleVendido() const{
    return cantidadCombustibleVendido;
}

string Venta::getCategoriaCombustible() const{
    return categoriaCombistible;
}

unsigned int Venta::getCantidadDinero() const{
    return cantidadDinero;
}

Venta::~Venta(){
    fechaVenta = "";
    horaVenta = "";
    cantidadCombustibleVendido = 0.0;
    categoriaCombistible = "";
    metodoPago = "";
    documentoCliente = "";
    cantidadDinero = 0;
}

void Venta::mostrarVenta(){
    cout<<"INFORMACION DE LA VENTA"<<endl;
    cout<<"Fecha: "<<fechaVenta<<endl;
    cout<<"Hora: "<<horaVenta<<endl;
    cout<<"Cantidad de combustible vendido: "<<cantidadCombustibleVendido<<endl;
    cout<<"Categoria de combustible vendido: "<<categoriaCombistible<<endl;
    cout<<"Metodo de pago: "<<metodoPago<<endl;
    cout<<"Documento del cliente: "<<documentoCliente<<endl;
    cout<<"Valor de la venta: "<<cantidadDinero<<endl;
}

