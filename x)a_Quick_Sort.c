//Quick Sort in C by Saksham Khajuria, IT, 11912058
#include<stdio.h>
//Program to swap
void swap(int *x,int *y){
    int temp;
    temp = *x;
    *x=*y;
    *y=temp;
}

//partition program
int part(int arr[],int lower,int upper){
    int i=lower-1;
    int pivot = arr[upper];     //pivot is initialized to the upper bound of array
    int j;
    for ( j = lower; j < upper; j++)            //pivot gets sorted first
    {
        if(pivot>arr[j]){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[upper]);
    return i+1;
}

//divide and conquer algo
void quickSort(int arr[],int lower,int upper){
    if(lower<upper){
        //recursive process takes place
        int partition = part(arr,lower,upper);
        quickSort(arr,lower,partition-1);       
        quickSort(arr,partition+1,upper);
    }
}

int main(){
    int arr[] = {5,7,2,6,1,9,8,3};
    quickSort(arr,0,7);
    int i;
    for ( i = 0; i < 8; i++)
    {
        printf("%d \t",arr[i]);
    }
    
    return 0;
}
