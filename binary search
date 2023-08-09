#include <stdio.h>

int binarySearch(int array[], int x, int low, int high) {
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (array[mid] == x)
      return mid;

    if (array[mid] < x)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return -1;
}

int main(void) {
  int array[100],x,n,n1,i;
  printf("Enter the total no. of elements : ");
  scanf("%d", &n1);
  printf("Enter the array elements : ");
  for(i=0; i<=n1-1; i++)
  {
  	scanf("%d", &array[i]);
  }
  n = sizeof(array) / sizeof(array[0]);
  printf("Enter the search element : ");
  scanf("%d", &x);
  int result = binarySearch(array, x, 0, n - 1);
  if (result == -1)
    printf("Not found");
  else
    printf("Element is found at index %d", result);
  return 0;
}
