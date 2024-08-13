#include<bits/stdc++.h>
using namespace std;

int calc(int v1 , int v2 , char op){
    if(op == '+'){
        return v1+v2;
    }
    else if(op == '-'){
        return v1-v2;
    }
    else if(op == '*'){
        return v1*v2;
    }
    else if(op == '/'){
        return v1/v2;
    }else{
        return pow(v1,v2);
    }
    return 0;
}

int postfix(string &str){
    stack<int> s;
    for(int i=0;i<str.size();i++){
        if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^'){
            int v2 = s.top();
            s.pop();
            int v1 = s.top();
            s.pop();
            s.push(calc(v1,v2,str[i]));
        }else{
            s.push(str[i]-'0');
        }
    }
    return s.top();
}

int prefix(string &str){
    stack<int> s;
    for(int i=str.size()-1;i>=0;i--){
        if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^'){
            int v1 = s.top();
            s.pop();
            int v2 = s.top();
            s.pop();
            s.push(calc(v1,v2,str[i]));
        }else{
            s.push(str[i]-'0');
        }
    }
    return s.top();
}

int main(){
    string str = "231*+9-";
    cout<<postfix(str)<<endl;
    return 0;
}