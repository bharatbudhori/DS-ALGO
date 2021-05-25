#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];   
        }
    }
    
    int row_st=0, col_st=0, row_end=n-1, col_end=m-1;
    
    while(row_st<=row_end && col_st<=col_end){
        
        
    //for row_st
    for(int col=col_st; col<=col_end;col++){
        cout<<arr[row_st][col]<<" ";
    }
    row_st++;
    
    //for col_end
    for(int row=row_st;row<=row_end;row++){
        cout<<arr[row][col_end]<<" ";
    }
    col_end--;
    
    //for row_end
    for(int col=col_end; col>=col_st;col--){
        cout<<arr[row_end][col]<<" ";
    }
    row_end--;
    
    //for col_st
    for(int row=row_end; row>=row_st; row--){
        cout<<arr[row][col_st]<<" ";
    }
    col_st++;  
    }
    
    return 0;
}