#include <iostream>
using namespace std;

void swap(int arr[], int i, int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

void waveSort(int arr[], int n){
    
    for(int i=1;i<n;i+=2){
        if(arr[i]>arr[i-1]){
            swap(arr,i,i-1);
        }
        if(arr[i]>arr[i+1] && i<=n-2){
            swap(arr,i,i+1);
        }
    }
}

int main()
{
    int arr[]={1,3,4,5,6,7,8,9,2};
    waveSort(arr,9);
    
    for(int i=0;i<9;i++){
        cout<<arr[i];
    }

    return 0;
}