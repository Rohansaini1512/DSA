#include<bits/stdc++.h>
using namespace std;

stack<int>insert(stack<int>&st, int data){
    stack<int>temp;
    while(not st.empty()){
        int curr = st.top();
        temp.push(curr);
        st.pop();
    }
    temp.push(data);
    while(not temp.empty()){
        int curr = temp.top();
        st.push(curr);
        temp.pop();
    }
    return st;
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(3);
    st.push(5);
    st.push(6);
    st.push(8);
    stack<int>st2 = insert(st, 4);
    while(not st2.empty()){
        cout<<st2.top()<<" ";
        st2.pop();
    }
    cout<<endl;
}