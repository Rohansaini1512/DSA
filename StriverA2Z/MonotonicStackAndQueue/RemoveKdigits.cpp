//Given string num representing a non-negative integer num, and an integer k, return the 
//smallest possible integer after removing k digits from num.
// Example 1:

// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

class Solution {
public:

string removeKdigits(string num, int k) {
    int n = num.size();
    stack<char> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && num[i] < st.top() && k > 0) {
            st.pop();
            k--;
        }
        st.push(num[i]);
    }

    while (k > 0 && !st.empty()) {
        st.pop();
        k--;
    }

    string result = "";
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    reverse(result.begin(), result.end());

    int i = 0;
    while (i < result.size() && result[i] == '0') {
        i++;
    }
    result = result.substr(i);

    return result.empty() ? "0" : result;
    }

};