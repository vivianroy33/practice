#include <stdio.h>
#include <stdlib.h>

//test arr
// int n = 6;
// int arr[6] = {2,5,1,7,12,4};

int n = 20;
int arr[20] = {2,5,23,7,12,66,5,234,7,24,12,5,1,12,12,23,234,111,0,12};
// i = 0; p = 0 -> 1
// i = 1; p = 1 -> 2;
// i = 2; p = 2 -> 2;
// i = 3; p = 2 -> 3;

//take last as pivot
//move small to left, greater to right
//return next pivot
int SortPartition(int* arr, int firstIdx, int lastIdx)
{
  int pIdx, temp;
  pIdx = firstIdx;
  //compare until the end
  for (int i=firstIdx; i<=lastIdx; i++)
  {
    if(arr[i]<arr[lastIdx])
    {
      //increase idx if smaller
      //if greater continue go without increase pIdx
      //face next smaller after greaters -> swap with current pIdx to move smaller to left side
      if (i > pIdx)
      {
        temp = arr[i];
        arr[i] = arr[pIdx];
        arr[pIdx] = temp;
      }
      pIdx++;
      //printf("%d,", pIdx);
    }
  }

  //swap last value to pivot location
  temp = arr[lastIdx];
  arr[lastIdx] = arr[pIdx];
  arr[pIdx] = temp;
  return pIdx;
}

void QuickSort(int *arr, int firstIdx, int lastIdx)
{
  int pIdx;
  static int round=0;
  pIdx = SortPartition(arr, firstIdx, lastIdx);

  //soft separate partition
  if ((pIdx) > firstIdx)
    QuickSort(arr, firstIdx, pIdx - 1);
  
  //soft right
  if ((pIdx) < lastIdx)
    QuickSort(arr, pIdx + 1, lastIdx);
}

int main()
{
  // int n;
  // scanf("%d", &n);
  // int* arr = malloc(n * sizeof(int));
  // for (int i=0; i<n; i++)
  // {
  //   scanf("%d", &arr[i]);
  // }

  /* sorting */
  QuickSort(arr, 0, n-1);
  printf("Sorted:\n");
  for (int i=0; i<n; i++)
  {
    printf("%d ", arr[i]);
  } 
}