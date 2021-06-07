/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

void reverseSentence(string s){
    stack<string> st;
    
    for(int i=0;i<s.length();i++){
        
        string word="";
        while(s[i] != ' ' && i<s.length()){
            word+=s[i];
            i++;
        }
        st.push(word);
    }
    while(! st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

int main()
{
    string  s="Hello, how are you doing?";
    reverseSentence(s);

    return 0;
}
