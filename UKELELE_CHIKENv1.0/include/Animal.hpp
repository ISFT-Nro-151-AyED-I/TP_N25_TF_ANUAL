#pragma once

#include <iostream>
#include <string>

namespace UkeleleChiken 
    {
        class Animal 
            {
                protected:
                    std::string nombre;
                    std::string tipoCarne;
                    int edad;
                    
                public:
                    // Constructores y destructor.
                    Animal();
                    Animal(const std::string& nombre, const std::string& tipoCarne, int edad);
                    virtual ~Animal();
                    
                    // Getters.
                    std::string getNombre() const;
                    std::string getTipoCarne() const;
                    int getEdad() const;

                    // Setters.
                    void setNombre(const std::string& nombre);
                    void setTipoCarne(const std::string& tipoCarne);
                    void setEdad(int edad);
                    
                    // Métodos virtuales puros (clase abstracta).
                    virtual void comer() = 0;
                    virtual void dormir() = 0;
                    virtual void sonido() = 0;
                    
                    // Métodos virtuales (pueden ser sobrescritos).
                    virtual void mostrarInfo() const;
            };
    }