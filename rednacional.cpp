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
    bool Duplicada = false;
    for(int i = 0;i < cantidadEstaciones;i++){
        if(Estaciones[i].getUbicacionGPS() == nuevaEstacion.getUbicacionGPS()){
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout<< "Ya encuentra agregada una estacion en esa ubicacion GPS"<< endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            Duplicada = true;
            break;
        }
        else if(Estaciones[i].getIdentificador() == nuevaEstacion.getIdentificador()){
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout<< "Ya encuentra agregada una estacion con ese identificador"<< endl;
            cout << endl;
            cout << endl;
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
        Estaciones[cantidadEstaciones] = nuevaEstacion;
        cantidadEstaciones++;
        cout<< "La estacion fue agregada correctamente."<< endl;

    }
}

void redNacional::eliminarEstacion(estacion estacionEliminar) {
    bool encontrado = false;

    for (int i = 0; i < cantidadEstaciones; i++) {
        if (Estaciones[i] == estacionEliminar) {
            encontrado = true;
            for (int j = i; j < cantidadEstaciones - 1; j++) {
                Estaciones[j] = Estaciones[j + 1];  // Desplaza todas las estaciones una posición a la izquierda
            }
            cantidadEstaciones--;
            cout << "La estacion ha sido eliminada correctamente." << endl;
            return;
        }
    }

    if(encontrado == false){
        cout << "La estación no se encuentra registrada." << endl;
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
    int numVentas(0);

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

    cout<<"Monto total de ventas de combustible Regular: "<<montoRegular<<endl;
    cout<<"Monto total de ventas de combustible Premium: "<<montoPremium<<endl;
    cout<<"Monto total de ventas de combustible EcoExtra: "<<montoEcoExtra<<endl;
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

estacion redNacional::encontarEstacion(estacion estacion1)
{
    bool encontrada = false;
    for(int i = 0; i < cantidadEstaciones; i++){
        if(Estaciones[i]==estacion1 ){
            return Estaciones[i];
            encontrada = true;
        }
    }
    if(encontrada == false ){
        cout << "No hay un estacion registrada con el nombre y el identificador ingresados" << endl;
    }

}

redNacional::~redNacional(){
    delete[] Estaciones;
}
