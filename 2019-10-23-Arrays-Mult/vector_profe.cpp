// compile as : g++ -Wall -g -fsanitize=address name.cpp

#include <iostream>
#include <vector>
#include <cmath>

const int M = 10000, N = 300;

void test_transposition(const std::vector<int> & M, const std::vector<int> & MT, int m, int n);

int main(void)
{
  // declarar las matrices
  std::vector<int> A(M*N), AT(N*M);
  int ii, jj;
  
  for(ii=0; ii < M; ++ii){
    for(jj=0; jj < N; ++jj){
      A[ii*N+jj] = ii*N + jj;  
    }
  }

  // procesarla : transponerla
  for(ii=0; ii < M; ++ii){
    for(jj=0; jj < N; ++jj){
      AT[jj*M +ii] = A[ii*N + jj];
    }
  }
  

  test_transposition(A, AT, M, N);  

  return 0;
}

void test_transposition(const std::vector<int> & M, const std::vector<int> & MT, int m, int n)
{
  int sum = 0;
  for(int ii=0; ii < m; ++ii){
    for(int jj=0; jj < n; ++jj){
      sum += std::fabs(M[ii*n + jj] - MT[jj*m + ii]); 
    }
  }
  double avg = 1.0*sum/(m*n);
  std::cout << "# diff = " << avg << "\n";
}
