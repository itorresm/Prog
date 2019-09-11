#include <iostream>
int main(void)
{
  int val1 = 0;
  int val2 = 0;
  std::cout << "Escriba un entero: " << std::endl;
  std::cin >> val1;
  std::cout << "Escriba otro entero: " << std::endl;
  std::cin >> val2;
  std::cout << "la suma es:\n" << val1+val2 << std::endl;
  std::cout << "el producto es:\n" << val1*val2 << std::endl;
  if (val1 > val2)
    {
      std::cout << "El mayor es: " << val1 << std::endl;
    }
  else
    {
      std::cout << "El menor es:\n " << val1 << std::endl;
    }
  return 0;
}
