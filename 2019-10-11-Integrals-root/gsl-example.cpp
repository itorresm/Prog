#include <fstream>
#include <gsl/gsl_sf_bessel.h>

int main (void)
{
  std::ofstream fout("datos.txt");
  fout.precision(15); fout.setf(std::ios::scientific);

  for (double x = 0; x <= 15.7; x += 0.1) {
    double y = gsl_sf_bessel_J0 (x);
    fout << x << "\t" << y << "\n";
  }

  fout.close();
  return 0;
}
