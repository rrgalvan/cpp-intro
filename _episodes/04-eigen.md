---
title: "Eigen: a linear algebra library"
teaching: 20
exercises: 0
questions:
- "¿Cómo usar la biblioteca Eigen para trabajar con matrices en C++?"
objectives:
- "Compilar programas usando la biblioteca matricial Eigen."
- "Utilizar objetos matemáticos: vectores, matrices"
- "Resolver sistemas de ecuaciones lineales"
keypoints:
- Uno
- Dos
---

Aunque C++ no incluye, por defecto, objetos matemáticos como vectores y matrices (pues, como vimos, la clase `std::vector` no posee operaciones matemáticas adecuadas), existen numerosas biblitecas matriciales en C++ que son muy adecuadas. Hemos optado aquí por una de ellas ([Eigen]) por considerarla de uso sencillo y apropiada para un uso general.

[Eigen] es una biblioteca de matrices para C++, incluyendo matrices huecas (con pocos ceros y, por tanto, menores requerimientos de memoria). Es genérica y rápida, gracias al uso de clases patrón, y fácil de usar para programadores habituados a usar C++. Incluye funcionalidades adicionales como factorización de matrices, métodos directos e iterativos para la resolución de sistemas lineales, transofmada rápida de fourier, etc.

## Primer contacto con Eigen

El siguiente programa es una variante de la sección "[empezando con Eigen](http://eigen.tuxfamily.org/)" de la biblioteca.
Para compilarlo, deberemos indicar la ruta de directorios hasta los ficheros de cabecera (ficheros de *include* o `.h`) de *Eigen*, ya que habitualmente estos ficheros no estarán dentro de rutas estándar. Para ello, basta utilizar una opción de compiación del tipo `-I /ruta/del/directorio/de/eigen`. Por ejemplo, si el programa se llama `ejemplo_3_1.cpp`, la orden adecuada (para Ubuntu GNU/Linux y Eigen3, i.e. versión 3) es:

~~~
g++ -I /usr/include/eigen3 ejemplo_3_1.cpp -o ejemplo_3_1
~~~
{: .bash}

A continuación se presenta el primer ejemplo:

> ## Ejemplo 1
>
> ~~~
> #include <iostream>
> #include <Eigen/Dense>
> int main()
> {
>   Eigen::MatrixXd m(2,2);
>   m(0,0) = 3;
>   m(0,1) = -1;
>   m(1,0) = 2.5;
>   m(1,1) = m(1,0) + m(0,1);
>   std::cout << m << std::endl;
> }
> ~~~
> {: .cpp}
>
> > ## Resultado
> >
> > ~~~
> > 3  -1
> > 2.5 1.5
> > ~~~
> {: .solution}
{: .callout}

Algunos comentarios sobre el ejemplo anterior:

1. Eigen define muchos tipos de datos y funciones, todos ellos dentro del espaio de nombres `Eigen`. Para aplicaciones sencillas, como la anterior, se puede utilizar la clase `MatrixXd`, que representa a matrices de tamaño arbitrario (de ahí la `X`) y con elementos en doble precisión (de ahí la `d` final). Si queremos coma flotante en simple precisión, podemos usar la clase `MatrixXf`.
3. En el programa se construye u objeto de *Eigen* de tipo `MatrixXd` que contendrá *2* filas y *2* columnas. Para acceder a los elementos se usa paréntesis `( , )`, a diferencia de los arrays C/C++. Pero las filas y columnas se indexan a partir de cero (como en C/C++).
2. El fichero de cabecera `Eigen/Dense` define a otros tipos de matrices (todos ellas llenas, en inglés *dense*), como veremos más adelante. Existen otros ficheros de cabecera que ofrencen distintos tipos de matrices y de funcionalidades, véase la [documentación en internet](http://eigen.tuxfamily.org/dox/group__QuickRefPage.html).

> ## Ejemplo 2
>
> ~~~
> #include <iostream>
> #include <Eigen/Dense>
> using namespace Eigen;
> using namespace std;
> int main()
> {
>   MatrixXd A = MatrixXd::Random(3,3);
>   A = (A + MatrixXd::Constant(3,3,1.2)) * 50;
>   cout << "A =" << endl << A << endl;
>   VectorXd v(3);
>   v << 1, 2, 3;
>   cout << "A * v =" << endl << A * v << endl;
> }
> ~~~
> {: .cpp}
{: .callout}

En este momento, el ejemplo anterior debe estar claro, salvo algunos puntos novedosos. Construímos la matriz `A` como una matriz cuadrada de orden *3*, con elementos aleatorios (entre *-1* y *1*). Le sumamos una matriz de orden *3*, todos cuyos cuyos elementos son iguales a *1.2*, y la multiplicamos por *50*. Construimos un vector (columna) de números en doble precisión, definimos su tamaño como *3*. Lo rellenamos con los elementos *1, 2, 3*, obsérvese cómo los objetos de *Eigen* pueden usar el operador `<<` (también las matrices). Multiplicamos la matriz por el vector e imprimimos el resultado.


## Matrices y vectores de tamaño fijo

Además de las de tamaño arbitrario estudiadas anteriormente, existe un segundo tipo de matrices densas: matrices (y vectores) de tamaño fijo. En ellas, la dimensión del objeto viene fijado en su diseño y no puede modificarse. Son, por tanto, menos flexibles que los objetos de tipo `MatrixXd`.

A continuación, se usan matrices y vectores de tamaño fijo para repetir el ejemplo anteior:

> ## Ejemplo 3
>
> ~~~
> #include <iostream>
> #include <Eigen/Dense>
> using namespace Eigen;
> using namespace std;
> int main()
> {
>   Matrix3d A = Matrix3d::Random();
>   A = (A + Matrix3d::Constant(1.2)) * 50;
>   cout << "A =" << endl << A << endl;
>   Vector3d v(1,2,3);
>   cout << "A * v =" << endl << A * v << endl;
>   cout << " (A * v)^T =" << endl << (A * v).transpose() << endl;
> }
> ~~~
> {: .cpp}
{: .callout}

En este caso, se usan los tipos `Matrix3d` y `Vector3d` para representar matrices y vectores en doble precisión y de tamaño *3*. Se pueden usar los tamaños `1`, `2`, `3` y `4` y varios tipos (`d`: double, `f`: float, `i`: int,...)

El usar tamaño fijo permite simplificar algo los métodos como `Random()` y `Constant()`.
Si embargo, las matrices y vectores de tamaño fijo tienen algunas **ventajas** de mayor calado:

- En primer lugar, el conocer su tamaño a la hora de la compilación permite algunas optimizaciones y, gracias a ellas, generar código más eficiente (más rápido).
- Por otro lado, al compilador le resulta más fácil detectar errores en el momento de la compilación. Por ejemplo, multiplicar objeto de tipo `Matrix3d` por un vector de tipo `Vector2d` producirá un error de compilación. Si usamos matrices de tamaño variable, el error no aparecerá hasta la ejecución del programa y será más difícil de detectar.

Sin embargo, no siempre el tamaño de la matriz es conocido en tiempo de compilación. Y además, el abusar de las matrices de tamaño fijo incrementa el tiempo de compilación y el tamaño del código ejecutable. Por ello, en la documentación de Eigen se aconseja la siguiente regla:

> ## Regla de oro
>
> Usar matrices y vectores de tamaño fijo cuando su tamaño sea *menor o igual a `4`*.
>
{: .callout}

## Para saber más

- En realidad, las matrices de tamaño fijo y variable no son más que tipos de datos definidos a partir de la clase patrón `Matrix`.

  `Matrix` es, por tanto, una de las clases centrales de la biblioteca
  Eigen. Para más detalles, véase el
  [tutorial de Eigen](http://eigen.tuxfamily.org/dox/group__TutorialMatrixClass.html)

- Muchas de los modelos matemáticos en el
  ámbito de las ciencias experimentales conducen a sistemas de
  ecuaciones de gran tamaño, cuyo manejo en el orenador es
  prohibitivo, desde el punto de vista de su almacenamiento en la
  memoria del ordenador. Sin embargo, muchas de estas matrices son
  huecas, es decir, una gran mayoría de sus elementos son ceros. Por
  tanto, basta con almacenar en memoria los elementos distintos de
  cero.

  Eigen contiene una clase patrón llamada `SparseMatrix` que
  implementa eficientemente matrices huecas. Para saber más véase la
  [documentación oficial](http://eigen.tuxfamily.org/dox/) del código
  de Eigen.

[eigen]: http://eigen.tuxfamily.org
