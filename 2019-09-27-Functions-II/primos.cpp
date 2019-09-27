#include <iostream>
#include <cmath>

int primo(int a);
int num_primos(int m);
void print_primos(int m, int n);

int main(void)
{
  print_primos(1,100);
  return 0;
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

int num_primos(int m)
{
	int sum = 0;
	for(int ii = 1; ii <=m; ++ii)
	{
		if (primo(ii) == 1)
		{
			sum += 1;
		}		
	}
	return sum;
}

void print_primos(int m, int n)
{
  int sum = -1;
  for (int ii = m; ii <= n; ii++)
  {
		std::cout << ii << "  " << num_primos(ii) << "  " << ii/(log(ii)-1.08366) << std::endl;
  }     
}
