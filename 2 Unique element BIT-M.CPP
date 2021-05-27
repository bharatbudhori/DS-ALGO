#include <iostream>
using namespace std;


int setBit(int n, int pos){
    return((n&(1<<pos))!=0);
}

void unique2(int arr[],int n){
    
    int xorSum=0;
    for(int i=0; i<n;i++){
      xorSum=xorSum^arr[i];  
    }
    
    int setbit=0, pos=0, tempXor=xorSum;
    
    while(setbit != 1){
        setbit=xorSum&1;
        pos++;
        xorSum=xorSum>>1;
    }
    
    int newXor=0;
    for(int i=0;i<n;i++){
        if(setBit(arr[i],pos-1)){
            newXor=newXor^arr[i];
        }
    }
    
    cout<<newXor<<endl;
    cout<<(tempXor^newXor)<<endl;
}

int main()
{  
    int arr[]={1,2,3,4,5 ,1,2,3};
    unique2(arr,8);
    return 0;
}