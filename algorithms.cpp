#include "algorithms.hpp"
#include <iostream>

int main()
{
  std::cout << "merge sort" << std::endl;

  int arr[] = {12, 11, 13, 5, 6, 7};
  int size = sizeof(arr) / sizeof(arr[0]);

  std::cout << "before sort" << std::endl;

  for(int i = 0; i < size; i++) 
      std::cout << arr[i] << " ";

  algo::mergeSort(arr, 0, size - 1);

  std::cout << "\nafter sort" << std::endl;

  for(int i = 0; i < size; i++)
      std::cout << arr[i] << " ";

  int a[] = {3, 3, 4, 2, 4, 4, 2, 4, 4};
  
  std::cout << "\n\nmajority element" << std::endl;

  std::cout << "array" << std::endl;

  for(int i = 0; i < (sizeof(a) / sizeof(a[0])); i++)
    std::cout << a[i] << " ";

  std::cout << "majority element is: " <<  algo::majorityElement(a, sizeof(a) / sizeof(a[0])) << std::endl;
  
  std::cout << "\ndone!" << std::endl;
  
  return 0;
}
