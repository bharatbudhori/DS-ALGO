#include <iostream>
using namespace std;

int firstOcc(int arr[], int n, int i, int key){
    if(i==n){
        return -1;
    }
    if(arr[i]==key){
        return i;
    }
    return firstOcc(arr,n,i+1,key);
}

int lastOcc(int arr[], int n, int i, int key){
if(i==n){
        return -1;
    }
    int restArr=lastOcc(arr,n,i+1,key);
    if(restArr != -1){
        return restArr;
    }
    if(arr[i]==key){
        return i;
    }
    return -1;
    
}

int main() {
    // Write C++ code here
    int arr[]={4,2,5,6,3,2,5};
    cout<<firstOcc(arr,7,0,2)<<endl;
    cout<<lastOcc(arr,7,0,2)<<endl;

    return 0;
}