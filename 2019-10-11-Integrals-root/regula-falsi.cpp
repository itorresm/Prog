#include <iostream>
#include <cmath>

using fptr = double (double);

double fun(double x);
double bisection(double xl, double xu, double eps, fptr f);


int main(void)
{
  std::cout.precision(15); std::cout.setf(std::ios::scientific);
  const double EPS = 1.0e-6;
  double root = bisection(100, 200, EPS, fun);
  std::cout << root << "\n";
  return 0;
}

double bisection(double xl, double xu, double eps, fptr f)
{
  double xr = xl;
  do
    {
      xr = xu- ((f(xu)*(xl-xu))/(f(xl)-f(xu)));
      if(std::fabs(f(xr)) <= eps)
	{
	  break;
	}
      else if (f(xr)*f(xl) < 0)
	{
	  xu = xr;
	}
      else
	{
	  xl = xr;
	}
    }
  while(1);
  
  return xr;
}

double fun(double x)
{
  return x+10-x*std::cosh(50.0/x);
}
