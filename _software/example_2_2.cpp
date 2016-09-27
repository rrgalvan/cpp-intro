//
// Ejemplo 2.2
//
// Fórmula de cuadratura de Gauss de tres puntos en [-1,1]
//
#include <iostream>
#include <vector>
#include <cmath> // Usaremos la función 'pow' de la bibilioteca matemática de C

int main()
{
  // Datos para la fórmula de cuadratura de Gauss de tres puntos en [-1,1]
  std::vector<double> x = { -sqrt(3.0/5), 0.0, sqrt(3.0/5) };  // Nodos
  std::vector<double> w = { 5./9, 8./9, 5./9 };  // Pesos

  // Valores exactos de la integral en [-1,1] de x^n, n=0,1,...
  std::vector<double> valor_exacto = { 2, 0, 2./3, 0, 2./5, 0, 2./7 };

  for(unsigned int n=0; n<valor_exacto.size(); n++) {
    // Aplicamos la fórmula de cuadratura a la función f(x)=x^n
    double quad=0;
    for(int i=0; i<3; i++) { // sumatorio en i de (w_i * x_i^n)
      quad += w[i]*std::pow(x[i], n);
    }
    // Vemos el resultado
    std::cout << "Aproximación de la integral en [-1,1] de x^" << n << ": " << quad;
    std::cout << " (error: " << std::abs(valor_exacto[n]-quad) << ")" << std::endl;
  }
}
