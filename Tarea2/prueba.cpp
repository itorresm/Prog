#include <iostream>
#include <cmath>

using fptr = double(double);
double fun(double x);
double bisection(double xl, double xu, double eps, fptr f);
double regulafalsi(double xl, double xu, double eps, fptr f);
double newton_raphson(double x0, double eps, fptr f, fptr fdev);
double fdev(double x);

int main(void)
{
  std::cout.precision(16), std::cout.setf(std::ios::scientific);
  return 0;
}

double fun(double x)
{
  return (3*std::pow(M_E, -x))-x;
}

double fdev(double x)
{
  return (-3*std::pow(M_E, -x))-1;
}
  
double bisection(double xl, double xu, double eps, fptr f)
{
  double xr = xl;
  int N = 0;
  while(1)
    {
      xr = (xl+xu)/2;
      N++;
      if (f(xr) <= eps)
	{
	  break;
	}
      else if (f(xl)*f(xr) < 0) 
	{
	  xu = xr;
	}
      else
	{
	  xl = xr;
	}
    }
  std::cout << "#bisection iter = " << N << std::endl;
  return xr;
}

double regulafalsi(double xl, double xu, double eps, fptr f)
{
  double xr = xl;
  int N = 0;
  while(1)
    {
      xr = xu - (f(xu)*(xl-xu))/(f(xl)-f(xu));
      N++;
      if (f(xr) <= eps)
	{
	  break;
	}
      else if (f(xl)*f(xr) < 0) 
	{
	  xu = xr;
	}
      else
	{
	  xl = xr;
	}
    }
  std::cout << "#regula-falsi iter = "<< N << std::endl;
  return xr;
}

double newton_raphson(double x0, double eps, fptr f, fptr fdev)
{
  double xr = x0;
  int N = 0;
  while(1)
    {
      N++;
      if (f(xr) <= eps)
	{
	  break;
	}
      else
	{
	  xr = xr - (f(xr))/(fdev(xr));
	}
    }
  std::cout << "#Newton_Raphson iter = " << N << std::endl;
  return xr;
}
