#include "algorithms.hpp"
#include <iostream>

int main()
{
  std::cout << "hello world" << std::endl;
  std::cin.get();

  int arr[] = {12, 11, 13, 5, 6, 7};
  int size = sizeof(arr) / sizeof(arr[0]);

  
  srt::mergeSort(arr, 0, size - 1);


  for(int i = 0; i < size; i++) {
      std::cout << arr[i] << " ";
  }

  std::cout << "\ndone!" << std::endl;
  
  return 0;
}
