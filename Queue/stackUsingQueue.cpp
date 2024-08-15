#include<bits/stdc++.h>
using namespace std;

class Stack {
    queue<int> q;
public:
    Stack() {}

    void push(int x) {
        q.push(x);
    }

    void pop() {
        if (q.empty()) return;

        int size = q.size();
        queue<int> temp;
        for (int i = 0; i < size - 1; i++) {
            temp.push(q.front());
            q.pop();
        }
        q.pop(); 

        q = temp; 
    }

    bool empty() {
        return q.empty();
    }

    int top() {
        if (q.empty()) return -1; 

        int size = q.size(); 
        queue<int> temp;
        int ans;
        for (int i = 0; i < size - 1; i++) {
            temp.push(q.front());
            q.pop();
        }
        ans = q.front(); 
        temp.push(ans); 
        q.pop();

        q = temp; 
        return ans;
    }
};

int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.pop();
    while (not st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}
