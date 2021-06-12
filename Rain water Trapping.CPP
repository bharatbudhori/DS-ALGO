#include <bits/stdc++.h>
using namespace std;

void trappedWater(int arr[], int n){
    int maxLeft[n];
    int maxRight[n];
    int maxL=0, maxR=0;
    
    for(int i=0;i<n;i++){
        if(i==0 ){
            maxLeft[i]=0;
            maxL=max(maxL,arr[i]);
            continue;
        }
        maxL=max(maxL,arr[i]);
        maxLeft[i]=maxL;
        
    }
    
    for(int i=n-1;i>=0;i--){
        if(i==n-1 ){
            maxRight[i]=0;
            maxR=max(maxR,arr[i]);
            continue;
        }
        maxR=max(maxR,arr[i]);
        maxRight[i]=maxR;
        
    }
    
    //for(int i=0;i<n;i++){
    //    cout<<maxLeft[i];
    //}
    //cout<<endl;
    //for(int i=0;i<n;i++){
    //    cout<<maxRight[i];
    //}
    //cout<<endl;
    int water=0;
    for(int i=0;i<n;i++){
        int x=(min(maxRight[i],maxLeft[i])-arr[i]);
        if(x>0){
            water+=x;
        }
    }
    
    cout<<water;
}

int main()
{
    int arr[]={8, 8, 2, 4, 5, 5, 1};
    
    trappedWater(arr,7);

    return 0;
}
