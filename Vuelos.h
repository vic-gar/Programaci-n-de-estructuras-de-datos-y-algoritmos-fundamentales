/*
    Proyecto Sistema de Vuelos
    Autor: Víctor Adrián García Galván
    Fecha: 19/09/2025
    versión: 1
    Descripción:
    Se crearán ejemplos antes de inicializar el programa para no tener que 
    implementarlos si se busca eficiencia.
    Los objetos se almacenan en un vector para su posterior uso en los métodos 
    de ordenamiento
*/
#ifndef VUELOS_H_
#define VUELOS_H_

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "Vuelo.h"

class Vuelos {
  private:
    std::vector<Vuelo> vuelos;

    static bool cmpPrecioAsc(const Vuelo &a, const Vuelo &b);
    static bool cmpPrecioDesc(const Vuelo &a, const Vuelo &b);  

  public:
    // Constuctr de la clase Vuelos
    Vuelos();

    //Métodos de la clase Vuelos
    void creaVuelosEjemplos();
    void agregaVuelo(const Vuelo &v);
    void mostrarVuelos() const;

    void ordenarPorPrecio(bool asc) const;
};

//Constructor por default
Vuelos::Vuelos() {}

// Coparadores para poder utilizar en sort(), indican si es ascendente o descendente
bool Vuelos::cmpPrecioAsc(const Vuelo &a, const Vuelo &b) {
  return a.get_precio() < b.get_precio();
}

bool Vuelos::cmpPrecioDesc(const Vuelo &a, const Vuelo &b) {
  return a.get_precio() > b.get_precio();
}

//Crea varios ejemplos de vuelos para que el usuario no tenga que generarlos al probar el programa
void Vuelos::creaVuelosEjemplos() {
    vuelos.push_back(Vuelo(1007, "2025-09-21", "Ciudad de México", "Cancún", "13:45", "16:05", "VivaAerobus", 1375));
    vuelos.push_back(Vuelo(1001, "2025-09-20", "Ciudad de México", "Cancún", "06:00", "08:20", "Aeroméxico", 1225));
    vuelos.push_back(Vuelo(1012, "2025-09-22", "Ciudad de México", "Cancún", "17:20", "19:40", "Interjet", 1500));
    vuelos.push_back(Vuelo(1005, "2025-09-21", "Ciudad de México", "Cancún", "06:00", "08:20", "Aeroméxico", 1325));
    vuelos.push_back(Vuelo(1010, "2025-09-22", "Ciudad de México", "Cancún", "09:30", "11:50", "Volaris", 1450));
    vuelos.push_back(Vuelo(1003, "2025-09-20", "Ciudad de México", "Cancún", "13:45", "16:05", "VivaAerobus", 1275));
    vuelos.push_back(Vuelo(1009, "2025-09-22", "Ciudad de México", "Cancún", "06:00", "08:20", "Aeroméxico", 1425));
    vuelos.push_back(Vuelo(1008, "2025-09-21", "Ciudad de México", "Cancún", "17:20", "19:40", "Interjet", 1400));
    vuelos.push_back(Vuelo(1002, "2025-09-20", "Ciudad de México", "Cancún", "09:30", "11:50", "Volaris", 1250));
    vuelos.push_back(Vuelo(1011, "2025-09-22", "Ciudad de México", "Cancún", "13:45", "16:05", "VivaAerobus", 1475));
    vuelos.push_back(Vuelo(1004, "2025-09-20", "Ciudad de México", "Cancún", "17:20", "19:40", "Interjet", 1300));
    vuelos.push_back(Vuelo(1006, "2025-09-21", "Ciudad de México", "Cancún", "09:30", "11:50", "Volaris", 1350));
}

// Metodo para agregar un nuevo vuelo
void Vuelos::agregaVuelo(const Vuelo &v) {
  vuelos.push_back(v);
}

// Método para mostrar la lsita de todos los vuelos disponibles
void Vuelos::mostrarVuelos() const {
  std::cout << "\n==========================================" << std::endl;
  std::cout << "\n         Vuelos en el Sistema" << std::endl;
  std::cout << "\n==========================================" << std::endl;

  for (size_t i = 0; i < vuelos.size(); i++) {
    std::cout << vuelos[i].conv_str() << std::endl;
  }
}

//Método para ordenar los vuelos de menor a manyor precio o visceversa 
void Vuelos::ordenarPorPrecio(bool asc) const {
    if (vuelos.size() <= 1) {
        mostrarVuelos();
        return;
    }

    std::vector<Vuelo> copia = vuelos;

    if (asc) {
        std::sort(copia.begin(), copia.end(), cmpPrecioAsc);
    } else {
        std::sort(copia.begin(), copia.end(), cmpPrecioDesc);
    }

    std::cout << "\n Ordenado por PRECIO (" << (asc ? "ascendente" : "descendente") << ")" << std::endl;
    for (size_t i = 0; i < copia.size(); i++) {
        std::cout << copia[i].conv_str() << std::endl;
    }
}

#endif // VUELOS_H_