#include 
<bits/stdc++.h>
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
    
#include <iostream>
using namespace std;

int main()
{   int n,m;
    cin>>n>>m;
    
    int target;
    cin>>target;
    int mat[n][m];
    
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            cin>>mat[i][j];
        }
    }
    
    int r=0, c=m-1;
    bool found=false;
    
    while(r<n && c>=0){
        if(mat[r][c]==target){
            found=true;
        }
        else if(mat[r][c]>target){
            c--;
        }
        else{
            r++;
        }
    }
    
    if (found){
        cout<<"element found";
    }
    else{
        cout<<"element does not exist";
    }
    
    

    return 0;
}