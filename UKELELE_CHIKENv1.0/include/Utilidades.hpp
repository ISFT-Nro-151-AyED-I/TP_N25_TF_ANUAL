#pragma once

#include <iostream>
#include <string>
#include <windows.h>
#include <limits>

#include "Configuracion.hpp"  // Para TipoAnimal.

namespace UkeleleChiken 
    {
        // Función principal del sistema (única llamada desde Main.cpp).
        void menu();
        
        // Configuración de consola.
        void configurarConsola();
                
        // Funciones de formato y presentación.
        void mostrarEncabezado(const std::string& titulo);
        void mostrarSeparador(char caracter = '=', int longitud = 40);
        void limpiarPantalla();
        void pausar(const std::string& mensaje = "Presiona Enter para continuar...");
        
        // Funciones de entrada validada.
        int leerEntero(const std::string& mensaje, int min = std::numeric_limits<int>::min(), 
                       int max = std::numeric_limits<int>::max());
        double leerDouble(const std::string& mensaje, double min = -std::numeric_limits<double>::max(), 
                          double max = std::numeric_limits<double>::max());
        std::string leerString(const std::string& mensaje);
        bool leerBooleano(const std::string& mensaje);
        
        // Funciones de menú.
        int mostrarMenuPrincipal();
        int mostrarMenuAnimales();
        int mostrarMenuProductos();
        int mostrarMenuClientes();
        int mostrarMenuPedidos();
        int mostrarMenuSimulacion();
        
        // Funciones de validación.
        bool validarRango(int valor, int min, int max);
        bool validarRango(double valor, double min, double max);
        bool validarStringNoVacio(const std::string& texto);
        bool validarOpcionMenu(int opcion, int min, int max);
        
        // Funciones de formato.
        std::string formatearPrecio(double precio);
        std::string centrarTexto(const std::string& texto, int ancho = 80);
        std::string obtenerFechaActual();
        
        // Emojis y elementos visuales.
        void mostrarEmojiAnimal(const std::string& tipoAnimal);
        void mostrarLogo();
        std::string obtenerEmojiAnimal(TipoAnimal tipo);
        
        // Funciones de depuración y mensajes.
        void mostrarError(const std::string& mensaje);
        void mostrarExito(const std::string& mensaje);
        void mostrarInformacion(const std::string& mensaje);
        void mostrarAdvertencia(const std::string& mensaje);
        
        // Funciones de conversión.
        TipoAnimal stringATipoAnimal(const std::string& tipo);
        std::string tipoAnimalAString(TipoAnimal tipo);
        
        // Utilidades de arrays.
        bool hayEspacioArray(int cantidadActual, int maximo);
        void inicializarArrayPunteros(void** array, int tamaño);
        
        // Declaraciones de funciones de gestión.
        void gestionarAnimales();
        void gestionarProductos();
        void gestionarClientes();
        void gestionarPedidos();
        void simularComportamientos();
        void mostrarReportes();
        void cargarDatosDemo();
        void limpiarMemoria();
        void crearPollo();
        void crearCerdo();
        void crearVaca();
        void listarAnimales();
        void eliminarAnimal();
        void crearProducto();
        void listarProductos();
        void eliminarProducto();
        void registrarCliente();
        void listarClientes();
        void eliminarCliente();
        void crearPedido();
        void listarPedidos();
        void agregarProductoAPedido();
        void simularAlimentacion();
        void simularSueno();
        void simularSonidos();
        
        // Función interna auxiliar.
        namespace detalle 
            {
                void limpiarBuffer();
            }
    }