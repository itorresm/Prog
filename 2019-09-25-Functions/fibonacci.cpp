#include <iostream>

int fibonacci_loop (int N);
int fibonacci_recursive (int N);

int main(void)
{
  int N = 5;
  std::cout << fibonacci_loop(N) << std::endl;
  std::cout << fibonacci_recursive(N) << std::endl;
  
  return 0;
}
int fibonacci_loop (int N)
{
  int suma = 0;
  if (N == 0 || N == 1) return 1;
  int aold1 = 0, aold2 = 1  
}
