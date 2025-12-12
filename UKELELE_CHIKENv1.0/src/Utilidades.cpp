#include <iostream>
#include <string>
#include <windows.h>
#include <limits>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <sstream>

#include "../include/Utilidades.hpp"
#include "../include/Animal.hpp"
#include "../include/Pollo.hpp"
#include "../include/Cerdo.hpp"
#include "../include/Vaca.hpp"
#include "../include/Producto.hpp"
#include "../include/Cliente.hpp"
#include "../include/Pedido.hpp"

namespace UkeleleChiken 
    {
        // ==================== Variables globales del sistema ====================
        namespace 
            {
                // Arrays para almacenar los objetos del sistema.
                Animal* animales[MAX_ANIMALES];
                Producto* productos[MAX_PRODUCTOS];
                Cliente* clientes[MAX_CLIENTES];
                Pedido* pedidos[MAX_PEDIDOS];
                
                // Contadores de objetos actuales.
                int cantidadAnimales = 0;
                int cantidadProductos = 0;
                int cantidadClientes = 0;
                int cantidadPedidos = 0;
                
                // Flag para datos demo cargados.
                bool datosDemoCargados = false;
            }

        // ==================== Función principal menu() ====================
        void menu() 
            {
                // Configura la codificación de consola para Windows.
                SetConsoleOutputCP(CP_UTF8);
                SetConsoleCP(CP_UTF8);
                
                // Configura consola.
                configurarConsola();

                // Inicializa arrays de punteros. 
                inicializarArrayPunteros(reinterpret_cast<void**>(animales), MAX_ANIMALES);
                inicializarArrayPunteros(reinterpret_cast<void**>(productos), MAX_PRODUCTOS);
                inicializarArrayPunteros(reinterpret_cast<void**>(clientes), MAX_CLIENTES);
                inicializarArrayPunteros(reinterpret_cast<void**>(pedidos), MAX_PEDIDOS);
                
                // Muestra logo y mensaje de bienvenida.
                mostrarLogo();
                std::cout << centrarTexto(UkeleleChiken::MENSAJE_BIENVENIDA) << "\n\n";
                pausar();
        
                // Bucle principal del programa.
                int opcion;

                do 
                    {
                        opcion = mostrarMenuPrincipal();
                        
                        switch (opcion) 
                            {
                                case 1: // Gestión de Animales.
                                    gestionarAnimales();
                                    break;
                                    
                                case 2: // Gestión de Productos.
                                    gestionarProductos();
                                    break;
                                    
                                case 3: // Gestión de Clientes.
                                    gestionarClientes();
                                    break;
                                    
                                case 4: // Gestión de Pedidos.
                                    gestionarPedidos();
                                    break;
                                    
                                case 5: // Simula Comportamientos.
                                    simularComportamientos();
                                    break;
                                    
                                case 6: // Muestra Reportes.
                                    mostrarReportes();
                                    break;
                                    
                                case 7: // Carga Datos Demo.
                                    cargarDatosDemo();
                                    break;
                                    
                                case 0: // Sale del sistema.
                                    mostrarEncabezado("SALIENDO DEL SISTEMA");
                                    std::cout << UkeleleChiken::MENSAJE_SALIDA << "\n\n";
                                    break;
                                    
                                default:
                                    mostrarError("Opción inválida. Intenta nuevamente.");
                                    pausar();
                                    break;
                            }
                        
                    } while (opcion != 0);
                
                // Limpia memoria dinámica.
                limpiarMemoria();
                
                std::cout << "\n";
                pausar("Programa finalizado. Presiona Enter para salir...");
            }

        // ==================== Funciones internas auxiliares ====================
        namespace detalle 
            {
                void limpiarBuffer() 
                    {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
            }    
           
        // ==================== Configuración de consola ====================
        void configurarConsola() 
            {
                system("cls");
            }

        // ==================== Formato y presentación ====================
        void mostrarEncabezado(const std::string& titulo) 
            {
                limpiarPantalla();
                mostrarSeparador('=', CONSOLE_WIDTH);
                std::cout << centrarTexto(titulo) << std::endl;
                mostrarSeparador('=', CONSOLE_WIDTH);
                std::cout << std::endl;
            }
        
           void mostrarSeparador(char caracter, int longitud) 
            {
                // Usa la constante del namespace UkeleleChiken si no se especifica longitud.
                int ancho = (longitud <= 0) ? CONSOLE_WIDTH : longitud;
                std::cout << std::string(ancho, caracter) << std::endl;
            }
        
        void limpiarPantalla() 
            {
                system("cls");
            }

        void pausar(const std::string& mensaje) 
            {
                std::cout << "\n" << mensaje;
                detalle::limpiarBuffer();
            }

        // ==================== Entrada validada ====================
        int leerEntero(const std::string& mensaje, int min, int max) 
            {
                int valor;

                while (true) 
                    {
                        std::cout << mensaje;
                        if (std::cin >> valor) 
                            {
                                if (validarRango(valor, min, max)) 
                                    {
                                        detalle::limpiarBuffer();

                                        return valor;
                                    } else 
                                        {
                                            mostrarError("Valor fuera de rango. Debe estar entre " + 
                                                         std::to_string(min) + " y " + std::to_string(max));
                                        }
                            } else 
                                {
                                    mostrarError("Entrada inválida. Debes ingresar un número entero.");
                                    detalle::limpiarBuffer();
                                }
                    }
            }

        double leerDouble(const std::string& mensaje, double min, double max) 
            {
                double valor;
                while (true) 
                    {
                        std::cout << mensaje;

                        if (std::cin >> valor) 
                            {
                                if (validarRango(valor, min, max)) 
                                {
                                    detalle::limpiarBuffer();

                                    return valor;
                                } else 
                                    {
                                        mostrarError("Valor fuera de rango. Debe estar entre " + 
                                                     std::to_string(min) + " y " + std::to_string(max));
                                    }
                            } else 
                                {
                                    mostrarError("Entrada inválida. Debes ingresar un número.");
                                    detalle::limpiarBuffer();
                                }
                    }
            }

        std::string leerString(const std::string& mensaje) 
            {
                std::string texto;
                while (true) 
                    {
                        std::cout << mensaje;
                        std::getline(std::cin, texto);

                        if (validarStringNoVacio(texto)) 
                            {
                                return texto;
                            } else 
                                {
                                    mostrarError("El texto no puede estar vacío.");
                                }
                    }
            }

        bool leerBooleano(const std::string& mensaje) 
            {
                std::string entrada;

                while (true) 
                    {
                        std::cout << mensaje << " (s/n): ";
                        std::getline(std::cin, entrada);

                        if (entrada == "s" || entrada == "S" || entrada == "si" || entrada == "SI") 
                            {
                                return true;

                            } else if (entrada == "n" || entrada == "N" || entrada == "no" || entrada == "NO") 
                                {
                                    return false;

                                } else 
                                    {
                                        mostrarError("Entrada inválida. Ingresa 's' para sí o 'n' para no.");
                                    }
                    }
            }

        // ==================== Menús ====================
        int mostrarMenuPrincipal() 
            {
                mostrarEncabezado("🐔 UKELELE CHICKEN - MENÚ PRINCIPAL 🍗");
                
                std::cout << "1. 🐓 Gestión de Animales\n";
                std::cout << "2. 🛒 Gestión de Productos\n";
                std::cout << "3. 👤 Gestión de Clientes\n";
                std::cout << "4. 📦 Gestión de Pedidos\n";
                std::cout << "5. 🎭 Simular Comportamientos\n";
                std::cout << "6. 📊 Mostrar Reportes\n";

                if (!datosDemoCargados) 
                    {
                        std::cout << "7. 📥 Cargar Datos de Demostración\n";
                    }
                std::cout << "0. 🚪 Salir\n\n";

                mostrarSeparador('-');
                
                int maxOpcion = datosDemoCargados ? 6 : 7;

                return leerEntero("Selecciona una opción: ", 0, maxOpcion);
            }

        int mostrarMenuAnimales() 
            {
                mostrarEncabezado("🐓 GESTIÓN DE ANIMALES");
                
                std::cout << "1. 🐔 Crear Pollo\n";
                std::cout << "2. 🐖 Crear Cerdo\n";
                std::cout << "3. 🐄 Crear Vaca\n";
                std::cout << "4. 📋 Listar Animales\n";
                std::cout << "5. 🗑️ Eliminar Animal\n";
                std::cout << "0. ↩️ Volver al Menú Principal\n\n";

                mostrarSeparador('-');
                
                return leerEntero("Selecciona una opción: ", 0, 5);
            }

        int mostrarMenuProductos() 
        {
            mostrarEncabezado("🛒 GESTIÓN DE PRODUCTOS");
            
            std::cout << "1. 🆕 Crear Producto\n";
            std::cout << "2. 📋 Listar Productos\n";
            std::cout << "3. 🗑️ Eliminar Producto\n";
            std::cout << "0. ↩️ Volver al Menú Principal\n\n";

            mostrarSeparador('-');
            
            return leerEntero("Selecciona una opción: ", 0, 3);
        }

        int mostrarMenuClientes() 
            {
                mostrarEncabezado("👤 GESTIÓN DE CLIENTES");
                
                std::cout << "1. 🆕 Registrar Cliente\n";
                std::cout << "2. 📋 Listar Clientes\n";
                std::cout << "3. 🗑️ Eliminar Cliente\n";
                std::cout << "0. ↩️ Volver al Menú Principal\n\n";

                mostrarSeparador('-');
                
                return leerEntero("Selecciona una opción: ", 0, 3);
            }

        int mostrarMenuPedidos() 
            {
                mostrarEncabezado("📦 GESTIÓN DE PEDIDOS");
                    
                std::cout << "1. 🆕 Crear Pedido\n";
                std::cout << "2. 📋 Listar Pedidos\n";
                std::cout << "3. 📝 Agregar Producto a Pedido\n";
                std::cout << "0. ↩️ Volver al Menú Principal\n\n";

                mostrarSeparador('-');
                
                return leerEntero("Selecciona una opción: ", 0, 3);
            }

        int mostrarMenuSimulacion() 
            {
                mostrarEncabezado("🎭 SIMULACIÓN DE COMPORTAMIENTOS");
                
                std::cout << "1. 🍽️ Simular Alimentación\n";
                std::cout << "2. 😴 Simular Sueño\n";
                std::cout << "3. 🔊 Simular Sonidos\n";
                std::cout << "0. ↩️ Volver al Menú Principal\n\n";
                
                mostrarSeparador('-');
                
                return leerEntero("Selecciona una opción: ", 0, 3);
            }

        // ==================== Validación ====================
        bool validarRango(int valor, int min, int max) 
            {
                return valor >= min && valor <= max;
            }

        bool validarRango(double valor, double min, double max) 
            {
                return valor >= min && valor <= max;
            }

        bool validarStringNoVacio(const std::string& texto) 
            {
                return !texto.empty();
            }

        bool validarOpcionMenu(int opcion, int min, int max) 
            {
                return validarRango(opcion, min, max);
            }

        // ==================== Formato ====================
        std::string formatearPrecio(double precio) 
            {
                std::stringstream ss;
                
                ss << std::fixed << std::setprecision(2) << "$" << precio;
                return ss.str();
            }

        std::string centrarTexto(const std::string& texto, int ancho) 
            {
                // Usa valor por defecto de Configuracion.hpp si no se especifica.
                int anchoUsar = (ancho <= 0) ? CONSOLE_WIDTH : ancho;
                int espacios = (anchoUsar - static_cast<int>(texto.length())) / 2;
        
                if (espacios < 0) espacios = 0;
                return std::string(espacios, ' ') + texto;
            }
        
        

        std::string obtenerFechaActual() 
            {
                std::time_t t = std::time(nullptr);
                std::tm* now = std::localtime(&t);

                char buffer[20];
                
                std::strftime(buffer, sizeof(buffer), "%d/%m/%Y", now);
                return std::string(buffer);
            }

        // ==================== Emojis y elementos visuales ====================
        void mostrarEmojiAnimal(const std::string& tipoAnimal) 
            {
                if (tipoAnimal.find("pollo") != std::string::npos || tipoAnimal.find("Pollo") != std::string::npos) 
                    std::cout << "🐔 ";

                    else if (tipoAnimal.find("cerdo") != std::string::npos || tipoAnimal.find("Cerdo") != std::string::npos) 
                        std::cout << "🐖 ";

                        else if (tipoAnimal.find("vaca") != std::string::npos || tipoAnimal.find("Vaca") != std::string::npos) 
                            std::cout << "🐄 ";

                            else 
                                std::cout << "❓ ";
            }

        void mostrarLogo() 
            {
                std::cout << "\n";
                std::cout << "  ██╗   ██╗██╗  ██╗███████╗██╗     ███████╗██╗     ███████╗     ██████╗██╗  ██╗██╗██╗  ██╗███████╗███╗   ██╗\n";
                std::cout << "  ██║   ██║██║ ██╔╝██╔════╝██║     ██╔════╝██║     ██╔════╝    ██╔════╝██║ ██╔╝██║██║ ██╔╝██╔════╝████╗  ██║\n";
                std::cout << "  ██║   ██║█████╔╝ █████╗  ██║     █████╗  ██║     █████╗      ██║     █████╔╝ ██║█████╔╝ █████╗  ██╔██╗ ██║\n";
                std::cout << "  ██║   ██║██╔═██╗ ██╔══╝  ██║     ██╔══╝  ██║     ██╔══╝      ██║     ██╔═██╗ ██║██╔═██╗ ██╔══╝  ██║╚██╗██║\n";
                std::cout << "  ╚██████╔╝██║  ██╗███████╗███████╗███████╗███████╗███████╗    ╚██████╗██║  ██╗██║██║  ██╗███████╗██║ ╚████║\n";
                std::cout << "   ╚═════╝ ╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝     ╚═════╝╚═╝  ╚═╝╚═╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═══╝\n";
                std::cout << "\n";
            }

        std::string obtenerEmojiAnimal(TipoAnimal tipo) 
            {
                switch (tipo) 
                    {
                        case TipoAnimal::POLLO: return "🐔";
                        case TipoAnimal::CERDO: return "🐖";
                        case TipoAnimal::VACA: return "🐄";
                        default: return "❓";
                    }
            }

        // ==================== Mensajes ====================
        void mostrarError(const std::string& mensaje) 
            {
                std::cout << "\n❌ ERROR: " << mensaje << std::endl;
            }

        void mostrarExito(const std::string& mensaje) 
            {
                std::cout << "\n✅ " << mensaje << std::endl;
            }

        void mostrarInformacion(const std::string& mensaje) 
            {
                std::cout << "\nℹ️  " << mensaje << std::endl;
            }

        void mostrarAdvertencia(const std::string& mensaje) 
            {
                std::cout << "\n⚠️  ADVERTENCIA: " << mensaje << std::endl;
            }

        // ==================== Conversión ====================
        TipoAnimal stringATipoAnimal(const std::string& tipo) 
            {
                if (tipo == "Pollo" || tipo == "POLLO" || tipo == "pollo") 
                return TipoAnimal::POLLO;

                if (tipo == "Cerdo" || tipo == "CERDO" || tipo == "cerdo") 
                return TipoAnimal::CERDO;
            
                if (tipo == "Vaca" || tipo == "VACA" || tipo == "vaca") 
                return TipoAnimal::VACA;

                return TipoAnimal::DESCONOCIDO;
            }

        std::string tipoAnimalAString(TipoAnimal tipo) 
            {
                switch (tipo) 
                    {
                        case TipoAnimal::POLLO: 
                        return "Pollo";

                        case TipoAnimal::CERDO: 
                        return "Cerdo";

                        case TipoAnimal::VACA: 
                        return "Vaca";
                        
                        default: 
                        return "Desconocido";
                    }
            }

        // ==================== Utilidades de arrays ====================
        bool hayEspacioArray(int cantidadActual, int maximo) 
            {
                return cantidadActual < maximo;
            }

        void inicializarArrayPunteros(void** array, int tamaño) 
            {
                for (int i = 0; i < tamaño; i++) 
                    {
                        array[i] = nullptr;
                    }
            }

        // ==================== Funciones de gestión del sistema ====================
        void cargarDatosDemo() 
            {
                if (datosDemoCargados) 
                    {
                        mostrarError("Los datos demo ya fueron cargados.");
                        pausar();
                        return;
                    }
                
                mostrarEncabezado("CARGANDO DATOS DE DEMOSTRACIÓN 📥");
                
                // Carga animales de demostración.
                if (hayEspacioArray(cantidadAnimales, MAX_ANIMALES)) 
                    {
                        animales[cantidadAnimales++] = new Pollo("Pio Pio", "Carne de pollo", 6, 2);
                        mostrarInformacion("Pollo 'Pio Pio' creado.");
                    }

                if (hayEspacioArray(cantidadAnimales, MAX_ANIMALES)) 
                    {
                        animales[cantidadAnimales++] = new Cerdo("Babe", "Carne de cerdo", 12, false);
                        mostrarInformacion("Cerdo 'Babe' creado.");
                    }
                
                if (hayEspacioArray(cantidadAnimales, MAX_ANIMALES)) 
                    {
                        animales[cantidadAnimales++] = new Vaca("Lola", "Carne de vaca", 48, 15.5);
                        mostrarInformacion("Vaca 'Lola' creada.");
                    }
                
                // Carga 5 productos de demostración.

                // Producto 1.
                if (hayEspacioArray(cantidadProductos, MAX_PRODUCTOS) && cantidadAnimales >= 3) 
                    {
                        productos[cantidadProductos++] = new Producto(1, "Pechuga de pollo", UkeleleChiken::PRECIO_POLLO * 1.5, animales[0]);
                        mostrarInformacion("Producto 'Pechuga de pollo' creado.");
                    }
                
                // Producto 2.
                if (hayEspacioArray(cantidadProductos, MAX_PRODUCTOS) && cantidadAnimales >= 3) 
                    {
                        productos[cantidadProductos++] = new Producto(2, "Lomo de cerdo", UkeleleChiken::PRECIO_CERDO * 2.0, animales[1]);
                        mostrarInformacion("Producto 'Lomo de cerdo' creado.");
                    }
                
                // Producto 3.
                if (hayEspacioArray(cantidadProductos, MAX_PRODUCTOS) && cantidadAnimales >= 3) 
                    {
                        productos[cantidadProductos++] = new Producto(3, "Bife de chorizo", UkeleleChiken::PRECIO_VACA * 1.8, animales[2]);
                        mostrarInformacion("Producto 'Bife de chorizo' creado.");
                    }
                
                // Producto 4.
                if (hayEspacioArray(cantidadProductos, MAX_PRODUCTOS) && cantidadAnimales >= 3) 
                    {
                        productos[cantidadProductos++] = new Producto(4, "Alas de pollo", UkeleleChiken::PRECIO_POLLO * 1.2, animales[0]);
                        mostrarInformacion("Producto 'Alas de pollo' creado.");
                    }
                
                // Producto 5.
                if (hayEspacioArray(cantidadProductos, MAX_PRODUCTOS) && cantidadAnimales >= 3) 
                    {
                        productos[cantidadProductos++] = new Producto(5, "Costillas de cerdo", UkeleleChiken::PRECIO_CERDO * 1.7, animales[1]);
                        mostrarInformacion("Producto 'Costillas de cerdo' creado.");
                    }
                
                // Carga clientes de demostración.
                if (hayEspacioArray(cantidadClientes, MAX_CLIENTES)) 
                    {
                        clientes[cantidadClientes++] = new Cliente(1, "Homero Tompson", "Av. Siempre Viva 123");
                        mostrarInformacion("Cliente 'Homero Tompson' creado.");
                    }
                
                if (hayEspacioArray(cantidadClientes, MAX_CLIENTES)) 
                    {
                        clientes[cantidadClientes++] = new Cliente(2, "Natalia Natalia", "Calle Desconocida 456");
                        mostrarInformacion("Cliente 'Natalia Natalia' creado.");
                    }
                
                if (hayEspacioArray(cantidadClientes, MAX_CLIENTES)) 
                    {
                        clientes[cantidadClientes++] = new Cliente(3, "José Coder", "Bv. De Los Hackers 789");
                        mostrarInformacion("Cliente 'José Coder' creado.");
                    }
                
                // Carga pedidos de demostración.

                // Pedido 1 (con 2 productos).
                if (hayEspacioArray(cantidadPedidos, MAX_PEDIDOS) && cantidadClientes >= 1 && cantidadProductos >= 2) 
                    {
                        pedidos[cantidadPedidos] = new Pedido(1, clientes[0]);
                        pedidos[cantidadPedidos]->agregarProducto(productos[0]); // Pechuga de pollo.
                        pedidos[cantidadPedidos]->agregarProducto(productos[1]); // Lomo de cerdo.
                        pedidos[cantidadPedidos]->agregarProducto(productos[4]); // Costillas de cerdo.
                        cantidadPedidos++;

                        mostrarInformacion("Pedido #1 creado con 3 productos.");
                    }
                
                // Pedido 2 (con 2 productos diferentes).
                if (hayEspacioArray(cantidadPedidos, MAX_PEDIDOS) && cantidadClientes >= 2 && cantidadProductos >= 4) 
                    {
                        pedidos[cantidadPedidos] = new Pedido(2, clientes[1]);
                        pedidos[cantidadPedidos]->agregarProducto(productos[2]); // Bife de chorizo.
                        pedidos[cantidadPedidos]->agregarProducto(productos[3]); // Alas de pollo.
                        cantidadPedidos++;
                        
                        mostrarInformacion("Pedido #2 creado con 2 productos.");
                    }
                
                datosDemoCargados = true;

                // Mensaje que muestra resumen de datos cargados.
                mostrarExito("Datos de demostración cargados exitosamente:");
                mostrarInformacion("- 3 animales (Pollo, Cerdo, Vaca)");
                mostrarInformacion("- 5 productos de carne");
                mostrarInformacion("- 3 clientes registrados");
                mostrarInformacion("- 2 pedidos creados");
                pausar();
            }
        
        void gestionarAnimales() 
            {
                int opcion;

                do 
                    {
                        opcion = mostrarMenuAnimales();
                        
                        switch (opcion) 
                            {
                                case 1: // Crea Pollo.
                                    crearPollo();
                                    break;
                                    
                                case 2: // Crea Cerdo.
                                    crearCerdo();
                                    break;
                                    
                                case 3: // Crea Vaca.
                                    crearVaca();
                                    break;
                                    
                                case 4: // Lista Animales.
                                    listarAnimales();
                                    break;
                                    
                                case 5: // Elimina Animal.
                                    eliminarAnimal();
                                    break;
                                    
                                case 0: // Vuelve al Menú Principal.
                                    break;
                                    
                                default:
                                    mostrarError("Opción inválida.");
                                    pausar();
                                    break;
                            }

                    } while (opcion != 0);
            }

        void gestionarProductos() 
            {
                int opcion;

                do 
                    {
                        opcion = mostrarMenuProductos();
                        
                        switch (opcion) 
                            {
                                case 1: // Crea Producto.
                                    crearProducto();
                                    break;
                                    
                                case 2: // Lista Productos.
                                    listarProductos();
                                    break;
                                    
                                case 3: // Elimina Producto.
                                    eliminarProducto();
                                    break;
                                    
                                case 0: // Vuelve al Menú Principal.
                                    break;
                                    
                                default:
                                    mostrarError("Opción inválida.");
                                    pausar();
                                    break;
                            }

                    } while (opcion != 0);
            }

        void gestionarClientes() 
            {
                int opcion;

                do 
                    {
                        opcion = mostrarMenuClientes();
                        
                        switch (opcion) 
                            {
                                case 1: // Registra Cliente.
                                    registrarCliente();
                                    break;
                                    
                                case 2: // Lista Clientes.
                                    listarClientes();
                                    break;
                                    
                                case 3: // Elimina Cliente.
                                    eliminarCliente();
                                    break;
                                    
                                case 0: // Vuelve al Menú Principal.
                                    break;
                                    
                                default:
                                    mostrarError("Opción inválida.");
                                    pausar();
                                    break;
                            }
                        
                    } while (opcion != 0);
            }

        void gestionarPedidos() 
            {
                int opcion;

                do 
                    {
                        opcion = mostrarMenuPedidos();
                        
                        switch (opcion) 
                            {
                                case 1: // Crear Pedido.
                                    crearPedido();
                                    break;
                                    
                                case 2: // Lista Pedidos.
                                    listarPedidos();
                                    break;
                                    
                                case 3: // Agrega Producto a Pedido.
                                    agregarProductoAPedido();
                                    break;
                                    
                                case 0: // Vuelve al Menú Principal.
                                    break;
                                    
                                default:
                                    mostrarError("Opción inválida.");
                                    pausar();
                                    break;
                            }

                    } while (opcion != 0);
            }

        void simularComportamientos() 
            {
                int opcion;

                do 
                    {
                        opcion = mostrarMenuSimulacion();
                        
                        switch (opcion) 
                            {
                                case 1: // Simula Alimentación.
                                    simularAlimentacion();
                                    break;
                                    
                                case 2: // Simula Sueño.
                                    simularSueno();
                                    break;
                                    
                                case 3: // Simula Sonidos.
                                    simularSonidos();
                                    break;
                                    
                                case 0: // Vuelve al Menú Principal.
                                    break;
                                    
                                default:
                                    mostrarError("Opción inválida.");
                                    pausar();
                                    break;
                            }
                        
                    } while (opcion != 0);
            }

        void mostrarReportes() 
            {
                mostrarEncabezado("REPORTES DEL SISTEMA 📊");
                
                std::cout << "📈 RESUMEN DEL SISTEMA:\n";

                mostrarSeparador('-');

                std::cout << "🐓 Animales registrados: " << cantidadAnimales << "/" << MAX_ANIMALES << "\n";
                std::cout << "🛒 Productos registrados: " << cantidadProductos << "/" << MAX_PRODUCTOS << "\n";
                std::cout << "👤 Clientes registrados: " << cantidadClientes << "/" << MAX_CLIENTES << "\n";
                std::cout << "📦 Pedidos registrados: " << cantidadPedidos << "/" << MAX_PEDIDOS << "\n";

                mostrarSeparador('=');
                
                // Calcula el valor total del inventario.
                double valorTotal = 0.0;

                for (int i = 0; i < cantidadProductos; i++) 
                    {
                        valorTotal += productos[i]->getPrecio();
                    }
                
                std::cout << "\n💰 VALOR TOTAL DEL INVENTARIO: " << formatearPrecio(valorTotal) << "\n";
                
                // Muestra estadísticas por tipo de animal.
                int pollos = 0, cerdos = 0, vacas = 0;

                for (int i = 0; i < cantidadAnimales; i++) 
                    {
                        std::string tipo = animales[i]->getTipoCarne();

                        if (tipo.find("pollo") != std::string::npos || tipo.find("Pollo") != std::string::npos) pollos++;
                            else if (tipo.find("cerdo") != std::string::npos || tipo.find("Cerdo") != std::string::npos) cerdos++;
                                else if (tipo.find("vaca") != std::string::npos || tipo.find("Vaca") != std::string::npos) vacas++;
                    }
                
                std::cout << "\n📊 DISTRIBUCIÓN DE ANIMALES:\n";
                std::cout << "🐔 Pollos: " << pollos << "\n";
                std::cout << "🐖 Cerdos: " << cerdos << "\n";
                std::cout << "🐄 Vacas: " << vacas << "\n";
                
                // Muestra el total de pedidos.
                double totalPedidos = 0.0;
                for (int i = 0; i < cantidadPedidos; i++) 
                    {
                        totalPedidos += pedidos[i]->getTotal();
                    }
                
                std::cout << "\n💰 VALOR TOTAL DE PEDIDOS: " << formatearPrecio(totalPedidos) << "\n";
                
                mostrarSeparador('=');
                
                std::cout << "📅 Fecha del reporte: " << obtenerFechaActual() << "\n";
                
                pausar();
            }

        void limpiarMemoria() 
            {
                // Libera memoria de animales.
                for (int i = 0; i < cantidadAnimales; i++) 
                    {
                        delete animales[i];
                        animales[i] = nullptr;
                    }
                
                // Libera memoria de productos.
                for (int i = 0; i < cantidadProductos; i++) 
                    {
                        delete productos[i];
                        productos[i] = nullptr;
                    }
                
                // Libera memoria de clientes.
                for (int i = 0; i < cantidadClientes; i++) 
                    {
                        delete clientes[i];
                        clientes[i] = nullptr;
                    }
                
                // Libera memoria de pedidos.
                for (int i = 0; i < cantidadPedidos; i++) 
                    {
                        delete pedidos[i];
                        pedidos[i] = nullptr;
                    }
                
                mostrarInformacion("Memoria liberada exitosamente.");
            }

        // ==================== Funciones específicas de gestión ====================
        void crearPollo() 
            {
                if (hayEspacioArray(cantidadAnimales, MAX_ANIMALES)) 
                    {
                        mostrarEncabezado("CREAR POLLO 🐔");
                        std::string nombre = leerString("Nombre del pollo: ");
                        std::string tipoCarne = leerString("Tipo de carne: ");
                        int edad = leerEntero("Edad (meses): ", 1, 120);
                        int huevos = leerEntero("Cantidad de huevos por día: ", 0, 10);
                        
                        animales[cantidadAnimales++] = new Pollo(nombre, tipoCarne, edad, huevos);
                        mostrarExito("Pollo '" + nombre + "' creado exitosamente.");

                    } else 
                        {

                            mostrarError("No hay espacio para más animales.");
                        }
                
                pausar();
            }

        void crearCerdo() 
            {
                if (hayEspacioArray(cantidadAnimales, MAX_ANIMALES)) 
                    {
                        mostrarEncabezado("CREAR CERDO 🐖");
                        std::string nombre = leerString("Nombre del cerdo: ");
                        std::string tipoCarne = leerString("Tipo de carne: ");
                        int edad = leerEntero("Edad (meses): ", 1, 240);
                        bool salvaje = leerBooleano("¿Es salvaje?");
                        
                        animales[cantidadAnimales++] = new Cerdo(nombre, tipoCarne, edad, salvaje);
                        mostrarExito("Cerdo '" + nombre + "' creado exitosamente.");

                    } else 
                        {
                            mostrarError("No hay espacio para más animales.");
                        }

                pausar();
            }

        void crearVaca() 
            {
                if (hayEspacioArray(cantidadAnimales, MAX_ANIMALES)) 
                    {
                        mostrarEncabezado("CREAR VACA 🐄");
                        std::string nombre = leerString("Nombre de la vaca: ");
                        std::string tipoCarne = leerString("Tipo de carne: ");
                        int edad = leerEntero("Edad (meses): ", 1, 360);
                        double leche = leerDouble("Litros de leche por día: ", 0.0, 50.0);
                        
                        animales[cantidadAnimales++] = new Vaca(nombre, tipoCarne, edad, leche);
                        mostrarExito("Vaca '" + nombre + "' creada exitosamente.");

                    } else 
                        {
                            mostrarError("No hay espacio para más animales.");
                        }

                pausar();
            }

        void listarAnimales() 
            {
                mostrarEncabezado("LISTADO DE ANIMALES 📋");

                if (cantidadAnimales == 0) 
                    {
                        mostrarInformacion("No hay animales registrados.");
                        
                    } else 
                        {
                            for (int i = 0; i < cantidadAnimales; i++) 
                                {
                                    std::cout << i + 1 << ". ";
                                    mostrarEmojiAnimal(animales[i]->getTipoCarne());
                                    animales[i]->mostrarInfo();
                                    std::cout << "\n";
                                }
                        }

                pausar();
            }

        void eliminarAnimal() 
            {
                mostrarEncabezado("ELIMINAR ANIMAL 🗑️");

                if (cantidadAnimales == 0) 
                    {
                        mostrarInformacion("No hay animales para eliminar.");
                        pausar();
                        return;
                    }
                
                std::cout << "Animales disponibles:\n";

                for (int i = 0; i < cantidadAnimales; i++) 
                    {
                        std::cout << i + 1 << ". ";
                        mostrarEmojiAnimal(animales[i]->getTipoCarne());
                        std::cout << animales[i]->getNombre() << " (" << animales[i]->getTipoCarne() << ")\n";
                    }
                
                int idx = leerEntero("Selecciona el animal a eliminar: ", 1, cantidadAnimales) - 1;
                
                // Verifica si el animal está siendo usado por algún producto.
                bool enUso = false;

                for (int i = 0; i < cantidadProductos; i++) 
                    {
                        if (productos[i]->getAnimalOrigen() == animales[idx]) 
                            {
                                enUso = true;
                                break;
                            }
                    }
                
                if (enUso) 
                    {
                        mostrarError("No se puede eliminar el animal porque está siendo usado por uno o más productos.");

                    } else 
                        {
                            std::string nombre = animales[idx]->getNombre();
                            delete animales[idx];
                            
                            // Mueve los elementos restantes.
                            for (int i = idx; i < cantidadAnimales - 1; i++) 
                                {
                                    animales[i] = animales[i + 1];
                                    
                                }
                            animales[--cantidadAnimales] = nullptr;
                            
                            mostrarExito("Animal '" + nombre + "' eliminado exitosamente.");
                        }

                pausar();
            }

        void crearProducto() 
            {
                if (hayEspacioArray(cantidadProductos, MAX_PRODUCTOS)) 
                    {
                        mostrarEncabezado("CREAR PRODUCTO 🆕");
                        
                        if (cantidadAnimales == 0) 
                            {
                                mostrarError("No hay animales disponibles. Crea primero un animal.");
                                pausar();
                                return;
                            }
                        
                        int id = leerEntero("ID del producto: ", 1, 1000);
                        std::string nombre = leerString("Nombre del producto: ");
                        double precio = leerDouble("Precio: ", 0.0, 100000.0);
                        
                        // Muestra animales disponibles.
                        std::cout << "\nAnimales disponibles:\n";

                        for (int i = 0; i < cantidadAnimales; i++) 
                            {
                                std::cout << i + 1 << ". ";
                                mostrarEmojiAnimal(animales[i]->getTipoCarne());
                                std::cout << animales[i]->getNombre() << " - " << animales[i]->getTipoCarne() << "\n";
                            }
                        
                        int idxAnimal = leerEntero("Selecciona el animal de origen: ", 1, cantidadAnimales) - 1;

                        // Verifica que el índice sea válido.
                        if (idxAnimal < 0 || idxAnimal >= cantidadAnimales) 
                            {
                                mostrarError("Índice de animal inválido. No se puede crear el producto.");
                                pausar();
                                return;
                            }

                        // Verifica que el puntero al animal no sea nulo.
                        if (animales[idxAnimal] == nullptr) 
                            {
                                mostrarError("El animal seleccionado no existe o ha sido eliminado.");
                                pausar();
                                return;
                            }
                        
                        productos[cantidadProductos++] = new Producto(id, nombre, precio, animales[idxAnimal]);
                        mostrarExito("Producto '" + nombre + "' creado exitosamente.");

                    } else 
                        {
                            mostrarError("No hay espacio para más productos.");
                        }
                
                pausar();
            }

        void listarProductos() 
            {
                mostrarEncabezado("LISTADO DE PRODUCTOS 📋");

                if (cantidadProductos == 0) 
                    {
                        mostrarInformacion("No hay productos registrados.");
                        
                    } else 
                        {
                            for (int i = 0; i < cantidadProductos; i++) 
                                {
                                    std::cout << i + 1 << ". ";
                                    productos[i]->mostrarInfo();
                                    std::cout << "\n";
                                }
                        }

                pausar();
            }

        void eliminarProducto() 
            {
                mostrarEncabezado("ELIMINAR PRODUCTO 🗑️");

                if (cantidadProductos == 0) 
                    {
                        mostrarInformacion("No hay productos para eliminar.");
                        pausar();
                        return;
                    }
                
                std::cout << "Productos disponibles:\n";

                for (int i = 0; i < cantidadProductos; i++) 
                    {
                        std::cout << i + 1 << ". ";
                        productos[i]->mostrarInfo();
                        std::cout << "\n";
                    }
                
                int idx = leerEntero("Selecciona el producto a eliminar: ", 1, cantidadProductos) - 1;
                
                std::string nombre = productos[idx]->getNombre();
                delete productos[idx];
                
                // Mueve los elementos restantes.
                for (int i = idx; i < cantidadProductos - 1; i++) 
                    {
                        productos[i] = productos[i + 1];
                    }

                productos[--cantidadProductos] = nullptr;
                
                mostrarExito("Producto '" + nombre + "' eliminado exitosamente.");
                pausar();
            }

        void registrarCliente() 
            {
                if (hayEspacioArray(cantidadClientes, MAX_CLIENTES)) 
                    {
                        mostrarEncabezado("REGISTRAR CLIENTE 🆕");

                        int id = leerEntero("ID del cliente: ", 1, 1000);

                        std::string nombre = leerString("Nombre del cliente: ");
                        std::string direccion = leerString("Dirección: ");
                        
                        clientes[cantidadClientes++] = new Cliente(id, nombre, direccion);

                        mostrarExito("Cliente '" + nombre + "' registrado exitosamente.");

                    } else 
                        {
                            mostrarError("No hay espacio para más clientes.");
                        }

                pausar();
            }

        void listarClientes() 
            {
                mostrarEncabezado("LISTADO DE CLIENTES 📋");

                if (cantidadClientes == 0) 
                    {
                        mostrarInformacion("No hay clientes registrados.");
                    } else 
                        {
                            for (int i = 0; i < cantidadClientes; i++) 
                                {
                                    std::cout << i + 1 << ". ";
                                    clientes[i]->mostrarInfo();
                                    std::cout << "\n";
                                }
                        }
                
                pausar();
            }

        void eliminarCliente() 
            {
                mostrarEncabezado("ELIMINAR CLIENTE 🗑️");

                if (cantidadClientes == 0) 
                    {
                        mostrarInformacion("No hay clientes para eliminar.");
                        pausar();
                        return;
                    }
                
                std::cout << "Clientes disponibles:\n";

                for (int i = 0; i < cantidadClientes; i++) 
                    {
                        std::cout << i + 1 << ". ";
                        clientes[i]->mostrarInfo();
                        std::cout << "\n";
                    }
                
                int idx = leerEntero("Selecciona el cliente a eliminar: ", 1, cantidadClientes) - 1;
                
                // Verifica si el cliente tiene pedidos.
                bool tienePedidos = false;

                for (int i = 0; i < cantidadPedidos; i++) 
                    {
                        if (pedidos[i]->getCliente() == clientes[idx]) 
                            {
                                tienePedidos = true;
                                break;
                            }
                    }
                
                if (tienePedidos) 
                    {
                        mostrarError("No se puede eliminar el cliente porque tiene pedidos asociados.");

                    } else 
                        {
                            std::string nombre = clientes[idx]->getNombre();
                            delete clientes[idx];
                            
                            // Mueve los elementos restantes.
                            for (int i = idx; i < cantidadClientes - 1; i++) 
                                {
                                    clientes[i] = clientes[i + 1];
                                }

                            clientes[--cantidadClientes] = nullptr;
                            
                            mostrarExito("Cliente '" + nombre + "' eliminado exitosamente.");
                        }

                pausar();
            }

        void crearPedido() 
            { 
                if (hayEspacioArray(cantidadPedidos, MAX_PEDIDOS)) 
                    {
                        mostrarEncabezado("CREAR PEDIDO 🆕");
                        
                        if (cantidadClientes == 0) 
                            {
                                mostrarError("No hay clientes disponibles. Registre primero un cliente.");
                                pausar();
                                return;
                            }
                        
                        int idPedido = leerEntero("ID del pedido: ", 1, 1000);
                        
                        // Muestra clientes disponibles.
                        std::cout << "\nClientes disponibles:\n";
                        for (int i = 0; i < cantidadClientes; i++) 
                            {
                                std::cout << i + 1 << ". ";
                                clientes[i]->mostrarInfo();
                                std::cout << "\n";
                            }
                        
                        int idxCliente = leerEntero("Selecciona el cliente: ", 1, cantidadClientes) - 1;
                        
                        pedidos[cantidadPedidos++] = new Pedido(idPedido, clientes[idxCliente]);
                        mostrarExito("Pedido #" + std::to_string(idPedido) + " creado exitosamente.");

                    } else 
                        {
                            mostrarError("No hay espacio para más pedidos.");
                        }
                
                pausar();
            }

        void listarPedidos() 
            {
                mostrarEncabezado("LISTADO DE PEDIDOS 📋");

                if (cantidadPedidos == 0) 
                    {
                        mostrarInformacion("No hay pedidos registrados.");
                    } else 
                        {
                            for (int i = 0; i < cantidadPedidos; i++) 
                                {
                                    std::cout << i + 1 << ". ";
                                    pedidos[i]->mostrarPedido();
                                    std::cout << "\n";
                                }
                        }

                pausar();
            }

        void agregarProductoAPedido() 
            {
                mostrarEncabezado("AGREGAR PRODUCTO A PEDIDO 📝");

                if (cantidadPedidos == 0 || cantidadProductos == 0) 
                    {
                        mostrarError("No hay pedidos o productos disponibles.");
                        pausar();
                        return;
                    }
                
                // Selecciona pedido.
                std::cout << "Pedidos disponibles:\n";

                for (int i = 0; i < cantidadPedidos; i++) 
                    {
                        std::cout << i + 1 << ". Pedido #" << pedidos[i]->getIdPedido() << " - Cliente: " 
                                  << pedidos[i]->getCliente()->getNombre() << "\n";
                    }

                int idxPedido = leerEntero("Selecciona el pedido: ", 1, cantidadPedidos) - 1;
                
                // Selecciona producto.
                std::cout << "\nProductos disponibles:\n";

                for (int i = 0; i < cantidadProductos; i++) 
                    {
                        std::cout << i + 1 << ". ";
                        productos[i]->mostrarInfo();
                        std::cout << "\n";
                    }

                int idxProducto = leerEntero("Selecciona el producto: ", 1, cantidadProductos) - 1;
                
                if (pedidos[idxPedido]->agregarProducto(productos[idxProducto])) 
                    {
                        mostrarExito("Producto '" + productos[idxProducto]->getNombre() + "' agregado al pedido #" + 
                                     std::to_string(pedidos[idxPedido]->getIdPedido()) + " exitosamente.");
                    } else 
                        {
                            mostrarError("No se pudo agregar el producto (pedido lleno).");
                        }
                
                pausar();
            }

        void simularAlimentacion() 
            {
                mostrarEncabezado("SIMULACIÓN DE ALIMENTACIÓN 🍽️");

                if (cantidadAnimales == 0) 
                    {
                        mostrarInformacion("No hay animales para simular.");
                        
                    } else 
                        {
                            std::cout << "Los animales están comiendo:\n";
                            mostrarSeparador('-');

                            for (int i = 0; i < cantidadAnimales; i++) 
                                {
                                    std::cout << i + 1 << ". ";
                                    mostrarEmojiAnimal(animales[i]->getTipoCarne());
                                    std::cout << animales[i]->getNombre() << ": ";
                                    animales[i]->comer();
                                    std::cout << "\n";
                                }
                        }

                pausar();
            }

        void simularSueno() 
            {
                mostrarEncabezado("SIMULACIÓN DE SUEÑO 😴");

                if (cantidadAnimales == 0) 
                    {
                        mostrarInformacion("No hay animales para simular.");
                    } else 
                        {
                            std::cout << "Los animales están durmiendo:\n";
                            mostrarSeparador('-');

                            for (int i = 0; i < cantidadAnimales; i++) 
                                {
                                    std::cout << i + 1 << ". ";
                                    mostrarEmojiAnimal(animales[i]->getTipoCarne());
                                    std::cout << animales[i]->getNombre() << ": ";
                                    animales[i]->dormir();
                                    std::cout << "\n";
                                }
                        }
                
                pausar();
            }

        void simularSonidos() 
            {
                mostrarEncabezado("SIMULACIÓN DE SONIDOS 🔊");

                if (cantidadAnimales == 0) 
                    {
                        mostrarInformacion("No hay animales para simular.");

                    } else 
                        {
                            std::cout << "Los animales están haciendo sonidos:\n";
                            mostrarSeparador('-');

                            for (int i = 0; i < cantidadAnimales; i++) 
                                {
                                    std::cout << i + 1 << ". ";
                                    mostrarEmojiAnimal(animales[i]->getTipoCarne());
                                    std::cout << animales[i]->getNombre() << ": ";
                                    animales[i]->sonido();
                                    std::cout << "\n";
                                }
                        }
                
                pausar();
            }
    }