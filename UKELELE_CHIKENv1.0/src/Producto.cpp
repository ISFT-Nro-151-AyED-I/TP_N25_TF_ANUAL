#include <iostream>
#include <iomanip>

#include "../include/Producto.hpp"

namespace UkeleleChiken 
    {
        // ==================== CONSTRUCTORES ====================
        Producto::Producto() 
                 : id(0), nombre(""), precio(0.0), animalOrigen(nullptr) {}

        Producto::Producto(int id, const std::string& nombre, double precio, Animal* animalOrigen)
                 : id(id), nombre(nombre), precio(precio), animalOrigen(animalOrigen) {}

        // ==================== DESTRUCTOR ====================
        Producto::~Producto() 
            {
                // NOTA: No eliminamos animalOrigen porque es una agregación.
                // El animalOrigen es propiedad de otra parte del sistema.
            }

        // ==================== GETTERS ====================
        int Producto::getId() const 
            {
                return id;
            }

        std::string Producto::getNombre() const 
            {
                return nombre;
            }

        double Producto::getPrecio() const
            {
                return precio;
            }

        Animal* Producto::getAnimalOrigen() const 
            {
                return animalOrigen;
            }

        // ==================== SETTERS ====================
        void Producto::setId(int id) 
            {
                this->id = id;
            }

        void Producto::setNombre(const std::string& nombre) 
            {
                this->nombre = nombre;
            }

        void Producto::setPrecio(double precio)
            {
                this->precio = precio;
            }

        void Producto::setAnimalOrigen(Animal* animalOrigen)    
            {
                this->animalOrigen = animalOrigen;
            }

        // ==================== MÉTODOS PÚBLICOS ====================
        void Producto::mostrarInfo() const 
            {
                std::cout << "🛒 Producto #" << id << ": " << nombre;
                std::cout << " | Precio: $" << std::fixed << std::setprecision(2) << precio;
                
                if (animalOrigen != nullptr) 
                    {
                        std::cout << " | Origen: ";
                        
                        // Muestra emoji según tipo de animal.
                        std::string tipoCarne = animalOrigen->getTipoCarne();
                        
                        if (tipoCarne.find("pollo") != std::string::npos || tipoCarne.find("Pollo") != std::string::npos) 
                            {
                                std::cout << "🐔 ";

                            } else if (tipoCarne.find("cerdo") != std::string::npos || tipoCarne.find("Cerdo") != std::string::npos) 
                                {
                                    std::cout << "🐖 ";

                                } else if (tipoCarne.find("vaca") != std::string::npos || tipoCarne.find("Vaca") != std::string::npos) 
                                    {
                                        std::cout << "🐄 ";

                                    } else 
                                        {
                                            std::cout << "❓ ";
                                        }
                        
                        std::cout << animalOrigen->getNombre() << " (" << tipoCarne << ")";

                    } else 
                        {
                            std::cout << " | Origen: ❓ Desconocido.";
                        }
            }
    }