#include<stdio.h>

int partition (int a[], int low, int high) {
    int pivot, i, j, temp;
    pivot=a[low];
    i = low+1;
    j = high;
    do{
        while (a[i] <= pivot) {
            i++;
        }
        
        while (a[j] > pivot) {
            j--;
        }
        
        if (i < j) {
            temp = a[j];
            a[j] = a[i];
            a[i] = temp;
        }

        printf("\nTHE INTER ARRAY IS : \n");
        for (int i = 0; i < 10; i++) {
            printf("%d\t", a[i]);
        }
    printf("\n");
        
    }while(i<j);
    
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    printf("\nTHE INTERMEDIATE ARRAY IS : \n");
        for (int i = 0; i < 10; i++) {
            printf("%d\t", a[i]);
        }
    printf("\n");
    
    return j;
}

void quickSort (int a[], int n, int low, int high) {
    int partitionIndex;
    
   if (low < high) {
        partitionIndex = partition (a, low, high);
        quickSort (a, n, low, partitionIndex-1);
        quickSort (a, n, partitionIndex+1, high);
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

    printf ("THE ARRAY IS : \n");

    for (int i = 0; i < n; i++) {
        printf ("%d\t", a[i]);
    }

    quickSort(a, n, 0, n-1);

    printf ("\n\nTHE SORTED ARRAY IS : \t");
    for (int i = 0; i < n; i++) {
        printf ("%d\t", a[i]);
    }
    return 0;
}
