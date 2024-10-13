#include <iostream>
#include "venta.h"
#include "surtidor.h"
#include "estacion.h"
#include <string.h>
#include "rednacional.h"
using namespace std;

void imprimirTabla(const string& mensaje);


int main()
{
    string nombre;
    cout<<"Ingrese el nombre de la red nacional: ";
    cin>> nombre;
    redNacional pais(nombre);

    string mensaje = " Bienvenido a la red nacional de gasolineras";
    imprimirTabla(mensaje);
    unsigned short int opc;
    do {
        string mensaje2 = "M E N U";
        imprimirTabla(mensaje2);
        cout << " 1 Agregar una estacion"<< endl;
        cout << " 2 Eliminar una estacion"<< endl;
        cout << " 3 Calcular el monto total de las ventas en cada E/S del pais, discriminado por categoría de combustible."<< endl;
        cout << " 4 Fijar los precios del combustible para toda la red."<< endl;
        cout << " 5 Agregar un surtidor a una estacion"<< endl;
        cout << " 6 Eliminar un surtidor de una  estacion"<< endl;
        cout << " 7 Activar un surtidor de una estacion"<< endl;
        cout << " 8 Desactivar un surtidor de una estacion"<< endl;
        cout << " 9 Consultar el historico de transacciones de cada surtidor de la E/S"<< endl;
        cout << " 10 Reportar la cantidad la cantidad de litros vendidos segun cada categoria de combustible" << endl;
        cout << " 11 Simular una venta de combustible"<< endl;
        cout << "12 Salir" << endl;
        cout << "ELIGA LA OPCION QUE DESEE: "<< endl;
        cin >> opc;

        switch (opc) {
        case 1:
        {
            cout << "Ha seleccionado la opcion  AGREGAR UNA ESTACION "<< endl;
            string nombre1;
            cout << "Ingrese el nombre de la estacion: ";
            cin.ignore();
            getline(cin,nombre1);
            string codigo;
            cout << "Ingrese el codigo identificador: ";
            getline(cin,codigo);
            string gerente;
            cout << "Ingrese el nombre del gerente: ";
            getline(cin,gerente);
            string region;
            while(true){
                cout <<"Ingrese la region, SOLO SE PUEDE INGRESAR Norte, Sur o Centro: ";
                getline(cin, region);
                if (region == "Norte" || region == "Sur" || region == "Centro") {
                    break;
                } else {
                    cout << "Entrada invalida. Por favor, ingrese una de las opciones permitidas." << endl;
                }

            }
            region;
            string ubicacionGPS;
            cout << "Ingrese la ubicacion la Ubicacion GPS: ";
            getline(cin,ubicacionGPS);
            estacion estacion1(nombre1,codigo,gerente,region,ubicacionGPS);
            pais.agregarEstacion(estacion1);
            pais.mostrarEstaciones();

            break;
        }
        case 2:
        {
            cout << "Opción 2 seleccionada.\n";
            break;
        }
        case 3:
        {
            cout << "Opción 3 seleccionada.\n";
            break;
        }
        case 4:
        {
            cout << "Opcion 4 seleccionada. \n";
            break;
        }
        default:
            cout << "Opción no válida.\n";
            break;
        }

        cout << endl;

    } while (opc != 12);  // El ciclo continúa hasta que el usuario elija salir

    return 0;
}

void imprimirTabla(const string& mensaje) {
    int ancho = mensaje.length() + 4; // Calcular el ancho de la tabla con espacio adicional
    string lineaHorizontal(ancho, '-'); // Crear una línea horizontal

    cout << "+" << lineaHorizontal << "+" << endl;
    cout << "|  " << mensaje << "  |" << endl;
    cout << "+" << lineaHorizontal << "+" << endl;


}
