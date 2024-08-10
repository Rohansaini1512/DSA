#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string s) {
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
        } else {
            // Check if stack is empty before accessing the top element
            if (st.empty()) {
                return false;
            }
            char curr = st.top();
            if ((s[i] == ')' && curr == '(') ||
                (s[i] == '}' && curr == '{') ||
                (s[i] == ']' && curr == '[')) {
                st.pop();
            } else {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    string s = "{[()]})";
    cout << (isBalanced(s) ? "Balanced" : "Not Balanced") << "\n";
    return 0;
}
