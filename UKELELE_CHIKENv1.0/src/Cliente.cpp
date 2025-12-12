#include <iostream>

#include "../include/Cliente.hpp"

namespace UkeleleChiken 
    {
        // ==================== CONSTRUCTORES ====================
        Cliente::Cliente() 
                : id(0), nombre(""), direccion("") {}

        Cliente::Cliente(int id, const std::string& nombre, const std::string& direccion)
                : id(id), nombre(nombre), direccion(direccion) {}

        // ==================== DESTRUCTOR ====================
        Cliente::~Cliente() 
            {
                // No hay memoria dinámica que liberar.
            }

        // ==================== GETTERS ====================
        int Cliente::getId() const 
            {
                return id;
            }

        std::string Cliente::getNombre() const 
            {
                return nombre;
            }

        std::string Cliente::getDireccion() const 
            {
                return direccion;
            }

        // ==================== SETTERS ====================
        void Cliente::setId(int id) 
            {
                this->id = id;
            }

        void Cliente::setNombre(const std::string& nombre) 
            {
                this->nombre = nombre;
            }

        void Cliente::setDireccion(const std::string& direccion) 
            {
                this->direccion = direccion;
            }
        

        // ==================== MÉTODOS PÚBLICOS ====================
        void Cliente::mostrarInfo() const 
            {
                std::cout << "👤 Cliente #" << id << ": " << nombre;
                std::cout << " | Dirección: " << direccion;
            }
    }