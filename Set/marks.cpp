//  Given the nummber of questions as n and the marks of correct answer as p and q marks for the incorrect answer . One can either attempt to solve the questiond in an examination and get either marks, the program calculates the total marks.
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,p,q;
    cin>>n>>p>>q;
    unordered_set<int> s;
    for(int i=0;i<=n;i++){
        for(int j = 0 ; j <= n ; j++){
            int correct = i;
            int incorrect = j;
            int unattempted = n - correct - incorrect;
            if(unattempted >= 0){
                int score = correct*p + incorrect*q;
                s.insert(score);
            }else{
                break;
            }
        }
    }
    cout<<s.size()<<endl;
    return 0;
}