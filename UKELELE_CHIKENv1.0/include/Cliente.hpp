#pragma once

#include <iostream>
#include <string>

namespace UkeleleChiken 
    {
        class Cliente 
            {
                private:
                    int id;
                    std::string nombre;
                    std::string direccion;
                    
                public:
                    // Constructores y destructor.
                    Cliente();
                    Cliente(int id, const std::string& nombre, const std::string& direccion);
                    ~Cliente();
                    
                    // Getters.
                    int getId() const;
                    std::string getNombre() const;
                    std::string getDireccion() const;

                    // Setters.
                    void setId(int id);
                    void setNombre(const std::string& nombre);
                    void setDireccion(const std::string& direccion);
                    
                    // Métodos públicos.
                    void mostrarInfo() const;
            };
    }