#pragma once

namespace UkeleleChiken 
    {
        // Constantes de configuración del sistema.
        const int MAX_PRODUCTOS = 10;       // Máximo productos a cargar.
        const int MAX_CLIENTES = 10;        // Máximo clientes a cargar.
        const int MAX_PEDIDOS = 10;         // Máximo pedidos a cargar.
        const int MAX_ANIMALES = 10;        // Máximo animales en el sistema.
        const int MAX_PRODUCTOS_POR_PEDIDO = 10; // Máximo productos por pedido.
        
        // Tipos de animales disponibles.
        enum class TipoAnimal 
            {
                POLLO,
                CERDO,
                VACA,
                DESCONOCIDO
            };

        // Precios base por tipo de carne (por kg).
        const double PRECIO_POLLO = 7500.0;
        const double PRECIO_CERDO = 7700.0;
        const double PRECIO_VACA = 12500.0;

        // Configuración de consola.
        const int CONSOLE_WIDTH = 80;
        const char LINEA_SEPARADORA[] = "========================================";

        // Mensajes del sistema.
        const char MENSAJE_BIENVENIDA[] = "🐔 Ukelele Chicken - Boutique de Carnes 🥩";
        const char MENSAJE_SALIDA[] = "¡Gracias por visitar Ukelele Chicken! 🍗";

        // Otros límites del sistema.
        const int MAX_NOMBRE = 50;
        const int MAX_DIRECCION = 100;
    }