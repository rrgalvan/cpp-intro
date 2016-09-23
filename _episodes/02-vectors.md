---
title: "Using C++ Objects: Vectors"
teaching: 10
exercises: 0
questions:
- "How can I create a vector of real numbers in C++?"
objectives:
- "Introduce C++ classes and objects"
- "Create and manipulate vector objects from the standard library"
- "Be aware of the strengths and limitations of these vector objects"
keypoints:
- "Lessons are stored in Git repositories on GitHub."
- "Lessons are written in Markdown."
- "Jekyll translates the files in the gh-pages branch into HTML for viewing."
- "The site's configuration is stored in _config.yml."
- "Each page's configuration is stored at the top of that page."
- "Groups of files are stored in collection directories whose names begin with an underscore."
---

Este episodio se centra en la creación y manipulación de objetos de tipo *vector*, que son instanciados a partir de la clase `std::vector` (contenida en la biblioteca estándar de C++).

## Clases y objetos

Los conceptos básicos en C++ son: *funciones* y *clases*

- Las **funciones** en C++, como en la mayor parte de los lenguajes de programación (C, Fortran, Java,...), son abstracciones de algoritmos. Reciben una serie de argumentos de entrada y, a través de una serie de instrucciones que implementan un algoritmo, devuelven (eventualmente) un argumento de salida. Las funciones permiten emplear en C++ el paradigma de la *programación modular*.

- Las **clases** en C++ son abstracciones que encapsulan...

  - *datos* (también llamados *atributos*) y
  - *métodos* (funciones que operan sobre esos datos).

Con frecuencia, los atributos son privados y solamente se puede acceder a ellos a través de los métodos que, a tal efecto, dispone la clase.

Las clases permiten emplear en C++ el paradigma de la *programación orientada a objetos*. Un **objeto** en C++ consiste simplemente en una variable que viene dada como representación concreta de una clase.
Existen unos métodos, llamados *constructores*, que están especializados en crear nuevos objetos

Para conocer más detalles sobre la forma de crear nuevas clases véase, por ejemplo, la sección 2.3 de [[B. Stroustrup (4th edition)]].

## La clase `vector` de la biblioteca estándar
La biblioteca estándar de C++ contiene diversas clases que pueden usarse como *contenedores* de datos. Una de ellas, en las que nos centraremos aquí, es la clase `vector`, que es utilizaremos para sustituir a los *arrays* de C.

Para acceder a ella, basta usar:

~~~
#include <vector>
~~~
{: .cpp}

Sabiendo que está situada dentro de la biblioteca estándar, podremos construir objetos de esta clase. Por ejemplo, la siguiente línea construye un vector de números en doble precisión.

~~~
std::vector<double> u;
~~~
{: .cpp}

En principio, el vector anterior no contiene ningún elemento. Existe la posibilidad de especificar el número de elementos en el momento de la construcción:

~~~
std::vector<double> v(2); // Vector con dos elementos
~~~
{: .cpp}

Ahora podemos utilizar el vector de forma similar a los arrays de C:

~~~
v[0]=1; v[1]=3.14;
std::cout << v[0]+v[1] << std::endl;
~~~
{: .cpp}

Pero la clase `vector` cuenta con métodos que la dotan de mayor potencia que a los viejos *arrays*. Por ejemplo:

~~~
int n = v.size(); // Obtener el número de elementos  del vector
u = v;            // Asignar el contenido de v al vector u (que cambia dinámicamente)
v.resize(3);      // Redimensionar v: ahora tiene 3 elementos (u sigue teniendo  2)
v[2] = u.back();  // El tercer elemento de v será igual al último de u
~~~
{: .cpp}


> ## Un programa que resume lo anterior
>
> ~~~
> #include <iostream>
> #include <vector>
> #include <cmath> // Usaremos la función 'pow' de la bibilioteca matemática de C
>
> void print_vector_double(std::vector<double> v) {
>   // Imprimimos el tamaño del vector y su contenido
>   int n = v.size();
>   std::cout << "[";
>   if (n>0) std::cout << v[0]; // Imprimer el primer elemento
>   for (int i=1; i<n; i++) std::cout << ',' << v[i]; // Imprimir los restantes
>   std::cout  << "]" << std::endl;
> }
>
> int main()
> {
>   const int n=4; // Dimensión del vector (número de elementos almacenados)
>   std::vector<double> v(n);  // Vector formado por n números (doble precisión)
>   for (int i=0; i<n; i++) v[i]= pow(2,i); // Cargamos los elementos: 1, 2, 4, 8
>   print_vector_double(v); // Imprimir el resultado
> }
> ~~~
> {: .cpp}
{: .challenge}

  - La clase `vector` puede contener cualquier número de elementos que son (esencialmente) los atributos que contiene la clase. Los elementos pueden ser de cualquier tipo válido en C++ (enteros, números en coma flotante, caracteres,... incluso otros vectores u objetos de cualquier clase),
  - La clase `vector` contiene una gran cantidad de métodos, mediante los cuales se accede a información de sus elementos o se manipula a los mismos. Por ejemplo, el método `size` devuelve el número de elementos contenidos en un objeto `vector` y el método `clear` elimina todos los elementos contenidos.

El siguiente programa construye un vector formado por tres números reales (en formato doble precisión), les asigna valores e imprime el resultado.

~~~

~~~
{: .cpp}



[B. Stroustrup (4th edition)]: http://www.stroustrup.com/4th.html
