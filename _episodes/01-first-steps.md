---
title: "First Steps"
teaching: 10
exercises: 0
questions:
- "¿Cómo creo, compilo y ejecuto mi primer programa en C++?"
objectives:
- "Conocer la sintaxis de C++ para imprimir información en la consola"
- "Ser capaz de crear, compilar y ejecutar este programa"
keypoints:
- "Punto clave 1"
- "Punto clave 2"
---

Este episodio se centra en la forma de compilar y ejecutar programas C++ en la shell UNIX.

## El primer programa en C++

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
contiene los servicios básicos de entrada/salida en *C++*). Gracias a
ella, la única intrucción del programa envía a la consola el texto
"¡Hola mundo!" seguido por un carácter de fin de línea.

## Compilación con GNU C++




[concept-maps]: {{ page.training }}/07-memory/
[python-gapminder]: https://swcarpentry.github.io/python-novice-gapminder/
[training]: {{ page.training }}/
