#include<stdio.h>
#include<stdlib.h>
#define MAX 50

void mergeSort(int[],int,int);
void simpleMerge(int[],int,int,int);

main()
{
    int array[MAX],size,i;
    printf("Enter the size of an array\n");
    scanf("%d",&size);
    printf("Enter array elements\n");
    for(i=0;i<size;i++)
    {
        scanf("%d",&array[i]);
    }
    mergeSort(array,0,size-1);
    printf("\nAfter sorting array elements are\n");
    for(i=0;i<size;i++)
        printf("%d ",array[i]);
}
void mergeSort(int a[],int low,int high)
{
    int mid,i;
    if(low<high)
    {
        mid=(low+high)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        simpleMerge(a,low,mid,high);
    }
}
void simpleMerge(int a[],int low,int mid,int high)
{
    int i=low,j=mid+1,k=low;
    int c[50];
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
        c[k++]=a[i++];
        else
        c[k++]=a[j++];
    }
    while(i<=mid)
        c[k++]=a[i++];
    while(j<=high)
        c[k++]=a[j++];
    for(i=low;i<=high;i++)
        a[i]=c[i];
}
