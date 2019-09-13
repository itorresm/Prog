#include <iostream>
#include <string>
//Saludo!
int main(void)
{
  std::string nombre = "name"; 
  std::cout << "Hey, what's your name? " << std::endl;
  std::cin >> nombre; 
  std::cout << "Hello there, " << nombre << "!" << std::endl; 
  return 0;
}
