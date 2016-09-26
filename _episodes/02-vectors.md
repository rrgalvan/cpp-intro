---
title: "Using C++ Objects: Vectors"
teaching: 30
exercises: 10
questions:
- "How can I create a vector of real numbers in C++?"
objectives:
- "Introduce C++ classes and objects"
- "Create and manipulate vector objects from the standard library"
- "Be aware of the strengths and limitations of these vector objects"
keypoints:
- Las clases en C++ son abstracciones que encapsulan datos junto a métodos (funciones) que operan sobre ellos.
- Los objetos son variables que se crean como representación concreta de una clase.
- La clase `vector` de la biblioteca estándar generaliza a los *arrays* 1d de C
- La clase `vector` se usa de forma similar a los *arrays* de C pero contiene métodos que le dan una mayor potencia.
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
> void print_vector_double(std::vector<double> v)
> {
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
>
{: .challenge}

> ## Extensión: Uso de patrones
>
> En el programa incluído en el Ejercicio 1, se definió la función `print_vector_double`, que actúa exclusivamente sobre objetos de tipo `std::vector<double>`. Esto significa que, para imprimir otro tipo de vectores (por ejemplo, vectores de números enteros, `std::vector<int>`) será necesario definir un nueva función.
>
> En lugar de ello, podemos utilizar patrones (*templates*, en inglés) para definir funciones genéricas. En el ejemplo anterior, bastaría sustituir la definición de la función`print_vector_double` por la siguientes expresión:
>
> ~~~
> template <class T> void print_vector<T>(std::vector<T> v)
> ~~~
>
> La expresión `T` actúa como un patrón o un tipo genérico, que puede abarcar cualquier tipo concreto (como `int`, `float`, `double`, etc.).
>
> Podemos utilizar ahora la función explicitando su tipo (`print_vector<int>`, `print_vector<float>`, `print_vector<double>`, etc).
>
> Por ejemplo, en el cuerpo de la función `main` del ejemplo anterior, sustituiríamos las líneas `print_vector_double(v)` por `print_vector<double>(v)`
>
> **Ejercicio**: se propone modificar el ejercicio 1 para utilizar una función patrón `print_vector<T>`.
>
> **Nota**: Esta misma técnica se puede extender para la definición de clases genéricas en C++. De hecho, `std::vector` que ha sido introducida anteriormente es una *clase patrón* y, como hemos vistos, puede almacenar tipos de datos genéricos y, a través de sus métodos, actuar sobre los mismos. Véase [[B. Stroustrup (4th edition)]], por ejemplo, para más detalles.
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
> *En otro caso*, obtendremos un error similar al siguiente:
>
> ~~~
> error: in C++98 ‘u’ must be initialized by constructor, not by ‘{...}’
> ~~~
> {: .output}
>
>
{: .callout}

En el siguiente ejercicio, se usa la clase `std::vector` para comprobar que la fórmula de cuadratura de Gauss de tres puntos en el intervalo *[-1,1]* tiene orden *5*. En concreto, para cada *n=0,1,...,6*, se aproxima la integral

$$
\int_{-1}^1 x^n \; dx
$$

mediante la fórmula de cuadratura:

$$
I(f) = \sum_{i=0}^2 w_i f(x_i),
$$

donde los nodos y los pesos (elegidos de forma óptima) vienen dados por:

$$\{ x_0, x_1, x_2 \} =  \{-\sqrt{3/5}, 0, \sqrt{3/5} \},$$

$$\{ w_0, w_1, w_2 \} = \{5/9, 8/9, 5/9\}.  $$

> ## Ejercicio 2: Fórmula de cuadratura de Gauss de tres puntos en [-1,1]
>
> ~~~
> #include <iostream>
> #include <vector>
> #include <cmath> // Usaremos la bibilioteca matemática de C
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
>
> > ## Resultado esperado
> >
> > ~~~
> > Aproximación de la integral en [-1,1] de x^0: 2 (error: 0)
> > Aproximación de la integral en [-1,1] de x^1: 0 (error: 0)
> > Aproximación de la integral en [-1,1] de x^2: 0.666667 (error: 1.11022e-16)
> > Aproximación de la integral en [-1,1] de x^3: 0 (error: 0)
> > Aproximación de la integral en [-1,1] de x^4: 0.4 (error: 5.55112e-17)
> > Aproximación de la integral en [-1,1] de x^5: 0 (error: 0)
> > Aproximación de la integral en [-1,1] de x^6: 0.24 (error: 0.0457143)
> > ~~~
> {: .solution}
>
{: .challenge}

## Puntos a favor y en contra de la clase `std::vector`

La clase `std::vector` posee grandes ventajas frente a los *arrays* de
C. Muchas de estas ventajes las cuales, como uso de iteradores o de
funciones de la biblioteca estándar, son comunes a otros tipos de
contenedores, como `std::list` o `std::set` y por brevedad no se han
comentado aquí, véase por ejemplo [B. Stroustrup (4th edition)].

Sin embargo, de cara su uso como objetos matemáticos o científicos, la
clase `std::vector` presenta series limitaciones. Por ejemplo, no
ofrecen (directamente) la posibilidad de realizar operaciones como suma de
vectores o producto de un vector por un escalar.

En la siguiente sección, estudiaremos la biblioteca Eigen que cubre
este tipo de necesidades.

[B. Stroustrup (4th edition)]: http://www.stroustrup.com/4th.html
