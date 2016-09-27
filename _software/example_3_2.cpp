#include <iostream>
#include <Eigen/Dense>
using namespace Eigen;
using namespace std;
int main()
{
  MatrixXd A = MatrixXd::Random(3,3);
  A = (A + MatrixXd::Constant(3,3,1.2)) * 50;
  cout << "A =" << endl << A << endl;
  VectorXd v(3);
  v << 1, 2, 3;
  cout << "A * v =" << endl << A * v << endl;
  cout << " (A * v)^T =" << endl << (A * v).transpose() << endl;
}
