#include<stdio.h>
#include<conio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int i=low, j=high+1;
    int pivot=arr[low];

    while (i<j){
        while (pivot >= arr[i]) i++;
        while (pivot < arr[j]) j--;

        if (i<j) swap(&arr[i], &arr[j]);
    } 
    swap (&arr[low], &arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int j = partition(arr, low, high);  

        quickSort(arr, low, j-1);
        quickSort(arr, j+1, high);
    }
}

int main() {
    int arr[10], n, i;

    printf("Enter no. of elemetns:\n");
    scanf ("%d", &n);

    printf ("Enter elements:\n");
    for (i=0; i<n; i++){
        scanf ("%d",&arr[i]);
    }
    quickSort(arr, 0, n-1);

    printf("Sorted array: ");
    for (i=0; i<n; i++){
        printf ("%d  ", arr[i]);
    }

    return 0;
}
