#include<bits/stdc++.h>
using namespace std;

class Queue {
    stack<int> st;
public:
    Queue() {}

    void push(int x) {
        this->st.push(x);
    }

    void pop() {
        if (this->st.empty()) {
            return;
        }
        stack<int> temp;
        while (not this->st.empty()) {
            temp.push(this->st.top());
            this->st.pop();
        }
        temp.pop();
        while (not temp.empty()) {
            this->st.push(temp.top());
            temp.pop();
        }
    }

    bool empty() {
        return this->st.empty();  // Return the result
    }

    int front() {
        stack<int> temp;
        while (not this->st.empty()) {
            temp.push(this->st.top());
            this->st.pop();
        }
        int ans = temp.top();
        while (not temp.empty()) {
            this->st.push(temp.top());
            temp.pop();
        }
        return ans;
    }
};

int main() {
    Queue q;  // Use the custom Queue class
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.pop();
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}
