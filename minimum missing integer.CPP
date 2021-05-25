#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    int N=1000;
    bool check[N];
    for(int i=0;i<N;i++){
        check[i]=false;
    }
    
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            check[arr[i]]=true;
        }
    }
    for(int i=1; i<N;i++){
        if(check[i]==false){
            cout<<i;
            return 0;
        }
    }
    cout<<"-1";
    
    return 0;
}