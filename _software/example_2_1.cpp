//
// Ejemplo 2.1
//
#include <iostream>
#include <vector>
#include <cmath> // Usaremos la función 'pow' de la bibilioteca matemática de C

void print_vector_double(std::vector<double> v) {
  // Imprimimos el tamaño del vector y su contenido
  int n = v.size();
  std::cout << "[";
  if (n>0) std::cout << v[0]; // Imprimir el primer elemento
  for (int i=1; i<n; i++) std::cout << ',' << v[i]; // Imprimir los restantes
  std::cout  << "]" << std::endl;
}

int main()
{
  const int n=4; // Dimensión del vector (número de elementos almacenados)
  std::vector<double> u;
  std::vector<double> v(n);  // Vector formado por n números (doble precisión)
  for (int i=0; i<n; i++) v[i]= pow(2,i); // Cargamos los elementos: 1, 2, 4, 8
  std::cout << "Vector v:" << std::endl;
  print_vector_double(v); // Imprimir el resultado

  u = v;
  std::cout << "Vector u:" << std::endl;
  print_vector_double(u); // Imprimir el resultado

  v.resize(n+1); // v tendrá tamaño 5
  v[4] = u.back(); // Modificar el 5º elemento
  std::cout << "Vector v:" << std::endl;
  print_vector_double(v); // Imprimir el resultado
}
