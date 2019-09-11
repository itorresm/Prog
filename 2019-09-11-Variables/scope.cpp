#include <iostream>


int main(void)
{
  
  double x = 7.4;
  {
    double x = 7.4;
    std::cout << x  << std:: endl;
  }
  std::cout << x  << std:: endl;
				  
  return 0;
  std::cout << "\a" <<std::endl;
}
