#include <iostream>
#include <cmath>

int main(void)
{
  int N = 10;
  double mean = 0.0;
  double sum1 = 0.0;
  double sum2 = 0.0;
  double dev = 0.0;

  
  double data[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  for (int ii = 0; ii < N; ++ii)
    {
      sum1 += data[ii];
    }
  mean = sum1/10.0;
  for (int ii = 0; ii< N; ++ii)
    {
      sum2 += std::pow((data[ii] - mean), 2);
    }
  dev = std::sqrt(sum2) / std::sqrt(N);
      

  std::cout << "The mean is: " << mean << std::endl;
  std::cout << "The standard deviation is: " << dev << std::endl;
  return 0;
}
