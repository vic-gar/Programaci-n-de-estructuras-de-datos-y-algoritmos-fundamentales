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
#include "Vuelos.h"

static void menu() {
    std::cout << "\n================= Menu =================\n";
    std::cout << "1. Mostrar vuelos\n";
    std::cout << "2. Ordenar ascendente (precio)\n";
    std::cout << "3. Ordenar descendente (precio)\n";
    std::cout << "4. Agregar un vuelo\n";
    std::cout << "5. Eliminar un vuelo (por ID)\n";
    std::cout << "6. Buscar vuelo por ID\n";
    std::cout << "7. Salir (se guardará el nuevo csv)\n";
    std::cout << "\n Elige una opcion: ";
}

int main() {
    Vuelos sistema;
    int opcion = 0;

    while (true) {
        menu();

        std::cin >> opcion;

        if (opcion == 1) {
            std::cout << "\n===== Mostrar Vuelos =====\n";
            sistema.mostrarOriginal();
        } 
        else if (opcion == 2) {
            std::cout << "\n===== Orden ascendente por precio =====\n";
            sistema.ordenarAsc();
        } 
        else if (opcion == 3) {
            std::cout << "\n===== Orden descendente por precio =====\n";
            sistema.ordenarDesc();
        } 
        else if (opcion == 4) {
            sistema.agregarVuelo();
        } 
        else if (opcion == 5) {
            if (!sistema.eliminarVuelo()) {
                std::cout << "No se encontró ese ID.\n";
            }
        } 
        else if (opcion == 6) {
            int id;
            std::cout << "ID del vuelo a buscar: ";
            std::cin >> id;

            Vuelo encontrado(0, "", "", "", "", "", "", 0);

            if (sistema.buscarPorID(id, encontrado)) {
                std::cout << "\n--- Vuelo encontrado ---\n";
                std::cout << encontrado << "\n";
            } else {
                std::cout << "No existe un vuelo con ese ID.\n";
            }
        }
        else if (opcion == 7) {
            sistema.guardarCSV();
            std::cout << "Saliendo...\n";
            break;
        } 
        else {
            std::cout << "Opción inválida. Intenta de nuevo.\n";
        }
    }

    return 0;
}
