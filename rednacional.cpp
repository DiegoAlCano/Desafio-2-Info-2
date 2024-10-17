#include "rednacional.h"
#include "surtidor.h"
#include "venta.h"
#include "estacion.h"

redNacional::redNacional(string _nombre)
{
    nombre = _nombre;
    capacidadEstaciones = 100;
    Estaciones =  new estacion[capacidadEstaciones];
    cantidadEstaciones = 0;

    preciosCombustible[0] = 13050;
    preciosCombustible[1] = 17500;
    preciosCombustible[2] = 21300;

    preciosCombustible[3] = 11600;
    preciosCombustible[4] = 16900;
    preciosCombustible[5] = 20100;

    preciosCombustible[6] = 14500;
    preciosCombustible[7] = 18300;
    preciosCombustible[8] = 22400;

}

unsigned int* redNacional::getPreciosCombustible(){
    return preciosCombustible;
}

void redNacional::agregarEstacion(estacion nuevaEstacion)
{
    surtidor surtidorDefecto1("SURT1","MODELX",true), surtidorDefecto2("SURT2","MODELY",true);
    bool Duplicada = false;
    for(int i = 0;i < cantidadEstaciones;i++){
        if(Estaciones[i].getUbicacionGPS() == nuevaEstacion.getUbicacionGPS()){
            cout << endl;
            cout << endl;
            cout<< "Ya se encuentra agregada una estacion en esa ubicacion GPS"<< endl;
            cout << endl;
            cout << endl;
            Duplicada = true;
            break;
        }
        else if(Estaciones[i].getIdentificador() == nuevaEstacion.getIdentificador()){
            cout << endl;
            cout << endl;
            cout<< "Ya se encuentra agregada una estacion con ese identificador"<< endl;
            cout << endl;
            cout << endl;
            Duplicada = true;
            break;
        }

    }
    if(!Duplicada){
        if (cantidadEstaciones == capacidadEstaciones) {
            redimensionar(Estaciones,capacidadEstaciones,cantidadEstaciones);
        }
        nuevaEstacion.agregarSurtidor(surtidorDefecto1);
        nuevaEstacion.agregarSurtidor(surtidorDefecto2);
        Estaciones[cantidadEstaciones] = nuevaEstacion;
        cantidadEstaciones++;
        cout<< "La estacion fue agregada correctamente."<< endl;

    }
}


void redNacional::eliminarEstacion(int &indice){
    bool estadoSurtidor=false;
    short unsigned int cantidadSurtidores = 0;

    cantidadSurtidores = Estaciones[indice].getCantidadSurtidores();

    for(int k = 0;k<cantidadSurtidores;k++){
        estadoSurtidor = Estaciones[indice].getSurtidores()[k].getActivo();
        if(estadoSurtidor == true){
            cout<<"La estacion tiene surtidores activos"<<endl;
                k = cantidadSurtidores;
        }
    }

    if(estadoSurtidor == false){
        for (int j = indice; j < cantidadEstaciones - 1; j++) {
            Estaciones[j] = Estaciones[j + 1];  // Desplaza todas las estaciones una posición a la izquierda
        }
                cantidadEstaciones--;
                cout << "La estacion ha sido eliminada correctamente." << endl;
    }

}


void redNacional::mostrarEstaciones() const {

    cout<<"-----------------------------" << endl;
    cout << "Numero de estaciones a nivel Nacional: "<< cantidadEstaciones<< endl;
    for (int i = 0; i < cantidadEstaciones; i++) {
        Estaciones[i].mostrarInformacion();
    }
    cout<<"-----------------------------" << endl;
}

void redNacional::montoVentasNacional(){
    unsigned long int montoRegular(0),montoPremium(0),montoEcoExtra(0),monto(0);
    string tipoCombustible;
    short int cantidadSurtidores(0);
    unsigned int numVentas(0);

    for(int i = 0; i<cantidadEstaciones;i++){
        cantidadSurtidores = Estaciones[i].getCantidadSurtidores();
        for(int k=0;k<cantidadSurtidores;k++){
            numVentas = Estaciones[i].getSurtidores()[k].getNumVentas();
            for(int w = 0;w<numVentas;w++){
                tipoCombustible = Estaciones[i].getSurtidores()[k].getVentas()[w].getCategoriaCombustible();
                monto =  Estaciones[i].getSurtidores()[k].getVentas()[w].getCantidadDinero();

                if(tipoCombustible=="Regular"){
                    montoRegular += monto;
                }

                else if(tipoCombustible=="Premium"){
                    montoPremium += monto;
                }

                else{
                    montoEcoExtra += monto;
                }

            }
        }

    }

    cout<<"Monto total de ventas de combustible Regular vendido a nivel nacional es: $"<<montoRegular<<endl;
    cout<<"Monto total de ventas de combustible Premium vendido a nivel nacional es: $"<<montoPremium<<endl;
    cout<<"Monto total de ventas de combustible EcoExtra vendido a nivel nacional es: $"<<montoEcoExtra<<endl;
    cout<<endl;


}

void redNacional::fijarPreciosCombustible(){
    unsigned int precio = 0;

    cout<<"Ingrese el precio de combustible Regular en la Region Norte: ";
    cin>>precio;
    preciosCombustible[0] = precio;

    cout<<"Ingrese el precio de combustible Premium en la Region Norte: ";
    cin>>precio;
    preciosCombustible[1] = precio;

    cout<<"Ingrese el precio de combustible EcoExtra en la Region Norte: ";
    cin>>precio;
    preciosCombustible[2] = precio;

    cout<<"Ingrese el precio de combustible Regular en la Region Centro: ";
    cin>>precio;
    preciosCombustible[3] = precio;

    cout<<"Ingrese el precio de combustible Premium en la Region Centro: ";
    cin>>precio;
    preciosCombustible[4] = precio;

    cout<<"Ingrese el precio de combustible EcoExtra en la Region Centro: ";
    cin>>precio;
    preciosCombustible[5] = precio;

    cout<<"Ingrese el precio de combustible Regular en la Region Sur: ";
    cin>>precio;
    preciosCombustible[6] = precio;

    cout<<"Ingrese el precio de combustible Premium en la Region Sur: ";
    cin>>precio;
    preciosCombustible[7] = precio;

    cout<<"Ingrese el precio de combustible EcoExtra en la Region Sur: ";
    cin>>precio;
    preciosCombustible[8] = precio;
}


void redNacional::redimensionar(estacion*& arreglo, unsigned short int& capacidadEstaciones,unsigned short int estaciones)
{

    int nuevaCapacidad = capacidadEstaciones + 50;
    estacion* nuevoArreglo = new estacion[nuevaCapacidad];
    for(int i= 0;i < estaciones;i++)
    {
        nuevoArreglo[i] = arreglo[i];
    }
    delete[] arreglo;
    arreglo = nuevoArreglo;
    capacidadEstaciones = nuevaCapacidad;
}

bool redNacional::encontarEstacion(string _codigoIdentificador, int &indice)
{
    for(int i = 0;i<cantidadEstaciones;i++){
        if(Estaciones[i].getIdentificador() == _codigoIdentificador){
            indice = i;
            return true;
        }
    }

    cout<<"La estacion ingresada no se encuentra registrada"<<endl;
    return false;
}

void redNacional::modificarEstacion(int &indice, short unsigned int &opc1, redNacional &red){
    if(opc1==1){
        cout<< "Ingrese el codigo del SURTIDOR: ";
        string codigoSurtidor;
        getline(cin,codigoSurtidor);
        cout<< "Ingrese el modelo del SURTIDOR: ";
        string modeloSurtidor;
        getline(cin,modeloSurtidor);
        string estado;
        while(true){
            cout<< "Ingrese el estado del SURTIDOR, 1 si esta ACTIVO o 2 si esta DESACTIVADO: ";
            getline(cin, estado);
            if (estado == "1" || estado == "2") {
                break;
            } else {
                cout << "Entrada invalida. Por favor, ingrese una de las opciones permitidas." << endl;
            }

        }
        bool ESTADO;
        if(estado== "1"){
            ESTADO = true;

        }
        else{
            ESTADO = false;
        }
        surtidor nuevoSurtidor(codigoSurtidor,modeloSurtidor,ESTADO);

        Estaciones[indice].agregarSurtidor(nuevoSurtidor);
    }

    else if(opc1 == 2){
        cout<< "Ingrese el codigo del SURTIDOR QUE DESEA ELIMINAR: ";
        string codigoSurtidor;
        getline(cin,codigoSurtidor);
        Estaciones[indice].eliminarSurtidor(codigoSurtidor);
    }

    else if(opc1 == 3){
        cout << "Ingrese el codigo del SURTIDOR QUE DESEA ACTIVAR: ";
        string codigoSurtidor;
        getline(cin,codigoSurtidor);
        Estaciones[indice].modificarSurtidor(codigoSurtidor);
    }

    else if(opc1 == 4){
        cout << "Ingrese el codigo del SURTIDOR QUE DESEA DESACTIVAR: ";
        string codigoSurtidor;
        getline(cin,codigoSurtidor);
        Estaciones[indice].modificarSurtidor(codigoSurtidor);
    }

    else if(opc1 == 5){
        Estaciones[indice].consultarTransacciones();
    }

    else if(opc1 == 6){
        Estaciones[indice].cantidadesVendidas();
    }

    else if(opc1 == 7){
        Estaciones[indice].simularVenta(red);
    }

    else if(opc1==9){
        Estaciones[indice].verificarFugas();
    }

}

redNacional::~redNacional(){
    delete[] Estaciones;
    Estaciones = NULL;
}
