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

    precioNorte[0] = 13050;
    precioNorte[1] = 17500;
    precioNorte[2] = 21300;

    precioSur[0] = 11600;
    precioSur[1] = 16900;
    precioSur[2] = 20100;

    precioCentro[0] = 14500;
    precioCentro[1] = 18300;
    precioCentro[2] = 22400;

}

void redNacional::agregarEstacion(estacion nuevaEstacion)
{
        if (cantidadEstaciones == capacidadEstaciones) {
            redimensionar(Estaciones,capacidadEstaciones,cantidadEstaciones);
        }
        Estaciones[cantidadEstaciones] = nuevaEstacion;
        cantidadEstaciones++;
        cout<< "La estacion fue agregada correctamente."<< endl;

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
        cout << "La estación no se encontra registrada." << endl;
    }
}



void redNacional::mostrarEstaciones() const {
    // Imprimir estaciones en la región Norte
    cout<<"-----------------------------" << endl;
    cout << "Numero de estaciones a nivel Nacional: "<< cantidadEstaciones<< endl;
    for (int i = 0; i < cantidadEstaciones; i++) {
        Estaciones[i].mostrarInformacion(); // Supongo que tienes un método para mostrar la info en la clase 'estacion'
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
    precioNorte[0] = precio;

    cout<<"Ingrese el precio de combustible Premium en la Region Norte: ";
    cin>>precio;
    precioNorte[1] = precio;

    cout<<"Ingrese el precio de combustible EcoExtra en la Region Norte: ";
    cin>>precio;
    precioNorte[2] = precio;

    cout<<"Ingrese el precio de combustible Regular en la Region Centro: ";
    cin>>precio;
    precioCentro[0] = precio;

    cout<<"Ingrese el precio de combustible Premium en la Region Centro: ";
    cin>>precio;
    precioCentro[1] = precio;

    cout<<"Ingrese el precio de combustible EcoExtra en la Region Centro: ";
    cin>>precio;
    precioCentro[2] = precio;

    cout<<"Ingrese el precio de combustible Regular en la Region Sur: ";
    cin>>precio;
    precioSur[0] = precio;

    cout<<"Ingrese el precio de combustible Premium en la Region Sur: ";
    cin>>precio;
    precioSur[1] = precio;

    cout<<"Ingrese el precio de combustible EcoExtra en la Region Sur: ";
    cin>>precio;
    precioSur[2] = precio;
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

redNacional::~redNacional(){
    delete[] Estaciones;
}
