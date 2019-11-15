#include <iostream>
#include <vector>


int main(void)
{
  int N = 1;
  int r_num;
  std::cout << "How many numbers?" << std::endl;
  std::cin >> N;
  std::vector<int> num;
  std::cout << "Numbers are?" << std::endl;
   for(int jj = 0; jj < N; ++jj)
     {
       std::cin >> r_num;
       bool flag = true;
       for (const auto & x : num)
	 {	   
	   if(x == r_num)
	     {
	       flag = false;
	       break;
	     }
	 }
       if (true == flag)
	 {
	   num.push_back(r_num);
	 }
       
     }
  std::cout << "Values are: " << std::endl;	       
  for(const auto & x : num)
    {
      std::cout << x << " ";
    }
  std::cout << std::endl;
  return 0;
}


