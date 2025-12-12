#include <iostream>
#include <iomanip>

#include "../include/Pedido.hpp"

namespace UkeleleChiken 
    {
        // ==================== CONSTRUCTORES ====================
        Pedido::Pedido() 
               : idPedido(0), cliente(nullptr), cantidadProductos(0), total(0.0) 
            {
                // Inicializa array de productos.
                for (int i = 0; i < MAX_PRODUCTOS_POR_PEDIDO; i++) 
                    {
                        productos[i] = nullptr;
                    }
            }

        Pedido::Pedido(int idPedido, Cliente* cliente)
               : idPedido(idPedido), cliente(cliente), cantidadProductos(0), total(0.0) 
            {
                // Inicializa array de productos.
                for (int i = 0; i < MAX_PRODUCTOS_POR_PEDIDO; i++) 
                    {
                        productos[i] = nullptr;
                    }
            }

        // ==================== DESTRUCTOR ====================
        Pedido::~Pedido() 
            {
                // NOTA: No eliminamos cliente ni productos porque son asociaciones.
                // El cliente y productos son propiedad de otras partes del sistema.
            }

        // ==================== GETTERS ====================
        int Pedido::getIdPedido() const 
            {
                return idPedido;
            }

        Cliente* Pedido::getCliente() const 
            {
                return cliente;
            }

        double Pedido::getTotal() const 
            {
                return total;
            }

        int Pedido::getCantidadProductos() const 
            {
                return cantidadProductos;
            }

        // ==================== SETTERS ====================
        void Pedido::setIdPedido(int idPedido) 
            {
                this->idPedido = idPedido;
            }

        void Pedido::setCliente(Cliente* cliente) 
            {
                this->cliente = cliente;
            }

        // ==================== MÉTODOS PÚBLICOS ====================
        bool Pedido::agregarProducto(Producto* producto) 
            {
                if (cantidadProductos >= MAX_PRODUCTOS_POR_PEDIDO) 
                    {
                        return false; // Array lleno.
                    }
                
                productos[cantidadProductos] = producto;
                cantidadProductos++;

                calcularTotal();
                
                return true;
            }

        void Pedido::calcularTotal() 
            {
                total = 0.0;

                for (int i = 0; i < cantidadProductos; i++) 
                    {
                        if (productos[i] != nullptr) 
                        {
                            total += productos[i]->getPrecio();
                        }
                    }
            }

        void Pedido::mostrarPedido() const 
            {
                std::cout << "📦 Pedido #" << idPedido;
                
                if (cliente != nullptr) 
                    {
                        std::cout << " | Cliente: " << cliente->getNombre();

                    } else 
                        {
                            std::cout << " | Cliente: ❓ Desconocido.";
                        }
                
                std::cout << " | Productos: " << cantidadProductos << "/" << MAX_PRODUCTOS_POR_PEDIDO;
                std::cout << " | Total: $" << std::fixed << std::setprecision(2) << total;
                
                if (cantidadProductos > 0) 
                    {
                        std::cout << "\n   Productos incluidos:";

                        for (int i = 0; i < cantidadProductos; i++) 
                            {
                                if (productos[i] != nullptr) 
                                    {
                                        std::cout << "\n   " << i + 1 << ". ";
                                        productos[i]->mostrarInfo();
                                    }
                            }
                    }
            }
    }