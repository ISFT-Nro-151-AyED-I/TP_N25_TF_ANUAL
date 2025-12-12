#pragma once

#include "Animal.hpp"

namespace UkeleleChiken 
    {
        class Cerdo : public Animal 
            {
                private:
                    bool esSalvaje;  // true si es salvaje, false si es doméstico.
                    
                public:
                    // Constructores y destructor.
                    Cerdo();
                    Cerdo(const std::string& nombre, const std::string& tipoCarne, int edad, bool esSalvaje);
                    ~Cerdo();
                    
                    // Getters y setters específicos.
                    bool getEsSalvaje() const;
                    void setEsSalvaje(bool esSalvaje);
                    
                    // Implementación de métodos virtuales puros.
                    void comer() override;
                    void dormir() override;
                    void sonido() override;
                    
                    // Sobrescritura de método virtual.
                    void mostrarInfo() const override;
            };
    }