#include <bits/stdc++.h>
using namespace std;

int calc(int v1, int v2, char op) {
    if(op == '+') return v1 + v2;
    if(op == '-') return v1 - v2;
    if(op == '*') return v1 * v2;
    if(op == '/') {
        if (v2 == 0) {
            throw runtime_error("Division by zero");
        }
        return v1 / v2;
    }
    if(op == '^') return pow(v1, v2);
    throw invalid_argument("Invalid operator");
}

int precedence(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    if(op == '^') return 3;
    return 0;
}

int eval(string &str) {
    stack<int> s;
    stack<char> ops;
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == '(') {
            ops.push(str[i]);
        }
        else if(str[i] == ')') {
            while(!ops.empty() && ops.top() != '(') {
                int v2 = s.top(); s.pop();
                int v1 = s.top(); s.pop();
                s.push(calc(v1, v2, ops.top()));
                ops.pop();
            }
            ops.pop(); // Remove the '(' from stack
        }
        else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^') {
            while(!ops.empty() && precedence(ops.top()) >= precedence(str[i])) {
                int v2 = s.top(); s.pop();
                int v1 = s.top(); s.pop();
                s.push(calc(v1, v2, ops.top()));
                ops.pop();
            }
            ops.push(str[i]);
        } 
        else if (isdigit(str[i])) {
            int num = 0;
            while (i < str.size() && isdigit(str[i])) {
                num = num * 10 + (str[i] - '0');
                i++;
            }
            i--; // Adjust for loop increment
            s.push(num);
        }
    }
    while(!ops.empty()) {
        int v2 = s.top(); s.pop();
        int v1 = s.top(); s.pop();
        s.push(calc(v1, v2, ops.top()));
        ops.pop();
    }
    return s.top();
}

int main() {
    string str = "1+(2*(3-1))+2";
    try {
        cout << eval(str) << endl;
    } catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}
