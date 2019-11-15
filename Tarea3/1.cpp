#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>

const double W = M_PI;
const double TF = 3*2*M_PI/W;
const double X0 = 3.21;
const double V0 = 0.0;
const int DIM = 2;

void euler(std::vector<double> & data, double t, double h);
void rk4(std::vector<double> & data, double t, double h);
double f(int idx, double t, const std::vector<double> & y);
double x(double t);
void print_data(std::vector<double> & h, std::vector<double> & y); 


std::vector<double> y = {X0, V0};

int main(void)
{
  std::cout.setf(std::ios::scientific); std::cout.precision(16);
  std::vector<double> h(15);
  for( int ii = 0; ii < 15; ++ii)
    {
      h[ii] = std::pow(0.5, ii);
    }
  print_data(h, y);
  return 0;
}

double f(int idx, double t, const std::vector<double> & y)
{
  if( 0 == idx)
    {
      return y[1];
    }
  else if ( 1 == idx)
    {
      return -W*W*y[0];
    }
  else
    {
      std::cerr << "Index Error: " << idx << std::endl;
      return 0;
    }
      
}

void euler(std::vector<double> & data, double t, double h)
{
  const int N = TF/h;
  std::vector<double> datatmp = data;
  for(int nt = 0; nt < N; ++nt)
    {
      double T = h*nt;
      for(int ii = 0; ii < int(data.size()); ++ii)
	{
	  data[ii] = datatmp[ii] + h*f(ii, T, datatmp);
	}
    }
}

void rk4(std::vector<double> & data, double t, double h)
{
  std::vector<double> k1, k2, k3, k4, aux;
  k1.resize(data.size());
  k2.resize(data.size());
  k3.resize(data.size());
  k4.resize(data.size());
  aux.resize(data.size());
  
  // k1
  for(int ii = 0; ii < int(data.size()); ++ii)
    {
      k1[ii] = h*f(ii, t, data);
    }
  // k2 aux
  for(int ii = 0; ii < int(data.size()); ++ii)
    {
      aux[ii] = data[ii] + k1[ii]/2;
    }
  //k2
  for(int ii = 0; ii < int(data.size()); ++ii)
    {
      k2[ii] = h*f(ii, t + h/2, aux);
    }
  // k3 aux
  for(int ii = 0; ii < int(data.size()); ++ii)
    {
      aux[ii] = data[ii] + k2[ii]/2;
    }
  //k3
  for(int ii = 0; ii < int(data.size()); ++ii)
    {
      k3[ii] = h*f(ii, t + h/2, aux);
    }
  // k4 aux
  for(int ii = 0; ii < int(data.size()); ++ii)
    {
      aux[ii] = data[ii] + k3[ii];
    }
  //k4
  for(int ii = 0; ii < int(data.size()); ++ii)
    {
      k4[ii] = h*f(ii, t + h, aux);
    }
  
  // write new data
  for(int ii = 0; ii < int(data.size()); ++ii)
    {
      data[ii] = data[ii] + (k1[ii] + 2*k2[ii] + 2*k3[ii] + k4[ii])/6.0;
    }
}

double x(double t)
{
  return (X0)*std::cos(M_PI*t);
}

void print_data(std::vector<double> & h, std::vector<double> & y)
{
  std::ofstream fout("1.txt");
  fout.setf(std::ios::scientific); fout.precision(16);
  for(int ii = 0; ii < 15; ++ii)
    {
      fout << h[ii] << " "; 
      euler(y, TF, h[ii]);
      fout << std::fabs(y[0]-x(TF)) << " ";
      rk4(y, TF, h[ii]);
      fout << std::fabs(y[0]-x(TF));
      fout << "\n";
    }
  fout.close();
}
