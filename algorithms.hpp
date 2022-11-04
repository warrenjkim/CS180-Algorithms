#include <vector>


// merge sort algorithm

namespace srt {
  //helper function merge()
  // merge() merges two halves of the array

  namespace {
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
	if(leftArr[left] < rightArr[right])
	  arr[curr++] = leftArr[left++];
	else
	  arr[curr++] = rightArr[right++];
      }

      // pour the rest of each array into the final array
      while(left < leftSize)
	arr[curr++] = leftArr[left++];

      while(right < rightSize)
	arr[curr++] = rightArr[right++];
      
      // delete dynamic arrays
      delete[] leftArr;
      delete[] rightArr;

      // end of function      
    }
  }

  void mergeSort(int* arr, int start, int end) {
    // base case: if start >= end
    if(start >= end)
      return;

    // recursive case: call mergeSort() on the left and right partitions
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
}

