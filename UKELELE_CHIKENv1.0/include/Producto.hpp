#pragma once

#include <iostream>
#include <string>

#include "Animal.hpp"

namespace UkeleleChiken 
    {
        class Producto 
            {
                private:
                    int id;
                    std::string nombre;
                    double precio;
                    Animal* animalOrigen;  // Agregación (puntero).
                    
                public:
                    // Constructores y destructor.
                    Producto();
                    Producto(int id, const std::string& nombre, double precio, Animal* animalOrigen);
                    ~Producto();
                    
                    // Getters.
                    int getId() const;
                    std::string getNombre() const;
                    double getPrecio() const;
                    Animal* getAnimalOrigen() const;

                    // Setters.
                    void setId(int id);
                    void setNombre(const std::string& nombre);
                    void setPrecio(double precio);
                    void setAnimalOrigen(Animal* animalOrigen);
                    
                    // Métodos públicos.
                    void mostrarInfo() const;
            };
    }