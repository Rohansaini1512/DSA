#include<bits/stdc++.h>
using namespace std;

stack<int> copyStack(stack<int> &input){
    stack<int> temp;
    while(not input.empty()){
        int curr = input.top();
        temp.push(curr);
        input.pop();
    }
    stack<int> output;
    while(not temp.empty()){
        int curr = temp.top();
        output.push(curr);
        temp.pop();
    }
    return output;
}

void f(stack<int>&st , stack<int>&st2){
    if(st.empty()){
        return;
    }
    int curr = st.top();
    st.pop();
    f(st,st2);
    st2.push(curr);
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(3);
    st.push(5);
    st.push(6);
    st.push(8);
    // stack<int> st2 = copyStack(st);
    stack<int> st2;
    f(st,st2);
    while(not st2.empty()){
        cout<<st2.top()<<"";
        st2.pop();
        
    }
    cout<<endl;

}