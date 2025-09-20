/*
  * Proyecto Filtro de Vuelos por precio
  * Víctor Adrián García Galván
  * A01713062
  * 19/09/2025
*/

/**
  * Descripción del Proyecto
  * Este proyecto para la clase de Programación de Estructuras de Datos y 
  * Algoritmos Fundamentales modela y muestra una lista de vuelos con datos 
  * básicos (ID, fecha, origen, destino, hora de salida/llegada, aerolínea y 
  * precio). Al iniciar, se cargan ejemplos predeterminados para evitar 
  * dependencias externas. Los vuelos se almacenan en un vector y se pueden 
  * ordenar por precio en forma ascendente o descendente usando std::sort 
  * con comparadores estáticos, sin modificar el orden original (se ordena una 
  * copia para fines de visualización).
**/

#include <iostream>
#include <string>
#include "Vuelos.h"


void menu() {
    std::cout << "\n================= Menu =================\n" << std::endl;
    std::cout << "1. Agregar un Vuelo\n" << std::endl;
    std::cout << "2. Mostrar Vuelos\n" << std::endl;
    std::cout << "3. Ordenar por PRECIO\n" << std::endl;
    std::cout << "4. Salir\n" << std::endl;
}


int main() {

    Vuelos sistema;
    sistema.creaVuelosEjemplos();


    int opcion = 0;
    while (opcion != 4) {
        menu();
        std::cin >> opcion;

        if (opcion == 1) {
            int id; 
            std::string f,o,d,s,l,a; 
            double p;

            std::cout << "\nID: "; 
            std::cin >> id;
            std::cout << "Fecha (YYYY-MM-DD): "; 
            std::cin >> f;
            std::cin.ignore();
            std::cout << "Origen: "; 
            std::getline(std::cin, o);
            std::cout << "Destino: "; 
            std::getline(std::cin, d);
            std::cout << "Sale (HH:MM): "; 
            std::cin >> s;
            std::cout << "Llega (HH:MM): "; 
            std::cin >> l;
            std::cin.ignore();
            std::cout << "Aerolínea: "; 
            std::getline(std::cin, a);
            std::cout << "Precio (MXN): "; 
            std::cin >> p;
            sistema.agregaVuelo(Vuelo(id, f, o, d, s, l, a, p));
            std::cout << "\nVuelo agregado." << std::endl;
        }
        else if (opcion == 2) {
            sistema.mostrarVuelos();
        }
        else if (opcion == 3) {
            int t; 
            std::cout << "\n¿Tipo? (1 ascendente / 2 descendente): "; 
            std::cin >> t;
            sistema.ordenarPorPrecio(t == 1);
        }
        else if (opcion == 4) {
            break;
        }
        else {
            std::cout << "\nEntrada invalida. Intenta de nuevo." << std::endl;
        }
    }


    return 0;
}