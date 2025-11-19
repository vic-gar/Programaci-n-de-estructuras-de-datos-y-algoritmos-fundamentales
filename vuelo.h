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

#ifndef VUELO_H_
#define VUELO_H_

#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>

class Vuelo {
  private:
    int id;
    std::string fecha;
    std::string origen;
    std::string destino;
    std::string sale;
    std::string llega;
    std::string aerolinea;
    double precio;

  public:
    //Constructores de la clase Vuelo
    Vuelo() : id(0), precio(0.0) {}

    Vuelo(int _id, const std::string &f, const std::string &o, const std::string &d,
    const std::string &s, const std::string &l, const std::string &a, double p):
     id(_id), fecha(f), origen(o), destino(d), sale(s), llega(l), aerolinea(a), 
     precio(p) {}

    // Getters de la clase Vuelo
    int get_id() const {return id;}
    std::string get_fecha() const {return fecha;}
    std::string get_origen() const {return origen;}
    std::string get_destino() const {return destino;}
    std::string get_sale() const {return sale;}
    std::string get_llega() const {return llega;}
    std::string get_aerolinea() const {return aerolinea;}
    double get_precio() const {return precio;}

    // Métodos de la clase Vuelo
    std::string conv_str() const;

    bool operator<(const Vuelo& other) const;
    bool operator>(const Vuelo& other) const;
    bool operator==(const Vuelo& other) const; 

    friend std::ostream& operator<<(std::ostream& os, const Vuelo& v);
};

//Metdo para imprimir los datos de un vuelo.
std::string Vuelo::conv_str() const {
    std::stringstream ss;
    ss << "\nVuelo || ID: " << id << "\nFecha -> " << fecha << "\nOrigen -> " << origen
      << "\nDestino -> " << destino << "\nSale -> " << sale << "\nLlega -> " << llega
      << "\nAerolínea -> " << aerolinea << "\nPrecio -> $" << std::fixed << 
      std::setprecision(2) << precio; 
    return ss.str();
}

bool Vuelo::operator<(const Vuelo& other) const {
  return id < other.id;
}

bool Vuelo::operator>(const Vuelo& other) const {
  return id > other.id;
}

bool Vuelo::operator==(const Vuelo& other) const {
  return id == other.id;
}

std::ostream& operator<<(std::ostream& os, const Vuelo& v) {
  return os << v.conv_str();
}



#endif //VUELO_H

