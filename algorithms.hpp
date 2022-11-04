// this header file is appropriately names algorithms.hpp
// this file encapsulates most algorithms covered in CS180 lectures
// this file uses namespace algo for all algorithms
#include <vector>
#include <iostream>

namespace algo {
  
  // namespace internal for helper functions not intended for client use
  namespace internal {
    // helper function merge()
    // returns: void
    // purpose: merge two halves of an array (each side sorted)
    void merge(int* arr, int start, int mid, int end) {
      // size of partitions
      int leftSize = mid - start + 1;
      int rightSize = end - mid;

      // create two subarrays
      int* leftArr = new int[leftSize];
      int* rightArr = new int[rightSize];

      // fill partitions
      for(int i = 0; i < leftSize; i++)
	leftArr[i] = arr[start + i];
      for(int i = 0; i < rightSize; i++)
	rightArr[i] = arr[mid + 1 + i];

      // pointers to leftArr, rightArr, and arr respectively
      int left = 0;
      int right = 0;
      int curr = start;

      // merge the two arrays using two pointer paradigm
      while(left < leftSize && right < rightSize) {
	// add the smaller of the two values to the array
	arr[curr++] = leftArr[left] < rightArr[right] ? leftArr[left++]: rightArr[right++];
      }

      // pour the rest of each array into the final array
      while(left < leftSize)
	arr[curr++] = leftArr[left++];

      while(right < rightSize)
	arr[curr++] = rightArr[right++];
      
      // delete dynamic arrays
      delete[] leftArr;
      delete[] rightArr;

      // end of function merge()
    }

    template<typename K, typename V>
    struct pair {
      K first;
      V second;

      pair() : first(K()), second(V()) { }
      pair(K first, V second) : first(first), second(second) { }
    };

    // end of namespace internal
  }

  using namespace internal;


  // function mergeSort()
  // parameters: raw array (int*), start position (int), end position (int)
  // this algorithm runs in O(nlog(n)) time
  // Note: this function is written first because it is necessary for a lot of other algorithms
  
  void mergeSort(int* arr, int start, int end) {
    // base case: if start >= end
    if(start >= end)
      return;

    // recursively call mergeSort() on the left and right partitions
    // calculate midpoint
    int mid = start + (end - start) / 2;
    
    // left half
    mergeSort(arr, start, mid);

    // right half
    mergeSort(arr, mid + 1, end);

    // merge halves
    merge(arr, start, mid, end);

    // end of function
  }

  // function sort()
  // small wrapper function
  void sort(int* arr, int size) {
    mergeSort(arr, 0, size - 1);
  }



  // function majorityElement()
  // parameters: raw array of integers (int*)
  // this algorithm runs in O(n) time
  int majorityElement(int* arr, int size) {
    // auxiliary data structure
    // first = candidate
    // second = count
    pair<int, int> candidate(arr[0], 0);

    // iterate through the array
    for(int i = 0; i < size; i++) {
      // if the element is no longer the majority
      if(candidate.first != arr[i] && candidate.second == 0) {
	// replace the majority
	candidate.first = arr[i];
	candidate.second = 1;
      }
      else if(candidate.first == arr[i])
	candidate.second++;
      else
	candidate.second--;
    }

    // at this point, we have a majority candidate
    // if the majority has a count of more than n/2, they are the majority, else they're not
    candidate.second = 0;
    
    for(int i = 0; i < size; i++)
      if(candidate.first == arr[i])
	candidate.second++;


    // return only if the candidate is the majority
    return candidate.second > size / 2 ? candidate.first : -1;
    
    // end of function majorityElement()
  }
}

// end of namespace algo
