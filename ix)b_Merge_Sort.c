//Merge Sort in C by Saksham khajuria, IT, 11912058
#include<stdio.h>
//merging two arrays
void merge(int arr[],int lower,int mid,int upper){
    //dividing a array in two separate subarrays
    int n1=mid-lower+1;
    int n2=upper-mid;
    int left[n1],right[n2];
    int i,j,k;
    //copying the data to sub arrays
    for ( i = 0; i < n1; i++)
    {
        left[i] = arr[lower+i];
    }
    for ( j = 0; j < n2; j++)
    {
        right[j] = arr[mid+1+j];
    }
    i=0;j=0;k=lower;        //initializing index
    //sorting the two different arrays and merging them
    while(i<n1 && j<n2){
        if(left[i]<=right[j]){
            arr[k++] = left[i++];
        }
        else{
            arr[k++] = right[j++];
        }
    }
    //copying the remaining elements
    for(;i<n1;i++){
        arr[k++] = left[i];
    }
    for(;j<n2;j++){
        arr[k++] = right[j++];
    }   
}
//divide and conquer algo
void mergeSort(int arr[],int lower,int upper){
    if(lower<upper){
        int mid = (lower+upper)/2;
        mergeSort(arr,lower,mid);
        mergeSort(arr,mid+1,upper);
        merge(arr,lower,mid,upper);
    }
}
int main(){
    int arr[]={3,6,1,8,2,7,5};
    mergeSort(arr,0,6);
    int i;
    for ( i = 0; i < 7;i++)
    {
        printf("%d \t",arr[i]);
    }
    
    return 0;
}
