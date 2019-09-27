#include <iostream>

template <class T, class S>
T max(T a, S b)
{
  T result = 0;
  if (a >= b)
    {
      result = a;
    }
  else
    {
      result = b;
    }
  return result;
}

int main (void)
{
  std::cout << max(32,13) << std::endl;
  std::cout << max(3.2,1.3) << std::endl;
  std::cout << max(3.2,13) << std::endl;
  std::cout << max(32,1.3) << std::endl;
  return 0;
}



