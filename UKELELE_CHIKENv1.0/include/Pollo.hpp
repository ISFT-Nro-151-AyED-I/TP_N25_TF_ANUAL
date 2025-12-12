#pragma once

#include "Animal.hpp"

namespace UkeleleChiken 
    {
        class Pollo : public Animal 
            {
                private:
                    int cantidadHuevos;  // Huevos por día.
                    
                public:
                    // Constructores y destructor.
                    Pollo();
                    Pollo(const std::string& nombre, const std::string& tipoCarne, int edad, int cantidadHuevos);
                    ~Pollo();
                    
                    // Getters y setters específicos.
                    int getCantidadHuevos() const;
                    void setCantidadHuevos(int cantidadHuevos);
                    
                    // Implementación de métodos virtuales puros.
                    void comer() override;
                    void dormir() override;
                    void sonido() override;
                    
                    // Sobrescritura de método virtual.
                    void mostrarInfo() const override;
            };
    }