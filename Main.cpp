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

    estacion estacion1("La Grande","5840","Diego","Centro","13975449076");
    estacion1.capacidadTanque();
    surtidor surtidor1("ABC123", "ModeloX", true);
    surtidor surtidor2("ABC321","MODELY",true);
    surtidor surtidor3("ABC312","MODELZ",true);
    surtidor surtidor4("ABC234", "ModeloX", true);
    surtidor surtidor5("ABC432","MODELY",true);
    surtidor surtidor6("ABC423","MODELZ",true);
    Venta venta1("9/10/2024","9:28",3.4,"Regular","Efectivo","1002969042",666);
    Venta venta2("9/10/2024","10:28",1.5,"Premium","Efectivo","11112969042",30000);
    Venta venta3("10/10/2024","7:31",3,"EcoExtra","Efectivo","1002969042",50000);
    Venta venta4("11/10/2024","12:16",3,"EcoExtra","Efectivo","103681573",50000);
    Venta venta5("9/10/2024","9:28",3.4,"Regular","Efectivo","1002969042",777);
    Venta venta6("9/10/2024","10:28",1.5,"Premium","Efectivo","11112969042",30000);
    Venta venta7("10/10/2024","7:31",3,"Premium","Efectivo","1002969042",50000);
    Venta venta8("11/10/2024","12:16",3,"EcoExtra","Efectivo","103681573",50000);

    surtidor1.agregarVenta(venta1);
    surtidor1.agregarVenta(venta4);
    surtidor3.agregarVenta(venta2);
    surtidor2.agregarVenta(venta3);
    surtidor6.agregarVenta(venta5);
    surtidor4.agregarVenta(venta8);
    surtidor4.agregarVenta(venta6);
    surtidor5.agregarVenta(venta7);

    estacion1.agregarSurtidor(surtidor1);
    estacion1.agregarSurtidor(surtidor2);
    estacion1.agregarSurtidor(surtidor3);
    estacion1.capacidadTanque();
    string infoRegion = estacion1.getRegion();
    pais.agregarEstacion(estacion1);
    //segunda estacion
    estacion estacion2("La Grande2","4058","Diego2","Norte","358958306");
    estacion2.agregarSurtidor(surtidor4);
    estacion2.agregarSurtidor(surtidor5);
    estacion2.agregarSurtidor(surtidor6);
    estacion2.capacidadTanque();
    pais.agregarEstacion(estacion2);

    imprimirTabla(" Bienvenido a la red nacional de gasolineras de :" + nombre);

    unsigned short int opc;

    do {
        imprimirTabla("M E N U");
        cout << " 1. Gestion de red "<< endl;
        cout << " 2. Gestion de estacion de servicio"<< endl;
        cout << " 3. Verificacion de fugas"<< endl;
        cout << " 4. Salir" << endl;
        cout << "ELIJA LA OPCION QUE DESEE: ";
        cin >> opc;

        switch (opc) {
        case 1:
        {
            unsigned short int opc1;
            do{

                imprimirTabla("GESTION DE RED");
                cout << " 1. Agregar una estacion"<< endl;
                cout << " 2. Eliminar una estacion"<< endl;
                cout << " 3. Calcular el monto total de las ventas en cada E/S del pais, discriminado por categoria de combustible."<< endl;
                cout << " 4. Fijar los precios del combustible para toda la red."<< endl;
                cout << " 5. Volver al MENU anterior" << endl;
                cout << "ELIJA LA OPCION QUE DESEE: ";
                cin >> opc1;
                switch (opc1) {
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
                        cout <<"Ingrese la region, SOLO SE PUEDE INGRESAR Norte, Sur o Centro tal como se ve en pantalla "<< endl;
                        imprimirTabla("Norte");
                        imprimirTabla("Centro");
                        imprimirTabla("Sur");
                        cout << "Ingrese la region: ";
                        getline(cin, region);
                        if (region == "Norte" || region == "Sur" || region == "Centro") {
                            break;
                        } else {
                            cout << "Entrada invalida. Por favor, ingrese una de las opciones permitidas." << endl;
                        }

                    }

                    string ubicacionGPS;
                    cout << "Ingrese la ubicacion la Ubicacion GPS: ";
                    getline(cin,ubicacionGPS);
                    estacion nuevaEstacion(nombre1,codigo,gerente,region,ubicacionGPS);
                    nuevaEstacion.capacidadTanque();
                    pais.agregarEstacion(nuevaEstacion);
                    pais.mostrarEstaciones();
                    break;
                }
                case 2:
                {
                    bool encontrado = false;
                    int indice = 0;
                    cout << "Ha seleccionada la opcion ELIMINAR UNA ESTACION" << endl;
                    string codigo;
                    cout << "Ingrese el codigo identificador: ";
                    cin.ignore();
                    getline(cin,codigo);

                    encontrado = pais.encontarEstacion(codigo,indice);

                    if(encontrado == true){
                        pais.eliminarEstacion(indice);
                        pais.mostrarEstaciones();
                    }
                    break;
                }
                case 3:
                {
                    cout << "Ha elegido la opcion Calcular el monto total de las ventas en cada E/S del pais, discriminado por categoria de combustible."<< endl;
                    pais.montoVentasNacional();
                    break;
                }
                case 4:
                {
                    cout << "Ha elegido la opcion Fijar los precios del combustible para toda la red."<< endl;
                    pais.fijarPreciosCombustible();
                    break;
                }
                case 5:
                {
                    cout << "Saliendo de la opcion GESTION DE RED"<< endl;
                    cout << "Volviendo al MENU anterior"<< endl;
                    break;
                }
                default:
                    cout << "Opción no válida.\n";
                    break;
                }
                cout << endl;
            }while(opc1 != 5);  // El ciclo continúa hasta que el usuario elija salir

            break;
        }
        case 2:
        {
            unsigned short int opc1;
            do{
                imprimirTabla("GESTION DE ESTACION DE SERVICIO");
                cout << " 1. Agregar un surtidor a una estacion"<< endl;
                cout << " 2. Eliminar un surtidor de una  estacion"<< endl;
                cout << " 3. Activar un surtidor de una estacion"<< endl;
                cout << " 4. Desactivar un surtidor de una estacion"<< endl;
                cout << " 5. Consultar el historico de transacciones de cada surtidor de la E/S"<< endl;
                cout << " 6. Reportar la cantidad la cantidad de litros vendidos segun cada categoria de combustible" << endl;
                cout << " 7. Simular una venta de combustible"<< endl;
                cout << " 8. Volver al MENU anterior" << endl;
                cout << "ELIJA LA OPCION QUE DESEE: ";
                cin >> opc1;

                switch (opc1) {
                case 1:
                {
                    bool encontrado = false;
                    int indice = 0;
                    cout << "Ha seleccionado la opcion  AGREGAR UN SURTIDOR A LA ESTACION "<< endl;
                    string codigo;
                    cout << "Ingrese el codigo identificador de la ESTACION: ";
                    cin.ignore();
                    getline(cin,codigo);

                    encontrado = pais.encontarEstacion(codigo,indice);

                    if(encontrado==true){
                        pais.modificarEstacion(indice,opc1,pais);
                    }

                    break;
                }
                case 2:
                {
                    bool encontrado = false;
                    int indice = 0;
                    cout << "Ha seleccionada la opcion ELIMINAR UN SURTIDOR DE LA ESTACION" << endl;
                    string codigo;
                    cout << "Ingrese el codigo identificador de la ESTACION DONDE SE ENCUENTRA EL SURTIDOR: ";
                    cin.ignore();
                    getline(cin,codigo);

                    encontrado = pais.encontarEstacion(codigo,indice);

                    if(encontrado == true){
                        pais.modificarEstacion(indice,opc1,pais);

                    }

                    break;
                }
                case 3:
                {
                    bool encontrado = false;
                    int indice = 0;
                    cout << "Ha seleccionado la opcion ACTIVAR SURTIDOR"<< endl;
                    string codigo;
                    cout << "Ingrese el codigo identificador de la ESTACION DONDE SE ENCUENTRA EL SURTIDOR: ";
                    cin.ignore();
                    getline(cin,codigo);

                    encontrado = pais.encontarEstacion(codigo,indice);

                    if(encontrado == true){
                        pais.modificarEstacion(indice,opc1,pais);
                    }

                    break;
                }
                case 4:
                {
                    bool encontrado = false;
                    int indice = 0;
                    cout << "Ha seleccionado la opcion DESACTIVAR SURTIDOR"<< endl;
                    string codigo;
                    cout << "Ingrese el codigo identificador de la ESTACION DONDE SE ENCUENTRA EL SURTIDOR: ";
                    cin.ignore();
                    getline(cin,codigo);

                    encontrado = pais.encontarEstacion(codigo,indice);

                    if(encontrado == true){
                        pais.modificarEstacion(indice,opc1,pais);
                    }

                    break;
                }
                case 5:{
                    cout<<"Ha seleccionado la opcion CONSULTAR HISTORICO DE TRANSACCIONES DE CADA SURTIDOR"<<endl;
                    bool encontrado = false;
                    int indice = 0;
                    string codigo;
                    cout << "Ingrese el codigo identificador de la ESTACION: ";
                    cin.ignore();
                    getline(cin,codigo);

                    encontrado = pais.encontarEstacion(codigo,indice);

                    if(encontrado == true){
                        pais.modificarEstacion(indice,opc1,pais);
                    }

                    break;
                }

                case 6:{
                    cout << "Ha seleccionado la opcion Reportar la cantidad la cantidad de litros vendidos segun cada categoria de combustible "<< endl;
                    bool encontrado = false;
                    int indice = 0;
                    string codigo;
                    cout << "Ingrese el codigo identificador de la ESTACION: ";
                    cin.ignore();
                    getline(cin,codigo);

                    encontrado = pais.encontarEstacion(codigo,indice);

                    if(encontrado == true){
                        pais.modificarEstacion(indice,opc1,pais);
                    }
                    break;
                }
                case 7:{

                    cout << "Ha seleccionado la opcion SIMULAR VENTA"<< endl;
                    bool encontrado=false;
                    int indice = 0;
                    string codigo;
                    cout << "Ingrese el codigo identificador de la ESTACION: ";
                    cin.ignore();
                    getline(cin,codigo);

                    encontrado = pais.encontarEstacion(codigo,indice);

                    if(encontrado == true){
                        pais.modificarEstacion(indice,opc1,pais);
                    }

                    break;
                }
                case 8:
                {
                    cout << "Saliendo de la opcion GESTION DE ESTACION DE SERVICIO"<< endl;
                    cout << "Volviendo al MENU anterior"<< endl;
                    break;
                }
                default:
                    cout << "Opción no válida";
                    break;
                }
                cout << endl;



            }while(opc1 != 8);

            break;
        }
        case 3:
        {
            bool encontrado = false;
            int indice = 0;
            short unsigned int opc1 = 9;
            imprimirTabla("SISTEMA NACIONAL DE VERIFICACION DE FUGAS");
            string codigo;
            cout << "Ingrese el codigo identificador de la ESTACION: ";
            cin.ignore();
            getline(cin,codigo);
            encontrado = pais.encontarEstacion(codigo,indice);

            if(encontrado == true){
                pais.modificarEstacion(indice,opc1,pais);
            }

            break;
        }
        case 4:
        {
            imprimirTabla("SALIENDO DEL SISTEMA");
            break;
        }
        default:
            cout << "Opción no válida.\n";
            break;
        }

        cout << endl;

    } while (opc != 4);  // El ciclo continúa hasta que el usuario elija salir

    return 0;
}

void imprimirTabla(const string& mensaje) {
    int ancho = mensaje.length() + 4; // Calcular el ancho de la tabla con espacio adicional
    string lineaHorizontal(ancho, '-'); // Crear una línea horizontal

    cout << "+" << lineaHorizontal << "+" << endl;
    cout << "|  " << mensaje << "  |" << endl;
    cout << "+" << lineaHorizontal << "+" << endl;


}
