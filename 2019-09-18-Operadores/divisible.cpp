#include <iostream>
int main(void)
{
  double a = 3;
  std::cout << "Write your integer:" << std::endl;
  std::cin >> a;
  if (a%3 == 0)
    {
      std::cout << "Number: " << a << " can be divided by 3\n";
    }
  else
    {
      std::cout << "Number: " << a << " cannot be divided by 3\n";
    }
  
  return 0;
}
