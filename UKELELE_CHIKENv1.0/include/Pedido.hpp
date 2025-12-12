#pragma once

#include <iostream>

#include "Cliente.hpp"
#include "Producto.hpp"
#include "Configuracion.hpp"

namespace UkeleleChiken 
    {
        class Pedido 
            {
                private:
                    int idPedido;
                    Cliente* cliente;  // Agregación (puntero).
                    Producto* productos[MAX_PRODUCTOS_POR_PEDIDO];  // Array de productos.
                    int cantidadProductos;
                    double total;
                    
                public:
                    // Constructores y destructor.
                    Pedido();
                    Pedido(int idPedido, Cliente* cliente);
                    ~Pedido();
                    
                    // Getters.
                    int getIdPedido() const;
                    Cliente* getCliente() const;
                    double getTotal() const;
                    int getCantidadProductos() const;

                    // Setters.
                    void setIdPedido(int idPedido);
                    void setCliente(Cliente* cliente);
                    
                    
                    // Métodos públicos.
                    bool agregarProducto(Producto* producto);
                    void calcularTotal();
                    void mostrarPedido() const;
            };
    }