#include <iostream>
int main(void)
{
  std::cout << ( (5==5) && (3>6) ) << std::endl;
  int a = 0;
  int b = 5;
  a = (b=3, b+2);
  std::cout << a << std::endl;
  return 0;
}
