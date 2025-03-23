cmake_minimum_required(VERSION 3.19)
project(POOSistemaGestionVentas)

set(CMAKE_CXX_STANDARD 20)

add_executable(POOSistemaGestionVentas
        main.cpp
        src/tienda.cpp
        src/producto.cpp
        src/cliente.cpp
        src/venta.cpp
)