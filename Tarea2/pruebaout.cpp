#include <fstream>
#include <cmath>

using fptr = double(double);
double fun(double x);
int bisection(double xl, double xu, double eps, fptr f);
int regulafalsi(double xl, double xu, double eps, fptr f);
int newton_raphson(double x0, double eps, fptr f, fptr fdev);
double fdev(double x);


int main(void)
{
  std::ofstream fout("prueba.txt");
  double xl = 0.0, xu = 2.0, x0 = 0.1;
  fout.precision(16), fout.setf(std::ios::scientific);
  fout << "#EPS-DELTA" << "              "
	    << "Nbisect" << "\t  "
	    << "NFalsePos" << "   "
	    << "NNewton" << "\t" << "\n";
  for (int n = 1; n <= 9; ++n)
    {
    double EPS  = std::pow(10, -n);
    fout << EPS << "\t"
	      << bisection(xl, xu, EPS, fun) << "\t  "
	      << regulafalsi(xl, xu, EPS, fun) << "\t      "
	      << newton_raphson(x0, EPS, fun, fdev) << "\n";
    }
  fout.close();
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
  
int bisection(double xl, double xu, double eps, fptr f)
{
  double xr = xl;
  int N = 0;
  while(1)
    {
      xr = (xl+xu)/2;
      if (std::fabs(f(xr)) <= eps)
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
      N++;
    }
  //std::cout << "#bisection iter = " << N << std::endl;
  return N;
}

int regulafalsi(double xl, double xu, double eps, fptr f)
{
  double xr = xl;
  int N = 0;
  while(1)
    {
      xr = xu - (f(xu)*(xl-xu))/(f(xl)-f(xu));
      if (std::fabs(f(xr)) <= eps)
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
      N++;
    }
  // std::cout << "#regula-falsi iter = "<< N << std::endl;
  return N;
}

int newton_raphson(double x0, double eps, fptr f, fptr fdev)
{
  double xr = x0;
  int N = 0;
  while(1)
    {
      if (f(xr) <= eps)
	{
	  break;
	}
      else
	{
	  xr = xr - (f(xr))/(fdev(xr));
	}
      N++;
    }
  //std::cout << "#Newton_Raphson iter = " << N << std::endl;
  return N;
}
