#include <stdio.h>
int BinarySearch(int *arr, int length, int find){
  int i = 0;
  int j = length - 1; // Length of array is n, last element is represented n - 1
  int middle = (i + j) / 2; //This will be floor due to integer data type
  while(i <= j){ //While the start does not excede int size of last value in array
    if(arr[middle] < find){ //If middle element is less than what is being searched for
      i = middle + 1; //Obviously the element is not found and the element is greater than middle point => make i one element to the right
    }
    else if(arr[middle] == find){ //The middle position is where the element exists in the array
      break;
    }
    else{ //This condition will be when arr[midd] > find
      j = middle - 1; // make j 1 element left of middle because find is less than arr[middle]
    }
    middle = (i + j) / 2; //if not found i or j changes, thus middle must also change.
  }
  return middle + 1;
}
int main(void){
  int arr[] = {10,88,100,103,109,245,800,842}; //Sorted int array of size n
  int find = 245;
  int length = sizeof(arr) / sizeof(*arr); // Determines the length by getting the full size of memory array uses and dividing by he size of first element memory size. Full memory / element memory = num elements = length
  int location = BinarySearch(arr,length, find);
  printf("The location of the element is at position: %d\n", location);
  return 0;
}
