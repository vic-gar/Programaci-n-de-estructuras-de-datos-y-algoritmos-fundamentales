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

//Métodos fuera de la clase para el uso de std::sort por precio

//Metodo que funciona como helper para comparar por precio no por ID (Ascendente)
bool compararAsc(const Vuelo &a, const Vuelo &b) {
    if (a.get_precio() == b.get_precio())
        return a.get_id() < b.get_id();
    return a.get_precio() < b.get_precio();
}

//Metodo que funciona como helper para comparar por precio no por ID (Descendente)
bool compararDesc(const Vuelo &a, const Vuelo &b) {
    if (a.get_precio() == b.get_precio())
        return a.get_id() > b.get_id();
    return a.get_precio() > b.get_precio();
}

class Vuelos {
  private:
    AVL<Vuelo> avl;
    std::vector<Vuelo> listaCSV;

  public:
    // Constuctr de la clase Vuelos
    Vuelos();

    void cargarCSV();
    void guardarCSV() const;

    //Métodos de la clase Vuelos
    void mostrarOriginal() const;
    void ordenarAsc() const;
    void ordenarDesc() const;

    void agregarVuelo();
    bool eliminarVuelo();

    bool buscarPorID(int id, Vuelo &r) const;
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

//Método para guardar los vuelos en un nuevo csv
void Vuelos::guardarCSV() const {
    std::ofstream file("vuelos.csv");

    for (const auto &v : listaCSV) {
        file << v.get_id()        << ","
             << v.get_fecha()     << ","
             << v.get_origen()    << ","
             << v.get_destino()   << ","
             << v.get_sale()      << ","
             << v.get_llega()     << ","
             << v.get_aerolinea() << ","
             << v.get_precio()    << "\n";
    }

    file.close();
    std::cout << "Guardados " << listaCSV.size() << " vuelos en 'vuelos.csv'.\n";
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

  std::sort(copia.begin(), copia.end(), compararAsc);

  for (const auto &v : copia) {
    std::cout << v << "\n";
  }
}

//Metodo para ordenar los vuelos de manera descendente
void Vuelos::ordenarDesc() const{
  std::cout << "\n--- Vuelos por precio descendente ---\n";
  std::vector<Vuelo> copia = listaCSV;

  std::sort(copia.begin(), copia.end(), compararDesc);

  for (const auto &v : copia) {
    std::cout << v << "\n";
  }
}

//Metodo para agregar un nuevo Vuelo a nuestro AVL y al vector auxiliar para ordenar
void Vuelos::agregarVuelo() {
  int id; 
  std::string fecha, origen, destino, sale, llega, aerolinea; 
  double precio;

  std::cout << "ID del vuelo: ";
  std::cin >> id;

  std::cin.ignore();

  std::cout << "Fecha (DD/MM/YYYY): ";
  std::getline(std::cin, fecha);

  std::cout << "Origen: ";
  std::getline(std::cin, origen);

  std::cout << "Destino: ";
  std::getline(std::cin, destino);

  std::cout << "Hora de salida (HH:MM): ";
  std::getline(std::cin, sale);

  std::cout << "Hora de llegada (HH:MM): ";
  std::getline(std::cin, llega);

  std::cout << "Aerolinea: ";
  std::getline(std::cin, aerolinea);

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

//Metodo que busca un vuelo por medio de su ID
bool Vuelos::buscarPorID(int id, Vuelo &r) const {
    Vuelo node(id, "", "", "", "", "", "", 0);
    const Vuelo* ptr = avl.get(node);

    if (ptr == 0) {
        return false;
    }

    r = *ptr;
    return true;
}


#endif // VUELOS_H_

