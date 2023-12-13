#include<stdio.h>

void selectionSort (int arr[], int n){
  int indexOfMin;

  for (int i=0;i<n-1;i++){
    indexOfMin = i;
    int temp;
    for (int j = i+1; j < n; j++) {
      if (arr[j] < arr[indexOfMin]){
        indexOfMin = j;
      }
    }
    temp = arr[i];
    arr[i] = arr[indexOfMin];
    arr[indexOfMin] = temp;

    printf("\nTHE INTERMEDIATE ARRAY IS : \n");
    for (int i = 0; i < n; i++) {
      printf("%d\t", arr[i]);
    }
    printf("\n");
  }
}

int main ()
{
  int n;
  printf ("ENTER THE SIZE OF THE ARRAY : ");
  scanf ("%d", &n);
  int a[n];

  for (int i = 0; i < n; i++){
    printf ("ENTER ELEMENT %d : ", (i + 1));
    scanf ("%d", &a[i]);
  }

  printf ("THE ARRAY IS : \t");

  for (int i = 0; i < n; i++){
    printf ("%d\t", a[i]);
  }

  selectionSort(a,n);

  printf ("\n\nTHE SORTED ARRAY IS : \t");

  for (int i = 0; i < n; i++){
    printf ("%d\t", a[i]);
  }
}