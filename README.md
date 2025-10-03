<h1 align=center>PROYECTO GET_NEX_LINE</h1>

¡Bienvenido al proyecto get_next_line de 42 Madrid!

Este proyecto consiste en la implementación de la función get_next_line en C, la cual lee línea por línea desde un descriptor de archivo. Esta función es parte del curriculum de la escuela 42 Madrid y tiene como objetivo principal entender y aplicar el manejo de archivos y la gestión dinámica de memoria en el lenguaje C.

## Tabla de contenidos
- [¿Cual es el Objetivo?](#cual-es-el-Objetivo)
- [Listado de funciones](#lista-de-funciones)
- [Modo de Uso](#Modo-de-Uso)

 <hr>

### ¿Qué es `GET_NEXT_LINE`?

get_next_line es una función en C que permite leer línea por línea desde un descriptor de archivo. Esta función es especialmente útil cuando se trabaja con archivos de texto grandes y se necesita procesar la información de forma eficiente, sin cargar todo el archivo en memoria de una vez.

### ¿cual es el objetivo?

El objetivo principal del proyecto get_next_line es implementar la función get_next_line, comprender su funcionamiento y aplicar conceptos clave de programación en C, como la gestión de memoria y el manejo de archivos. Durante el desarrollo del proyecto, también se utiliza la herramienta de depuración lldb para identificar y corregir cualquier fuga de memoria, asegurando así un manejo correcto de los recursos.

## Lista de funciones:

|      Funciones de Get_next_line    |
| :----------------------------------: 
| [get_next_line.c](/get_next_line.c) |
| [get_next_line_utils.c](/get_next_line_utils.c) |
| [get_next_line_bonus.c](/get_next_line_bonus.c) |
| [get_next_line_utils_bonus.c](/get_next_line_utils_bonus.c) |

### Modo de Uso
Para utilizar este proyecto, sigue estos pasos:
- Clona el repositorio desde GitHub.
  -- git clone ...
- Crea una funcion main y vincula el file descriptor.
- Compila en la terminal y Una vez compilado, ejecuta el programa con los descriptores de archivo deseados.

### Compilación
Para compilar tu programa :
- gcc -o mi_programa get_next_line.c get_next_line_utils.c main.c 

