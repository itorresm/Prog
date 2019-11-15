#include <iostream>
#include <string>
#include <vector>
#include <fstream>

struct Estudiante
{
  std::string name, id;
  std::vector<double> notas;
};

const int N_EST = 2;
const  int N_NOTAS = 4;

void setup_notas(Estudiante & e, int NNOTAS);
void print_course(std::vector<Estudiante> & curso, std::string fname);
void read_course(std::vector<Estudiante> & curso, std::string fname);

int main (void)
{
  std::vector<Estudiante> curso1(N_EST);
  
  for (auto & est : curso1)
    {
      setup_notas(est, N_NOTAS); 
    }
  curso1[0].name = "Est1";
  curso1[0].id = "ID1";
  curso1[0].notas = {4.5, 4.8, 4.1, 2.5};

  curso1[1].name = "Est2";
  curso1[1].id = "ID2";
  curso1[1].notas = {2.5, 2.8, 2.1, 4.5};
  
  print_course(curso1, "curso.txt");

  std::vector<Estudiante> curso2;
  read_course(curso2, "curso.txt");
  
  return 0;
}

void setup_notas(Estudiante & e, int NNOTAS)
{
  e.notas.resize(NNOTAS);
}

void print_course(std::vector<Estudiante> & curso, std::string fname)
{
  std::ofstream fout(fname);
  fout << curso.size() << "\n";
  fout << curso[0].notas.size() << "\n";
  for(const auto & est : curso)
    {
      fout << est.name << "\n"
	   << est.id << "\n";
      for(const auto & grade : est.notas)
	{
	  fout << grade << " ";
	}
      fout << "\n";
    }
  fout.close();
}

void read_course(std::vector<Estudiante> & curso, std::string fname)
{
  std::ifstream fin(fname);
  int nest = 0, nnotas = 0;
  fin >> nest;
  fin >> nnotas;
  curso.resize(nest);
  for(auto & est : curso)
    {
      setup_notas(est, nnotas);
    }
  for(auto & est : curso)
    {
      //std::getline(fin, est.name);
      //std::getline(fin, est.id);
      fin >> est.name;
      fin >> est.id;
      for(int ii = 0; ii < nnotas ; ++ii)
	{
	  fin >> est.notas[ii];
	}
    }
  print_course(curso, "curso_test.txt");

  fin.close();
}
