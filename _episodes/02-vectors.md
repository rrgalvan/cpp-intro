---
title: "Using C++ Objects: Vectors"
teaching: 15
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
- La clase `vector` puede contener cualquier número de elementos que son (esencialmente) los atributos que contiene la clase. Los elementos pueden ser de cualquier tipo válido en C++ (enteros, números en coma flotante, caracteres,... incluso otros vectores u objetos de cualquier clase),
- La clase `vector` contiene una gran cantidad de métodos, mediante los cuales se accede a información de sus elementos o se manipula a los mismos. Por ejemplo, el método `size` devuelve el número de elementos contenidos en un objeto `vector` y el método `clear` elimina todos los elementos contenidos.
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

Sabiendo que está situada dentro de la biblioteca estándar, podremos construir objetos de esta clase. Por ejemplo, la siguiente línea construye un vector de números en doble precisión, utilizando el constructor más sencillo (el nuevo vector no recibe ningún parámetro).

~~~
std::vector<double> u;
~~~
{: .cpp}

Todos los elementos de un vector tienen que ser del mismo tipo. En el caso anterior, los elementos almacenados son de tipo es `double`. Se puede utilizar cualquier otro tipo (`int`, `float`, `char`, etc.) o incluso cualquier clase que haya sido declarada previamente (por ejemplo, se podría construir un vector de vectores, como especificamos más adelante).

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
v[2] = u.back();  // El 3er elemento de v será igual al último de u
~~~
{: .cpp}

**Comentario**: Los datos almacenados por la clase `vector` están localizados en posiciones consecutivas de memoria y así el acceso a los mismos (mediante el operador `[]`) es tan eficiente como en arrays de C. Lo mismo ocurre con funciones como `size`. Si embargo, las funciones en las que cambia el tamaño del vector, como `resize`, son muy poco eficientes pues, posiblemente, los datos almacenados por el vector deberán ser realojados en memoria (para mantener su alojamiento consecutivo).


A continuación, proponemos un ejercicio en el que se implementan los conceptos anteriores

> ## Ejercicio 1: Primer programa con la clase `std::vector`
>
> Como ejercicio, se propone compilar y ejecutar el siguiente programa, comprobando que
> el resultado coincide con el esperado
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
>   if (n>0) std::cout << v[0]; // Imprimir el primer elemento
>   for (int i=1; i<n; i++) std::cout << ',' << v[i]; // Imprimir los restantes
>   std::cout  << "]" << std::endl;
> }
>
> int main()
> {
>   const int n=4; // Dimensión del vector (número de elementos almacenados)
>   std::vector<double> u;
>   std::vector<double> v(n);  // Vector formado por n números (doble precisión)
>   for (int i=0; i<n; i++) v[i]= pow(2,i); // Cargamos los elementos: 1, 2, 4, 8
>   std::cout << "Vector v:" << std::endl;
>   print_vector_double(v); // Imprimir el resultado
>
>   u = v;
>   std::cout << "Vector u:" << std::endl;
>   print_vector_double(u); // Imprimir el resultado
>
>   v.resize(n+1); // v tendrá tamaño 5
>   v[4] = u.back(); // Modificar el 5º elemento
>   std::cout << "Vector v:" << std::endl;
>   print_vector_double(v); // Imprimir el resultado
> }
> ~~~
> {: .cpp}
>
> > ## Resultado esperado
> >
> > ~~~
> > Vector v:
> > [1,2,4,8]
> > Vector u:
> > [1,2,4,8]
> > Vector v:
> > [1,2,4,8,8]
> > ~~~
> {: .solution}
{: .challenge}


> ## Otros tipos de constructores
>
> Además de las vistas anteriormente, existen otras dos variantes para construir objetos de la clase `std::vector` que pueden resultar muy útiles. En el primero (constructor de copia), un vector se crea a partir de otro existente (del que se copian los elementos),
>
> ~~~
> std::vector<int> u = v; // Donde v es un vector de enteros, previamente definido
> ~~~
> {: .cpp}
>
> En el segundo, el vector se construye a partir de una lista de elementos dada explícitamente:
>
> ~~~
> std::vector<char> u = {'H','o','l','a'};
> ~~~
> {: .cpp}
>
> Atención: el constructor anterior solamente es válido para la versión `C++11` o superior. Si compilamos un programa con el ejemplo anterior con `g++`, debemos usar la opción `-std=c++11` (o `c++14` o superior):
>
> ~~~
> g++ -std=c++11 mi_programa.cpp
> ~~~
> {: .bash}
>
>
> En otro caso, obtendremos un error similar al siguiente:
>
> ~~~
> error: in C++98 ‘u’ must be initialized by constructor, not by ‘{...}’
> ~~~
> {: .output}
>
>
{: .callout}

En el siguiente ejercicio, se usa la clase `std::vector` para comprobar que la fórmula de cuadratura de Gauss de tres puntos tiene orden 5. En concreto, para $n=0,1,...,6$, se aproximan las integrales
$$
\int_{-1}^1 x^n \; dx
$$
mediante la fórmula de cuadratura:
$$
I(f) = \sum_{i=0}^2 w_i f(x_i),
$$
donde $\{ x_0, x_1, x_2 \} =  \{-\sqrt{3/5}, 0, \sqrt{3/5} \}$ y $\{ w_0, w_1, w_2 \} = \{5./9, 8./9, 5./9\}  $

> ## Ejercicio 2: Fórmula de cuadratura de Gauss de tres puntos en [-1,1]
>
> ~~~
> #include <iostream>
> #include <vector>
> #include <cmath> // Usaremos la función 'pow' de la bibilioteca matemática de C
>
> int main()
> {
>   // Datos para la fórmula de cuadratura de Gauss de tres puntos en [-1,1]
>   std::vector<double> x = { -sqrt(3.0/5), 0.0, sqrt(3.0/5) };  // Nodos
>   std::vector<double> w = { 5./9, 8./9, 5./9 };  // Pesos
>
>   // Valores exactos de la integral en [-1,1] de x^n, n=0,1,...
>   std::vector<double> valor_exacto = { 2, 0, 2./3, 0, 2./5, 0, 2./7 };
>
>   for(unsigned int n=0; n<valor_exacto.size(); n++) {
>     // Aplicamos la fórmula de cuadratura a la función f(x)=x^n
>     double quad=0;
>     for(int i=0; i<3; i++) { // sumatorio en i de (w_i * x_i^n)
>       quad += w[i]*std::pow(x[i], n);
>     }
>     // Vemos el resultado
>     std::cout << "Aproximación de la integral en [-1,1] de x^" << n << ": " << quad;
>     std::cout << " (error: " << std::abs(valor_exacto[n]-quad) << ")" << std::endl;
>   }
> }
> ~~~
> {: .cpp}
{: .challenge}


[B. Stroustrup (4th edition)]: http://www.stroustrup.com/4th.html
