#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={3,45,6,8,4,5,7,8,9,1,3,4};
    int maxProfit=0;
    int minSoFar=arr[0];
    int len = sizeof(arr)/sizeof(arr[0]);
    
    for (int i=0;i<len;i++){
        minSoFar=min(minSoFar,arr[i]);
        
        int profit=arr[i]-minSoFar;
        maxProfit=max(maxProfit,profit);
    }
    
    cout<<maxProfit;
    
    
    return 0;
}