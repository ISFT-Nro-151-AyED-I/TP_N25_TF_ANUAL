#pragma once

#include "Animal.hpp"

namespace UkeleleChiken 
    {
        class Vaca : public Animal 
            {
                private:
                    double litrosLeche;  // Litros de leche por día.
                    
                public:
                    // Constructores y destructor.
                    Vaca();
                    Vaca(const std::string& nombre, const std::string& tipoCarne, int edad, double litrosLeche);
                    ~Vaca();
                    
                    // Getters y setters específicos.
                    double getLitrosLeche() const;
                    void setLitrosLeche(double litrosLeche);
                    
                    // Implementación de métodos virtuales puros.
                    void comer() override;
                    void dormir() override;
                    void sonido() override;
                    
                    // Sobrescritura de método virtual.
                    void mostrarInfo() const override;
            };
    }