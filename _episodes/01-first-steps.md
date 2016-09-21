---
title: "First Steps"
teaching: 10
exercises: 2
questions:
- "¿Cómo creo, compilo y ejecuto mi primer programa en C++?"
objectives:
- "Conocer la sintaxis de C++ para imprimir información en la consola"
- "Ser capaz de crear, compilar y ejecutar este programa"
keypoints:
- "La sintaxis de C++ es similar a la del lenguaje C (a la que extiende)"
- "Para imprimir hacia la consola, dirigimos los datos a la salida estándar `std::cout`"
- "Podemos usar cualquier editor para crear un programa C++"
- "Podemos compilarlo con GNU/C++ mediante la orden `g++`"
---

Este episodio se centra en la forma de compilar y ejecutar programas C++ en la shell UNIX. Aunque (en cierto modo) C++ es un superconjunto del lenguaje C, nos centraremos en la sintaxis específica de C++ e intentaremos sacar partido a las capacidades introducidas en las últimas versiones (`c++2003`, `c++2011`, `c++2014`).

## Un primer programa en C++

Un programa de ordenador es una secuencia de instrucciones que actúan sobre un conjunto de datos. Todo programa debe tenr un punto de entrada a estas instrucciones. Como en el lenguaje *C*, el punto de entrada para un programa *C++* es la función **main**, que en su forma más simple se escribe como

~~~
int main(int argc, char** argv) {
}
~~~
{: .cpp}

Como en *C*, la función *main* toma dos argumentos, un entero *argc* y
una lista de cadenas de caracteres, *argv*, que en este caso no son
usados. De hecho, el programa anterior no realiza ninguna tarea pues
la función *main* no contiene ninguna instrucción. Añadiremos dos
nuevas líneas de código para que el programa muestre en la consola :

~~~
#include <iostream>
int main(int argc, char** argv)
{
  std::cout << "¡Hola mundo!" << std::endl;
}
~~~
{: .cpp}

La primera línea, carga la biblioteca estándar *iostream* (que
contiene los servicios básicos de entrada/salida en *C++*). Ésta
biblioteca es usada por la única intrucción del programa, contenida
entre llaves `{` `}`. En esta instrucción se envía (usando el operador `<<`) a la salida
estándar `std::cout` (que habitualmente coincide con la consola UNIX)
el texto "¡Hola mundo!" seguido por un carácter de fin de línea `std::endl`.

>
> ## El espacio de nombres estándar
>
> - La expresión `std::` en el programa anterior especifica *de forma explícita* que el nombre `cout` se puede encontrar en el espacio de nombres de la biblioteca estándar (y lo mismo para `endl`). Esta biblioteca contiene muchos otros objetos y funciones interesantes, algunos de los cuales se detallarán más adelante.
> - Todo espacio de nombres puede usarse, además, *de forma implícita* mediante la orden `using namespace`. Por ejemplo, el programa anterior es equivalente al siguiente:
>
> ~~~
> #include <iostream>
> using namespace std
> int main(int argc, char** argv)
> {
>  cout << "¡Hola mundo!" << endl;
> }
> ~~~
> {: .cpp}
{: .discussion}



## Compilación con GNU C++

Con frecuencia se utilizan editores especializados o entornos integrados para la compilación de ficheros C++, que permiten combinar la edición, compilación y ejecución de los programas en entornos de escritorio. Muchos de estos entornos permiten utilizar proyectos de compilación en formatos *Make* y/o *CMake*.

>
> ## Algunos editores y entornos integrados recomendados
>
>  Con licencia libre, multi-plataforma (GNU/Linux, MacOS, Windows). Ordenados menor a mayor facilidad de uso (no por su potencia).
>
> - [Code::Blocks]
> - [Eclipse]
> - [Emacs]
> - [Vim]
{: .discussion}

En vez de optar por un entorno integrado, los conceptos serán independientes del editor utilizado. Se incluye así la posibilidad de utilizar editores (como [Emacs], [Vi] o [Nano]) dentro de terminales UNIX. Este caso es usual en sesiones remotas (en entornos UNIX que son ejecutados en servidores remotos).

>
> ## Edición del programa `holamundo.cpp`
>
> Ejercicio: utilizando la consola UNIX:
>
> 1. Crear, dentro del directorio de inicio del usuario, un directorio llamado `proyectos` y dentro de él uno nuevo llamado `c++`
> 2. Crear, dentro del directorio `c++`, un fichero llamado `holamundo.cpp` que contenga el código C++ que fue introducido anteriormente
>
{: .challenge}

Antes de procesar el programa anterior, debemos asegurarnos de contar con un compilador C++ adecuado. Aquí nos centraremos en el compilador GNU C++, que forma parte de [GCC] (GNU Compiler Collection).

>
> ## Instalación del compilador GNU C++
>
> - GNU C++ tiene licencia libre y puede instalarse en todos los sistemas operativos usuales.
> - En entornos GNU/Linux basados en Debian (como Ubuntu), es suficiente teclear en la consola UNIX la siguiente orden (que instalará además otras herramienteas como el compilador GNU C o la herramienta de compilación Make:
>
> ~~~
> sudo apt-get install build-essential
> ~~~
> {: .bash}
{: .discussion}

Utilizando este compilador y suponiendo que nos encontramos, dentro de la consola UNIX, en el directorio c++, podemos compilar el programa `holamundo.cpp` mediante la siguiente orden:

> ~~~
> g++ holamundo.cpp -o holamundo
> ~~~
> {: .bash}

Como resultado, contaremos con un programa ejecutable llamado `holamundo`, situado en el directorio actual. Por supuesto, el nombre `holamundo` puede modificarse o, incluso, la opción `-o holamundo` puede ser eliminada (y en este caso, el programa resultante se llamará `a.out`). A continuación, podemos ejecutar el programa de la siguiente forma,

> ~~~
> ./holamundo
> ~~~
> {: .bash}

obteniendo el siguiente resultado:

> ~~~
> ¡Hola mundo!
> ~~~
> {: .output}

## Tipos de datos, variables, funciones y aritmética



[Code::Blocks]: http://www.codeblocks.org/
[Eclipse]: [Code::Blocks] http://www.eclipse.org/downloads/packages/eclipse-ide-cc-developers/marsr
[Emacs]: https://www.gnu.org/software/emacs/
[Vim]: http://www.vim.org/
[Vi]: http://www.vim.org/
[Nano]: https://www.nano-editor.org/
[GCC]: http://gcc.gnu.org
