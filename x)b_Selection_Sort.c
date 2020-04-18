//Selection Sort in C by Saksham Khajuria, IT, 11912058
#include<stdio.h>
//swapping two words
void swap(int *x,int *y){
    int temp;
    temp = *x;
    *x=*y;
    *y=temp;
}
//Selection Sort Algo
void selectionSort(int arr[],int n){
    int i,j,min;
    for (i = 0; i < n-1; i++)
    {
        min=i;      
        for(j=i+1;j<n;j++){         //marker
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        swap(&arr[i],&arr[min]);
    }
    
}
int main(){
    int arr[]={2,5,28,7,4,26,25};
    selectionSort(arr,7);
    int i;
    for ( i = 0; i < 7; i++)
    {
        printf("%d \t",arr[i]);
    }
    
    return 0;
}
