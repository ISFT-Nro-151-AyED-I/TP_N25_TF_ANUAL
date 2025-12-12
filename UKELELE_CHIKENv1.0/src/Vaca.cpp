#include <iostream>
#include <iomanip>

#include "../include/Vaca.hpp"

namespace UkeleleChiken 
    {
        // ==================== CONSTRUCTORES ====================
        Vaca::Vaca() 
             : Animal(), litrosLeche(0.0) {}

        Vaca::Vaca(const std::string& nombre, const std::string& tipoCarne, int edad, double litrosLeche)
             : Animal(nombre, tipoCarne, edad), litrosLeche(litrosLeche) {}

        // ==================== DESTRUCTOR ====================
        Vaca::~Vaca() 
            {
                // No hay memoria dinámica adicional que liberar.
            }

        // ==================== GETTERS Y SETTERS ESPECÍFICOS ====================
        double Vaca::getLitrosLeche() const 
            {
                return litrosLeche;
            }

        void Vaca::setLitrosLeche(double litrosLeche) 
            {
                this->litrosLeche = litrosLeche;
            }

        // ==================== IMPLEMENTACIÓN DE MÉTODOS VIRTUALES PUROS ====================
        void Vaca::comer() 
        
            {
                std::cout << "🌿 La vaca '" << getNombre() << "' está pastando hierba fresca en el campo.";
            }

        void Vaca::dormir() 
            {
                std::cout << "😴 La vaca '" << getNombre() << "' está durmiendo recostada en el establo.";
            }

        void Vaca::sonido() 
            {
                std::cout << "🐄 La vaca '" << getNombre() << "' hace: ¡Muuuuu!";
            }

        // ==================== SOBRESCRITURA DE MÉTODO VIRTUAL ====================
        void Vaca::mostrarInfo() const 
            {
                Animal::mostrarInfo();  // Llama a la versión de la clase base.
                std::cout << " | Leche/día: " << std::fixed << std::setprecision(1) << litrosLeche << "L 🥛";
            }
    }