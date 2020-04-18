//C program for Insertion Sort by Saksham Khajuria, IT, 11912058
#include<stdio.h>
void insertionSort(int arr[],int n){
    int i,j,k;
    for(i=0;i<n;i++){
        j=arr[i];
        k=i-1;
        while(arr[k]>arr[i] && k>=0){           //to shift elements to make correct postion for unsorted element
            arr[k+1] = arr[k];
            k=k-1;
        }
        arr[k+1]=j;
    }
}
int main(){
    int i;
    int arr[]={1,5,2,7,4,8,3,6};
    insertionSort(arr,8);
    for ( i = 0; i < 8; i++)
    {
        printf("%d \t",arr[i]);
    }
    
    return 0;
}
