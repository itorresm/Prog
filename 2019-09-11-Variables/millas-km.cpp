#include <iostream>
int main (void)
  
{
  double miles = 0.0;
  double km = 0.0;
  std::cout << "Distance in Miles: " << std::endl;
  std::cin >> miles;
  km = miles*1.609;
    std::cout << "Distance in Kilometers:\n " <<km << std::endl;
  return 0;
}
