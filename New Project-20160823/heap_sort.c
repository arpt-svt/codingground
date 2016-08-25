#include <stdio.h>

void swap(int *a,int *b){
    *a^=*b^=*a^=*b;
}
void heapify(int arr[],int n,int i){
    int max = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l<n && arr[l] > arr[max]) max = l;
    if(r<n && arr[r] > arr[max]) max = r;
    if(max!=i){
        swap(&arr[i],&arr[max]);
        heapify(arr,i,max); 
    }
}

void heapsort(int arr[],int n){
    int i;
    for(i=n/2 - 1 ; i>=0;i--) heapify(arr,n,i);
    for(i=n-1;i>=0;i--){
        swap(&arr[0],&arr[i]);
        heapify(arr,n,0);
    }
}

void print(int arr[],int n){
    int i=0;
    for(;i<n;i++) printf(" %d ",arr[i]);
}
int main()
{
    int arr[] = {22,312,4,1,0,213};
    int n = 6;
    heapsort(arr,n);
    print(arr,n);
    return 0;
}
