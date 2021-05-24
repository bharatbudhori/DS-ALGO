#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k; 
    int a[n];
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int b[100000];
    for(int i=0; i<100000; i++){
       b[i]=-1;
    }
    
    
    for(int i=0; i<n; i++){
       b[a[i]]=a[i];
    }
    int count=0;
    for(int i=0; i<100000;i++){
        if(b[i] != -1){
            count++;
            if(count==k){
                cout<<i;
                break;
            }
        }
        
    }
    return 0;
    
    
}