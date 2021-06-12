#include <bits/stdc++.h>
using namespace std;

int trapWater(int a[], int n){
    stack<int> st;
    int ans=0;
    
    for(int i=0;i<n;i++){
        while(!st.empty() && a[st.top()]<a[i]){
            int cur=st.top();
            st.pop();
            
            if(st.empty()){
                break;
            }
            int diff=i-st.top()-1;
            ans+=(min(a[st.top()],a[i])-a[cur])*diff;
        }
        st.push(i);
    }
    return ans;
}

int main()
{
    int arr[]={4,2,0,3,2,5};
    
    cout<<trapWater(arr,6);

    return 0;
}
