#include<stdio.h>

void merge (int a[], int low, int mid, int high){
    int i=low , k=low , b[50];
    int j=mid+1;
    while (i <= mid && j <= high){
        if (a[i] < a[j]) {
            b[k] = a[i];
            i++;
            k++;
        }
        else{
            b[k] = a[j];
            j++;
            k++;
        }
    }

    while (i <= mid){
        b[k] = a[i];
        i++;
        k++;
    }

    while (j <= high){
        b[k] = a[j];
        i++;
        k++;
    }
    
    for (i = low; i <= high ; i++){
        a[i] = b[i];
    }
}

void mergeSort (int a[], int n, int low, int high){
    int mid;
    if (low < high){
        mid = (low + high)/2;
        mergeSort (a, n, low, mid);
        mergeSort (a, n, mid+1, high);
        merge (a, low, mid, high);
   }
}
void main ()
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
    for (int i = 0; i < n; i++) {
        printf ("%d\t", a[i]);
    }
    mergeSort(a, n, 0, n-1);
    printf ("\n\nTHE SORTED ARRAY IS : \t");
    for (int i = 0; i < n; i++) {
        printf ("%d\t", a[i]);
    }
}
