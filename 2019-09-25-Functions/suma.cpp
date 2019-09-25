#include <iostream>
int suma(int m, int n);

int main(void)
{
  std::cout << suma(200000,300000) << "\n";
  return 0;
}

int suma(int m, int n)
{
  int ii = 0;
  int result = 0;
  for(ii = m; ii <= n ; ++ii)
    {
      if( ii%3==0 || ii%5==0 || ii%7==0)
	{
	  result += ii;
	}
    }
    
  return result;
}
