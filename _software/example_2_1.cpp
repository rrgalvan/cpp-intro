#include <iostream>
#include <vector>
#include <cmath> // Usaremos la función 'pow' de la bibilioteca matemática de C

void print_vector_double(std::vector<double> v) {
  // Imprimimos el tamaño del vector y su contenido
  int n = v.size();
  std::cout << "[";
  if (n>0) std::cout << v[0]; // Imprimer el primer elemento
  for (int i=1; i<n; i++) std::cout << ',' << v[i]; // Imprimir los restantes
  std::cout  << "]" << std::endl;
}

int main()
{
  const int n=4; // Dimensión del vector (número de elementos almacenados)
  std::vector<double> v(n);  // Vector formado por n números (doble precisión)
  for (int i=0; i<n; i++) v[i]= pow(2,i); // Cargamos los elementos: 1, 2, 4, 8
  print_vector_double(v); // Imprimir el resultado
}
