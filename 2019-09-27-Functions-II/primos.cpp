#include <iostream>

int primo(int a);
void print_primos(int m, int n);
int print (int i, int j);

int main(void)
{
  print_primos(1,100);
  return 0;
}


int print (int i, int j)
{
  for (int ii = i; ii <= j; ii++)
    {
      std::cout << ii << std::endl;
    }
  
}


int primo(int a)
{
  int result = 0;
  if (a == 2)
    {
      return 1;
    }
  for(int ii = 2; ii < a; ++ii)
    {
      if (a%ii == 0)
	{
	  result = 0;
	  break;
	}
      else
	result = 1;
    }
  return result;
}

void print_primos(int m, int n)
{
  int sum = -1;
  for (int ii = m; ii <= n; ii++)
    {
      std::cout << ii << std::endl;
      if (primo(ii) == 1)
	{
	  sum += 1;
	  std::cout << "   " << ii << "   " << sum  << std::endl;
	}
      
    }
}


