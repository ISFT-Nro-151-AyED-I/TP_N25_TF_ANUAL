#include <iostream>

#include "../include/Cerdo.hpp"

namespace UkeleleChiken 
    {
        // ==================== CONSTRUCTORES ====================
        Cerdo::Cerdo() 
              : Animal(), esSalvaje(false) {}

        Cerdo::Cerdo(const std::string& nombre, const std::string& tipoCarne, int edad, bool esSalvaje)
              : Animal(nombre, tipoCarne, edad), esSalvaje(esSalvaje) {}

        // ==================== DESTRUCTOR ====================
        Cerdo::~Cerdo() 
            {
                // No hay memoria dinámica adicional que liberar.
            }

        // ==================== GETTERS Y SETTERS ESPECÍFICOS ====================
        bool Cerdo::getEsSalvaje() const 
            {
                return esSalvaje;
            }

        void Cerdo::setEsSalvaje(bool esSalvaje) 
            {
                this->esSalvaje = esSalvaje;
            }

        // ==================== IMPLEMENTACIÓN DE MÉTODOS VIRTUALES PUROS ====================
        void Cerdo::comer() 
            {
                std::cout << "🍎 El cerdo '" << getNombre() << "' está comiendo manzanas y bellotas.";

                if (esSalvaje) 
                    {
                        std::cout << " en el bosque.";

                    } else 
                        {
                            std::cout << " en el corral.";
                        }
            }

        void Cerdo::dormir() 
            {
                std::cout << "😴 El cerdo '" << getNombre() << "' está roncando.";

                if (esSalvaje) 
                    {
                        std::cout << " en una cueva.";

                    } else 
                        {
                            std::cout << " en el barro para refrescarse.";
                        }
            }

        void Cerdo::sonido() 
            {
                std::cout << "🐖 El cerdo '" << getNombre() << "' hace: ¡Oink Oink!";
            }

        // ==================== SOBRESCRITURA DE MÉTODO VIRTUAL ====================
        void Cerdo::mostrarInfo() const 
            {
                Animal::mostrarInfo();  // Llama a la versión de la clase base.
                std::cout << " | Tipo: " << (esSalvaje ? "Salvaje 🌳" : "Doméstico 🏠");
            }
    }