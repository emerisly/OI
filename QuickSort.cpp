/* C implementation QuickSort */
#include<stdio.h> 


void quickSort(int arr[], int left, int right) {
      int l = left, r = right;
      int tmp;
      int pivot = arr[(left + right) / 2];
      while (l <= r) {
            while (arr[l] < pivot) l++;
            while (arr[r] > pivot) r--;
            if (l <= r) {
                  tmp = arr[l];
                  arr[l] = arr[r];
                  arr[r] = tmp;
                  l++;r--;
            }
      }
      if (left < r) quickSort(arr, left, r);
      if (l < right) quickSort(arr, l, right);
}

int main() 
{ 
    int arr[] = {10, 7, 8, 9, 1, 5}; 
    //sizeof(arr)==24, sizeof(arr[0])==4
    //n=6
    int n = sizeof(arr)/sizeof(arr[0]); 
    quickSort(arr, 0, n-1); 
    printf("Sorted array: "); 
	for (int x:arr)
        printf("%d ", x); 
    return 0; 
} 
