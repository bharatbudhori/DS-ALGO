#include <bits/stdc++.h>
using namespace std;

int largestRectangle(vector<int> &heights){
    int n=heights.size();
    vector<int> left(n),right(n);
    
    stack<int> st;
    
    for(int i=0;i<n;i++){            //filling left
        
        if(st.empty()){
            left[i]=0;
            st.push(i);
        }
        else{
            while(! st.empty() and heights[st.top()]>=heights[i]){
                st.pop();
            }
            left[i]=st.empty()? 0 : st.top()+1;
            st.push(i);
        }
    }
    while(! st.empty())
        st.pop();
    
    for(int i=n-1;i>=0;i--){            //filling right
        
        if(st.empty()){
            left[i]=n-1;
            st.push(i);
        }
        else{
            while(! st.empty() and heights[st.top()]>=heights[i]){
                st.pop();
            }
            right[i]=st.empty()? n-1 : st.top()-1;
            st.push(i);
        }
    }
    
    int max_area=0;
    for(int i=0;i<n;i++){
        max_area=max(max_area, heights[i]*(right[i]-left[i]+1));
    }
    return max_area;
    
}

int main()
{
    vector<int> vect;
 
    vect.push_back(2);
    vect.push_back(1);
    vect.push_back(5);
    vect.push_back(6);
    vect.push_back(2);
    vect.push_back(3);
    
    cout<<largestRectangle(vect);
    return 0;
}
