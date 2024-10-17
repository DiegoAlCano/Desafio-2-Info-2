#include "surtidor.h"
#include <iostream>
#include <string.h>
#include "venta.h"
#include "estacion.h"
#include <stdlib.h>
#include "rednacional.h"
using namespace std;

estacion::estacion(){
    nombre = "";
    identificador = "";
    gerente = "";
    region = "";
    ubicacionGPS = "";
    cantidadSurtidores = 0;
    Surtidores = new surtidor[12];
}

estacion::estacion(string _nombre,string _identificador,string _gerente, string _region,string _ubicacionGPS){
    nombre = _nombre;
    identificador = _identificador;
    gerente = _gerente;
    region = _region;
    ubicacionGPS = _ubicacionGPS;
    cantidadSurtidores = 0;
    Surtidores = new surtidor[12];
}

void estacion::agregarSurtidor(surtidor& nuevoSurtidor){

    bool Duplicada = false;

    for(int i = 0;i < cantidadSurtidores;i++){
        if(Surtidores[i].getCodigoIdentificador() == nuevoSurtidor.getCodigoIdentificador()){
            cout << endl;
            cout << endl;
            cout<< "Ya se encuentra agregado un surtidor con ese codigo identificador"<<endl;
            cout << endl;
            cout << endl;
            Duplicada = true;
            break;
        }
    }

    if(cantidadSurtidores==12){
        cout<<"No se pueden agregar mas surtidores a la estacion "<<nombre<<endl;
    }

    else if(!Duplicada){
        Surtidores[cantidadSurtidores]= nuevoSurtidor;
        cantidadSurtidores++;
        cout<< "El SURTIDOR se ha agregado correctamente."<< endl;
        cout<<"La cantidad de surtidores es: "<< cantidadSurtidores<< endl;
    }
}


void estacion::eliminarSurtidor(string _codigoIdentificador){

    string id;
    bool encontrado = false;

    if(cantidadSurtidores>2){
        for (int i = 0; i < cantidadSurtidores; i++) {
            id = Surtidores[i].getCodigoIdentificador();
            if (id == _codigoIdentificador) {
                encontrado = true;
                // Mover los surtidores hacia atrás en el arreglo
                for (int k = i; k < cantidadSurtidores - 1; k++) {
                    Surtidores[k] = Surtidores[k + 1];
                }
                cantidadSurtidores--; // Reducir la cantidad de surtidores
                break; // Salir del bucle una vez encontrado
            }
        }

        if (encontrado) {
            cout << "Surtidor eliminado" << endl;
            cout << endl;
        } else {
            cout << "El codigo ingresado no pertenece a un surtidor de la estacion" << endl;
            cout << endl;
        }
    }
    else{
        cout <<"La estacion tiene el numero minimo de surtidores: 2"<<endl;
    }
}

void estacion::modificarSurtidor(string _codigoIdentificador){
    string id;
    bool encontrado = false,estado= false;

    for(int i=0;i<cantidadSurtidores;i++){
        id = Surtidores[i].getCodigoIdentificador();
        estado = Surtidores[i].getActivo();
        if(id ==_codigoIdentificador){
            encontrado = true;
            if(estado==true){
                Surtidores[i].setcambiarEstado();
                i = cantidadSurtidores;
                cout<<"Surtidor desactivado"<<endl;
                cout<<endl;
            }
            else{
                Surtidores[i].setcambiarEstado();
                i = cantidadSurtidores;
                cout<<"Surtidor activado"<<endl;
                cout<<endl;
            }
        }

    }

    if(!encontrado){
        cout<<"El codigo ingresado no corresponde a un surtidor de la estacion"<<endl;
        cout<<endl;
    }
}

void estacion::cantidadesVendidas(){
    unsigned int regular=0,premium=0,extra=0,vendida=0,numVentas;
    string tipo;

    for(int i=0;i<cantidadSurtidores;i++){
        numVentas = (Surtidores[i].getNumVentas());
        for(int k = 0;k<numVentas;k++){
            vendida = (Surtidores[i].getVentas())[k].getCantidadCombustibleVendido();
            tipo = (Surtidores[i].getVentas())[k].getCategoriaCombustible();
            if(tipo=="Regular"){
                regular += vendida;
            }
            else if(tipo=="Premium"){
                premium += vendida;
            }
            else{
                extra += vendida;
            }
        }
    }

    cout<<"Cantidad de combustible Regular vendido: "<<regular<<endl;
    cout<<"Cantidad de combustible Premium vendido: "<<premium<<endl;
    cout<<"Cantidad de combustible EcoExtra vendido: "<<extra<<endl;
    cout<<endl;
}

void estacion::consultarTransacciones(){

    for(int i=0;i<cantidadSurtidores;i++){
        cout<<"Ventas del surtidor con codigo: "<<Surtidores[i].getCodigoIdentificador()<<endl;
        Surtidores[i].mostrarVentas();
    }
}


void estacion::capacidadTanque(){
    srand(time(NULL));
    for(int i = 0;i<3;i++){
        tanque[i]= rand() % 101 + 100;
        tanque[3+i]=tanque[i];
    }
}

string estacion::getRegion()
{
    return region;
}
string estacion::getNombre()
{
    return nombre;
}

string estacion::getIdentificador()
{
    return identificador;
}
string estacion::getUbicacionGPS()
{
    return ubicacionGPS;
}

surtidor* estacion::getSurtidores(){
    return Surtidores;
}

short unsigned int estacion::getCantidadSurtidores(){
    return cantidadSurtidores;
}
void estacion::mostrarInformacion() const {
    cout << "--------------------------"<<endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Codigo: " << identificador << endl;
    cout << "Responsable: " << gerente << endl;
    cout << "Region: " << region << endl;
    cout << "Ubicacion GPS: " << ubicacionGPS << endl;
    cout << "--------------------------"<<endl;
}

void estacion::verificarFugas(){
    short unsigned int Regular=0,Premium=0, EcoExtra=0,combustibleVendido = 0,numVentas=0;
    string categoriaCombustible;

    for(int i = 0;i<cantidadSurtidores;i++){
        numVentas = Surtidores[i].getNumVentas();
        for(int k=0;k<numVentas;k++){
            categoriaCombustible = Surtidores[i].getVentas()[k].getCategoriaCombustible();
            combustibleVendido = Surtidores[i].getVentas()[k].getCantidadCombustibleVendido();
            if(categoriaCombustible == "Regular"){
                Regular += combustibleVendido;
            }
            else if(categoriaCombustible == "Premium"){
                Premium += combustibleVendido;
            }
            else{
                EcoExtra += combustibleVendido;
            }
        }
    }

    if(Regular+tanque[3]<tanque[0]*0.95){
        cout<<"Existe una fuga para el combustible Regular"<<endl;
    }

    else{
        cout<<"No exiten fugas para el combustible Regular"<<endl;
    }

    if(Premium+tanque[4]<tanque[1]*0.95){
        cout<<"Existe una fuga para el combustible Premium"<<endl;
    }

    else{
        cout<<"No exiten fugas para el combustible Premium"<<endl;
    }

    if(EcoExtra+tanque[5]<tanque[2]*0.95){
        cout<<"Existe una fuga para el combustible EcoExtar"<<endl;
    }

    else{
        cout<<"No exiten fugas para el combustible EcoExtra"<<endl;
    }


}

void estacion::simularVenta(redNacional& red){

    unsigned short int surt = 0;
    string texto, textoAux;
    short unsigned int combustibleVendido;
    unsigned int valorVenta=0;
    short int tipo;
    Venta nuevaVenta;

    unsigned short int cantidadActivos;
    for(int i = 0; i<cantidadSurtidores;i++){
        if(Surtidores[i].getActivo()==true){
            cantidadActivos++;
        }
    }
    if(cantidadActivos == 1){

        int aux;
        srand(time(NULL));
        for(int i = 0;i< cantidadSurtidores;i++){
            if(Surtidores[i].getActivo()==true){
                aux = i;
            }
        }
        srand(time(NULL));
        cout<<"La fecha debe ser ingresada en formato: dd/mm/aa"<<endl;
        cout<<"Ingrese el dia de la venta: ";
        cin>>textoAux;
        texto += textoAux;
        texto += '/';
        cout<<"Ingrese el mes de la venta: ";
        cin>>textoAux;
        texto += textoAux;
        texto += '/';
        cout<<"Ingrese el anio de la venta: ";
        cin>>textoAux;
        texto += textoAux;

        nuevaVenta.setFechaVenta(texto);
        texto="";

        cout<<"La hora debe ser ingresada en formato 24 horas hh:mm"<<endl;
        cout<<"Ingrese la hora del dia de la venta: ";
        cin>>textoAux;
        texto += textoAux;
        texto += ':';
        cout<<"Ingrese el minuto del dia de la venta: ";
        cin>>textoAux;
        texto += textoAux;

        nuevaVenta.setHoraVenta(texto);
        texto = "";

        while(true){
            cout<<"Ingrese 1 para tipo de combustible Regular"<<endl;
            cout<<"Ingrese 2 para tipo de combustible Premium"<<endl;
            cout<<"Ingrese 3 para tipo de combustible EcoExtra"<<endl;
            cout<<"Tipo de combustible: ";
            cin>>tipo;

            if (cin.fail()) {
                cin.clear(); // Limpiar el error de entrada
                cin.ignore(1000, '\n'); // Ignorar la entrada inválida
                cout << "Tipo de combustible invalido. Intente de nuevo" << endl;
            }

            else if(tipo!=1 and tipo!=2 and tipo!=3){
                cout<<"Tipo de Combustible invalido.Intente de nuevo"<<endl;
            }

            else{
                combustibleVendido = (rand() % 20) + 3;
                if(combustibleVendido>tanque[tipo+2]){
                    combustibleVendido = tanque[tipo+2];
                }

                tanque[tipo+2]-=combustibleVendido;

                cout<<"Litros de combustible vendido: "<<combustibleVendido<<endl;

                nuevaVenta.setCantidadCombustibleVendido(combustibleVendido);


                if(tipo==1){
                    nuevaVenta.setCategoriaCombustible("Regular");
                }
                else if(tipo==2){
                    nuevaVenta.setCategoriaCombustible("Premium");
                }
                else if(tipo==3){
                    nuevaVenta.setCategoriaCombustible("EcoExtra");
                }

                if(region=="Norte"){
                    valorVenta = combustibleVendido*red.getPreciosCombustible()[tipo-1];
                }
                else if(region == "Centro"){
                    valorVenta = combustibleVendido*red.getPreciosCombustible()[tipo+2];
                }
                else if(region=="Sur"){
                    valorVenta = combustibleVendido*red.getPreciosCombustible()[tipo+5];
                }

                cout<<"Valor de la venta: "<<valorVenta<<endl;
                nuevaVenta.setCantidadDinero(valorVenta);
                break;

            }
        }

        while(true){
            cout<<"Ingrese 1 para metodo de pago Efectivo"<<endl;
            cout<<"Ingrese 2 para metodo de pago TDebito"<<endl;
            cout<<"Ingrese 3 para metodo de pago TCredito"<<endl;
            cout<<"Metodo de Pago: ";
            cin>>tipo;

            if(cin.fail()){
                cin.clear(); // Limpiar el error de entrada
                cin.ignore(1000, '\n'); // Ignorar la entrada inválida
                cout << "Tipo de metodo de pago invalido. Intente de nuevo" << endl;
            }

            else if(tipo==1){
                nuevaVenta.setMetodoPago("Efectivo");
                break;
            }
            else if(tipo==2){
                nuevaVenta.setMetodoPago("TDebito");
                break;
            }
            else if(tipo==3){
                nuevaVenta.setMetodoPago("TCredito");
                break;
            }

            else{
                cout<<"Metodo de pago invalido.Intente de nuevo"<<endl;
            }

        }

        cout<<"Ingrese el numero de documento del cliente: ";
        cin>>textoAux;

        nuevaVenta.setDocumentoCliente(textoAux);

        Surtidores[aux].agregarVenta(nuevaVenta);
        cout<<"Venta agregada exitosamente"<<endl;
        cout<<endl;

        nuevaVenta.mostrarVenta();
    }
    else if(cantidadActivos > 1){

        srand(time(NULL));
        surt = rand() % cantidadSurtidores;
        while(Surtidores[surt].getActivo()==false){
            surt = rand() % cantidadSurtidores;
        }

        cout<<"La fecha debe ser ingresada en formato: dd/mm/aa"<<endl;
        cout<<"Ingrese el dia de la venta: ";
        cin>>textoAux;
        texto += textoAux;
        texto += '/';
        cout<<"Ingrese el mes de la venta: ";
        cin>>textoAux;
        texto += textoAux;
        texto += '/';
        cout<<"Ingrese el anio de la venta: ";
        cin>>textoAux;
        texto += textoAux;

        nuevaVenta.setFechaVenta(texto);
        texto="";

        cout<<"La hora debe ser ingresada en formato 24 horas hh:mm"<<endl;
        cout<<"Ingrese la hora del dia de la venta: ";
        cin>>textoAux;
        texto += textoAux;
        texto += ':';
        cout<<"Ingrese el minuto del dia de la venta: ";
        cin>>textoAux;
        texto += textoAux;

        nuevaVenta.setHoraVenta(texto);
        texto = "";

        while(true){
            cout<<"Ingrese 1 para tipo de combustible Regular"<<endl;
            cout<<"Ingrese 2 para tipo de combustible Premium"<<endl;
            cout<<"Ingrese 3 para tipo de combustible EcoExtra"<<endl;
            cout<<"Tipo de combustible: ";
            cin>>tipo;

            if (cin.fail()) {
                cin.clear(); // Limpiar el error de entrada
                cin.ignore(1000, '\n'); // Ignorar la entrada inválida
                cout << "Tipo de combustible invalido. Intente de nuevo" << endl;
            }

            else if(tipo!=1 and tipo!=2 and tipo!=3){
                cout<<"Tipo de Combustible invalido.Intente de nuevo"<<endl;
            }

            else{
                combustibleVendido = (rand() % 20) + 3;
                if(combustibleVendido>tanque[tipo+2]){
                    combustibleVendido = tanque[tipo+2];
                }

                tanque[tipo+2]-=combustibleVendido;

                cout<<"Litros de combustible vendido: "<<combustibleVendido<<endl;

                nuevaVenta.setCantidadCombustibleVendido(combustibleVendido);


                if(tipo==1){
                    nuevaVenta.setCategoriaCombustible("Regular");
                }
                else if(tipo==2){
                    nuevaVenta.setCategoriaCombustible("Premium");
                }
                else if(tipo==3){
                    nuevaVenta.setCategoriaCombustible("EcoExtra");
                }

                if(region=="Norte"){
                    valorVenta = combustibleVendido*red.getPreciosCombustible()[tipo-1];
                }
                else if(region == "Centro"){
                    valorVenta = combustibleVendido*red.getPreciosCombustible()[tipo+2];
                }
                else if(region=="Sur"){
                    valorVenta = combustibleVendido*red.getPreciosCombustible()[tipo+5];
                }

                cout<<"Valor de la venta: "<<valorVenta<<endl;
                nuevaVenta.setCantidadDinero(valorVenta);
                break;

            }
        }

        while(true){
            cout<<"Ingrese 1 para metodo de pago Efectivo"<<endl;
            cout<<"Ingrese 2 para metodo de pago TDebito"<<endl;
            cout<<"Ingrese 3 para metodo de pago TCredito"<<endl;
            cout<<"Metodo de Pago: ";
            cin>>tipo;

            if(cin.fail()){
                cin.clear(); // Limpiar el error de entrada
                cin.ignore(1000, '\n'); // Ignorar la entrada inválida
                cout << "Tipo de metodo de pago invalido. Intente de nuevo" << endl;
            }

            else if(tipo==1){
                nuevaVenta.setMetodoPago("Efectivo");
                break;
            }
            else if(tipo==2){
                nuevaVenta.setMetodoPago("TDebito");
                break;
            }
            else if(tipo==3){
                nuevaVenta.setMetodoPago("TCredito");
                break;
            }

            else{
                cout<<"Metodo de pago invalido.Intente de nuevo"<<endl;
            }

        }

        cout<<"Ingrese el numero de documento del cliente: ";
        cin>>textoAux;

        nuevaVenta.setDocumentoCliente(textoAux);

        Surtidores[surt].agregarVenta(nuevaVenta);
        cout<<"Venta agregada exitosamente"<<endl;
        cout<<endl;

        nuevaVenta.mostrarVenta();
    }
    else{
        cout << "La estacion no tiene surtidores activos para simular la venta"<< endl;
    }

}


estacion::~estacion(){

        //delete[] Surtidores;
        //Surtidores = NULL;
}
