#include <iostream>
#include <Eigen>

const M = 2, N = 3;
int main(void)
{
  Eigen::Matrix<int, M, N> A;
  Eigen::Matrix<int, N, M> B;
  Eigen::Matrix<int, M, M> C = A*B;
  A << 1, 2, 3,
    4, 5, 6;
  B << 5, -1, 1,
    0, -2, 3;
  std::cout << "A: " << std::endl;
  std::cout << A << std::endl;
  std::cout << "B: " << std::endl;
  std::cout << B << std::endl;
  std::cout << "A*B: " << std::endl;
  std::cout << C << std::endl;
  
  return 0;
}
