#include <iostream>

#include "../include/Animal.hpp"

namespace UkeleleChiken 
    {
        // ==================== CONSTRUCTORES ====================
        Animal::Animal() 
               : nombre(""), tipoCarne(""), edad(0) {}

        Animal::Animal(const std::string& nombre, const std::string& tipoCarne, int edad)
               : nombre(nombre), tipoCarne(tipoCarne), edad(edad) {}

        // ==================== DESTRUCTOR ====================
        Animal::~Animal() 
            {
                // Destructor virtual para liberación correcta de memoria.
            }

        // ==================== GETTERS ====================
        std::string Animal::getNombre() const 
            {
                return nombre;
            }

        std::string Animal::getTipoCarne() const 
            {
                return tipoCarne;
            }

        int Animal::getEdad() const 
            {
                return edad;
            }

        // ==================== SETTERS ====================
        void Animal::setNombre(const std::string& nombre) 
            {
                this->nombre = nombre;
            }

        void Animal::setTipoCarne(const std::string& tipoCarne) 
            {
                this->tipoCarne = tipoCarne;
            }

        void Animal::setEdad(int edad) 
            {
                this->edad = edad;
            }

        // ==================== MÉTODOS VIRTUALES ====================
        void Animal::mostrarInfo() const 
            {
                std::cout << "🐾 " << nombre << " | Tipo: " << tipoCarne << " | Edad: " << edad << " meses";
            }

        /* NOTA: Los métodos virtuales puros comer(), dormir() y sonido()
           NO tienen implementación aquí porque Animal es clase abstracta.
           Se implementan en las clases derivadas. */
    }