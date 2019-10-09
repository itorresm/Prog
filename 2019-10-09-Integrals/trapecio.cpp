#include <iostream>
#include <cmath>

using fptr = double (double);
double fun(double x);
double trapecio(double h, double x0, double xf, fptr fun);
int main(void)
{
  std::cout.precision(16); std::cout.setf(std::ios::scientific);
  double h = 0.01;
  std::cout << trapecio(h, 0.0, 2*M_PI, fun) << std::endl;
  return 0;
}

double fun(double x)
{
  return std::sin(x);
}

double trapecio(double h, double x0, double xf, fptr fun)
{
  double sum = 0.0;
  double x =0.0;
  int N = (xf-x0)/h;
  for (int ii = 1; ii <= N-1; ++ii)
    {
      x = x0 + ii*h;
      sum += 2* fun(x);
    }
  sum += fun(x0) + fun(xf);
  return h/2 *sum;
}
    
