#include <iostream>

#include "../include/Pollo.hpp"

namespace UkeleleChiken 
    {
        // ==================== CONSTRUCTORES ====================
        Pollo::Pollo() 
              : Animal(), cantidadHuevos(0) {}

        Pollo::Pollo(const std::string& nombre, const std::string& tipoCarne, int edad, int cantidadHuevos)
              : Animal(nombre, tipoCarne, edad), cantidadHuevos(cantidadHuevos) {}

        // ==================== DESTRUCTOR ====================
        Pollo::~Pollo() 
            {
                // No hay memoria dinámica adicional que liberar.
            }

        // ==================== GETTERS Y SETTERS ESPECÍFICOS ====================
        int Pollo::getCantidadHuevos() const 
            {
                return cantidadHuevos;
            }

        void Pollo::setCantidadHuevos(int cantidadHuevos) 
            {
                this->cantidadHuevos = cantidadHuevos;
            }

        // ==================== IMPLEMENTACIÓN DE MÉTODOS VIRTUALES PUROS ====================
        void Pollo::comer() 
            {
                std::cout << "🍚 El pollo '" << getNombre() << "' está picoteando maíz y granos.";
            }

        void Pollo::dormir() 
            {
                std::cout << "😴 El pollo '" << getNombre() << "' está durmiendo en el gallinero con una pata levantada.";
            }

        void Pollo::sonido() 
            {
                std::cout << "🐔 El pollo '" << getNombre() << "' hace: ¡Kikirikiiii!";
            }

        // ==================== SOBRESCRITURA DE MÉTODO VIRTUAL ====================
        void Pollo::mostrarInfo() const 
            {
                Animal::mostrarInfo();  // Llama a la versión de la clase base.
                std::cout << " | Huevos/día: " << cantidadHuevos;
                std::cout << " 🥚";
            }
    }