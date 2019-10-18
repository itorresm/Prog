#include <iostream>
#include <cmath>

void average(const double arr[], int N);


int main(void)
{
  const int N = 10;
  // double data[N] = {1,1,1,1,1,1,1,1,1,1};
  // double data[N] = {0};
  double data[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  average(data, N);
 
  return 0;
}

void average(const double arr[], int N)
{
 // average and std dev
  double sum = 0.0, sum2 = 0.0;

  for(int ii = 0; ii < N; ++ii){
     sum  += arr[ii];
     sum2 += arr[ii]*arr[ii];
  }

  double average = sum/N;
  double stddev = std::sqrt(sum2/N - (average*average));

  std::cout << "# Average : " << average << "\n";
  std::cout << "# stddev  : " << stddev  << "\n";
}

