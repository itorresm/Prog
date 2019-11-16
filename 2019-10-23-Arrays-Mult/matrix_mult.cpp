#include <iostream>
#include <vector>

const int M = 2, N = 3;
void matrix_mult (const std::vector<int> & A, const std::vector<int> & B,
		  std::vector<int> & C, int m, int n);
void print (const std::vector<int> & C, int m, int n);


int main(void)
{
  std::vector<int> A(M*N), B(N*M), C(M*M);
  A = {1, 2, 3, 4, 5, 6};
  B = {5, -1, 1, 0, -2, 3};
  // for (int ii = 0; ii < M; ++ii)
  //    {
  //      for (int jj = 0; jj < N; ++jj)
  // 	{
  // 	  A[ii*N + jj] = ii*N + jj;
  // 	}
  //   }
  // for (int jj = 0; jj < N; ++jj)
  //   {
  //     for (int ii = 0; ii < M; ++ii)
  // 	{
  // 	  B[jj*M + ii] = jj*M + ii;
  // 	}
  // }
  matrix_mult(A, B, C, M, N);
  std::cout << "A: " << std::endl;
  print(A, M, N);
  std::cout << "B: " << std::endl;
  print(B, N, M);
  std::cout << "A*B: " << std::endl;
  print(C, M, M);
  return 0;
}

void print (const std::vector<int> & C, int m, int n)
{
   for (int ii = 0; ii < m; ++ii)
    {
      for (int jj = 0; jj < n; ++jj)
	{
	  std::cout << C[ii*n + jj] << "  ";
	}
      std::cout << "\n";
    }
}

void matrix_mult(const std::vector<int> & A, const std::vector<int> & B,
		 std::vector<int> & C, int m, int n)
{
  double sum = 0;
  for (int kk = 0; kk < m ; ++kk)
    {
      for (int ii = 0; ii < m; ++ii)
	{
	  for (int jj = 0; jj < n; ++jj)
	    {
	      sum += A[kk*n + jj]*B[jj*m + ii];
	    }
	  C[kk*m + ii] = sum;
	  sum = 0;
	}
    }
}
