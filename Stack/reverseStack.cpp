#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int>&st, int data){
    if(st.empty()){
        st.push(data);
        return;
    }
    int curr = st.top();
    st.pop();
    insertAtBottom(st, data);
    st.push(curr);
}

void f(stack<int>&st){
    if(st.empty()){
        return;
    }
    int curr = st.top();
    st.pop();
    f(st);
    insertAtBottom(st, curr);
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(3);
    st.push(5);
    st.push(6);
    st.push(8);
    while(not st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    // cout<<endl;
    f(st);
    while(not st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}