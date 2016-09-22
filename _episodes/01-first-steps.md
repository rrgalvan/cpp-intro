---
title: "First Steps"
teaching: 15
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
> - Todo espacio de nombres puede usarse, además, *de forma implícita* mediante la orden `using namespace`. Por ejemplo, el programa anterior es equivalente al siguiente (nota: C++ usa `//` para comentarios):
>
> ~~~
> #include <iostream>
> using namespace std // Los nombres de std serán visibles sin std::
> int main(int argc, char** argv)
> {
>  cout << "¡Hola mundo!" << endl;
> }
> ~~~
>  Como se puede observar en C++ se usa `//` para los comentarios
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

>
> ## Otras opciones de compilación
>
> El compilador `g++` admite muchas otras opciones, entre ellas:
>
> - `-l`: Utilizar una biblioteca
> - `-I`: Explicitar un directorio desde donde incluir ficheros
> - `-Wall`: Al compilar, mostrar tanos mensajes de aviso (*warnings*) como sea posible (para poder localizar posibles errores).
>
> Por ejemplo, consideremos el siguiente programa, al que llamaremos `ejemplo2.cpp`
>
> ~~~
> #include <iostream>
> #include <cmath> // Biblioteca matemática de C
> int main()
> {
>   // Declaramos dos números en doble precisión.
>   double x, y=3; // A y le asignamos un valor
>   std::cout << "La raíz de " << y << " es " << sqrt(y) << std::endl;
> }
> ~~~
> {: .cpp}
>
> En él se calcula la raíz de *y=3*. Se declara una variable, *x*, que no se utiliza, lo que podría ser un indicio de errores en futuras versiones.
> Si compilamos con la opción `-Wall`, el compilador nos advertirá de este heho:
>
> ~~~
> g++ -Wall ejemplo1 -o ejemplo1
> ~~~
> {: .cpp}
>
> ~~~
> math.cpp: In function ‘int main()’:
> math.cpp:7:10: warning: unused variable ‘x’ [-Wunused-variable]
>    double x, y=3; // A y le asignamos un valor
>           ^
> ~~~
> {: .output}
{: .discussion}

## Tipos de datos, variables, funciones y aritmética

La sintaxis básica de C++ está basada en C con algunas extensiones, como muestran el siguiente ejemplos. Para conocer más detalles, puede consultarse un tutorial como el contenido en el capítulo 2 de [[B. Stroustrup (4th edition)]]

> ## Un ejemplo más extenso
> En el siguiente ejemplo se muestra un programa C++ que define dos funciones y, utilizándolas junto a un bucle *for*, las aplica a un rango de valores
>
> ~~~
> #include <iostream>
>
> // Calculate the square of double precision floating-point number
> double square(double x)
> {
>   return x*x;
> }
>
> // Print a formated string showing the square of x
> void print_square(double x)
> {
>   std::cout << "The square of " << x
> 	    << " is: " << square(x) << std::endl;
> }
>
> int main()
> {
>   int nSquares = 5;
>   double x=1;
>   for (int i=0; i<nSquares; i++)
>     {
>       print_square(x);
>       x = x+1;
>     }
> }
>
> ~~~
> {: .cpp}
{: .callout}

El resultado debe ser el siguiente:

> ~~~
> The square of 1 is: 1
> The square of 2 is: 4
> The square of 3 is: 9
> The square of 4 is: 16
> The square of 5 is: 25
> ~~~
> {: .output}

> ## Variantes del programa anterior
>
> Programar una variante del programa anterior que:
>
> - Sustituya la función `square` por $$f(x)=\cos(x^2+1)r$$
> - Sustituya el bucle `for` por un bucle `while`
>
{: .challenge}

[Code::Blocks]: http://www.codeblocks.org
[Eclipse]: [Code::Blocks] http://www.eclipse.org/downloads/packages/eclipse-ide-cc-developers/marsr
[Emacs]: https://www.gnu.org/software/emacs
[Vim]: http://www.vim.org
[Vi]: http://www.vim.org
[Nano]: https://www.nano-editor.org
[GCC]: http://gcc.gnu.org
[B. Stroustrup (4th edition)]: http://www.stroustrup.com/4th.html
