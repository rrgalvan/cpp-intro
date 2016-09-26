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

[Eigen] es una biblioteca de matrices para C++, incluyendo matrices huecas (con pocos ceros y, por tanto, menores requerimientos de memoria). Es genérica y rápida, gracias al uso de clases patrón, y fácil de usar para programadores habituados a usar C++. Incluye funcionalidades adicionales como resolución de sistemas lineales, transofmada rápida de fourier, etc.

## Primer programa con Eigen

El siguiente programa está extraído de la página web de la biblioteca ([empiezando con Eigen]([¡http://eigen.tuxfamily.org/dox/GettingStarted.html)):

~~~
#include <iostream>
#include <Eigen/Dense>
using Eigen::MatrixXd;
int main()
{
  MatrixXd m(2,2);
  m(0,0) = 3;
  m(1,0) = 2.5;
  m(0,1) = -1;
  m(1,1) = m(1,0) + m(0,1);
  std::cout << m << std::endl;
}
~~~
{: .cpp}

En este ejemplo se

[eigen]: http://eigen.tuxfamily.org
