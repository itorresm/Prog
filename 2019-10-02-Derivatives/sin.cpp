#include <cstdio>
#include <cmath>

double fun(double x);
double dev_forward(double x, double h);
double dev_central(double x, double h);
double dev_forward_richardson(double x, double h);

int main(void)
{
  double x = M_PI/2.0;
  double h = 0.1;
  for (x = 0.0; x <= M_PI/2.0; x += 0.1)
  {
  std::printf("%25.16e %25.16e %25.16e %25.16e %25.16e %25.16e\n", x, h,
	      std::cos(x), dev_forward(x, h), dev_central(x,h),
	      dev_forward_richardson(x,h));
  }
  return 0;
}



double fun(double x)
{
  return std::sin(x);
}

double dev_forward(double x, double h)
{
  return (fun(x+h)-fun(x))/h;
}

double dev_central(double x, double h)
{
  return (fun(x+h)-fun(x-h))/2*h;
}

double dev_forward_richardson(double x, double h)
    {
      return 4.0/3* dev_central(x,h)-1.0/3* dev_forward(x,h);
    }


//gnuplot commands: plot "datos.txt" u 1:3
//u using, fila 1: fila 3
   
