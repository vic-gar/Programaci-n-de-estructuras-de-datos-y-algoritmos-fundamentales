/*
    Proyecto Sistema de Vuelos
    Autor: Víctor Adrián García Galván
    Fecha: 20/10/2025
    versión: 2
    Descripción:
    Se cargarán ejemplos antes de inicializar el programa para no tener que 
    implementarlos si se busca eficiencia.
    Los objetos se almacenan en un vector para su posterior uso en los métodos 
    de ordenamiento y además en un AVL para la posterior busqueda, acceso, 
    inserción y borrado de vuelos.
*/
#ifndef VUELOS_H_
#define VUELOS_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "vuelo.h"
#include "avl.h"

class Vuelos {
  private:
    AVL<Vuelo> avl;
    std::vector<Vuelo> listaCSV;

  public:
    // Constuctr de la clase Vuelos
    Vuelos();

    void cargarCSV();

    //Métodos de la clase Vuelos
    void mostrarOriginal() const;
    void ordenarAsc() const;
    void ordenarDesc() const;

    void agregarVuelo();
    bool eliminarVuelo();
};

//Constructor por default de la clase Vuelos
Vuelos::Vuelos() { 
  cargarCSV(); 
}

//Metodo para cargar vuelos desde un CSV
void Vuelos::cargarCSV() {
    std::ifstream file("vuelos.csv");
    if (!file) {
        std::cout << "No se pudo abrir 'vuelos.csv'.\n";
        return;
    }

    listaCSV.clear();

    std::string sid, fecha, origen, destino, sale, llega, aerolinea, sprecio;
    while ( std::getline(file, sid, ',') &&
            std::getline(file, fecha, ',') &&
            std::getline(file, origen, ',') &&
            std::getline(file, destino, ',') &&
            std::getline(file, sale, ',') &&
            std::getline(file, llega, ',') &&
            std::getline(file, aerolinea, ',') &&
            std::getline(file, sprecio) ) {

        int id = std::stoi(sid);
        double precio = std::stod(sprecio);
        listaCSV.emplace_back(id, fecha, origen, destino, sale, llega, aerolinea, precio);
    }
    file.close();

    avl = AVL<Vuelo>();
    for (const auto& v : listaCSV) avl.add(v);

    std::cout << "Cargados " << listaCSV.size() << " vuelos.\n";
}

//Metodo para mostrar los vuelos guardados en el CSV
void Vuelos::mostrarOriginal() const {
  std::cout << "\n--- Vuelos en el sistema ---\n";
  for (size_t i = 0; i < listaCSV.size(); ++i) {
    const Vuelo& v = listaCSV[i];
    std::cout << v << "\n";
  }
}

//Metodo para ordenar los vuelos de manera ascendente
void Vuelos::ordenarAsc() const{
  std::cout << "\n--- Vuelos por precio ascendente ---\n";
  std::vector<Vuelo> copia = listaCSV;

  std::sort(copia.begin(), copia.end());

  for (const auto &v : copia) {
    std::cout << v << "\n";
  }
}

//Metodo para ordenar los vuelos de manera descendente
void Vuelos::ordenarDesc() const{
  std::cout << "\n--- Vuelos por precio descendente ---\n";
  std::vector<Vuelo> copia = listaCSV;

  std::sort(copia.begin(), copia.end(), std::greater<Vuelo>());

  for (const auto &v : copia) {
    std::cout << v << "\n";
  }
}

//Metodo para agregar un nuevo Vuelo a nuestro AVL y al vector auxiliar para ordenar
void Vuelos::agregarVuelo() {
  int id; std::string fecha, origen, destino, sale, llega, aerolinea; double precio;

  std::cout << "ID: "; 
  std::cin >> id;
  std::cout << "Fecha (dd/mm/aaaa): "; 
  std::cin >> fecha;
  std::cout << "Origen: "; 
  std::cin >> origen;
  std::cout << "Destino: "; 
  std::cin >> destino;
  std::cout << "Sale (hh:mm): "; 
  std::cin >> sale;
  std::cout << "Llega (hh:mm): "; 
  std::cin >> llega;
  std::cout << "Aerolínea: "; 
  std::cin >> aerolinea;
  std::cout << "Precio: "; 
  std::cin >> precio;

  Vuelo v(id, fecha, origen, destino, sale, llega, aerolinea, precio);
  listaCSV.push_back(v);
  avl.add(v);
  std::cout << "Vuelo agregado.\n";
}

//Metodo para eliminar un Vuelo a nuestro AVL y al vector auxiliar para ordenar
bool Vuelos::eliminarVuelo() {
  int id;
  std::cout << "ID del vuelo a eliminar: ";
  std::cin >> id;

  for (auto it = listaCSV.begin(); it != listaCSV.end(); ++it) {
    if (it->get_id() == id) {
      Vuelo borr = *it;
      avl.remove(borr);
      listaCSV.erase(it);
      std::cout << "Vuelo eliminado.\n";
      return true;
    }
  }
  std::cout << "No se encontró ese ID.\n";
  return false;
}


#endif // VUELOS_H_