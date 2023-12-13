#include <stdio.h>

void insertionSort(int arr[], int n)
{
  int key, i, j;
  for (int i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;

    printf("\nTHE INTERMEDIATE ARRAY IS : \n");
    for (int i = 0; i < n; i++) {
      printf("%d\t", arr[i]);
    }
    printf("\n");
  }
  
  printf("\n\n\nTHE SORTED ARRAY IS : \t");
  
  for (int i = 0; i < n; i++) {
    printf("%d\t", arr[i]);
  }
}

int main()
{
  int n;
  printf("ENTER THE SIZE OF ATHE ARRAY : ");
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; i++) {
    printf("ENTER ELEMENT %d : ", (i + 1));
    scanf("%d", &a[i]);
  }
  printf("THE ARRAY IS : \t");
  for (int i = 0; i < n; i++) {
    printf("%d\t", a[i]);
  }
  insertionSort(a, n);
  return 0;
}