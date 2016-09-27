#include <iostream>
#include <Eigen/Dense>
using namespace Eigen;
using namespace std;
int main()
{
  Matrix3d A = Matrix3d::Random();
  A = (A + Matrix3d::Constant(1.2)) * 50;
  cout << "A =" << endl << A << endl;
  Vector3d v(1,2,3);
  cout << "A * v =" << endl << A * v << endl;
  cout << " (A * v)^T =" << endl << (A * v).transpose() << endl;
}
