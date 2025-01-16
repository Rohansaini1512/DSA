// Given an array of integers heights representing the histogram's bar height where the width 
//of each bar is 1, return the area of the largest rectangle in the histogram.

class Solution {
public:

vector<int> PSE(vector<int>& h) {
    int n = h.size();
    stack<int> st;
    vector<int> pse(n);
    for (int i = 0; i < n; i++) {
        while (!st.empty() && h[st.top()] >= h[i]) {
            st.pop();
        }
        pse[i] = st.empty() ? -1 : st.top(); 
        st.push(i);
    }
    return pse;
}

vector<int> NSE(vector<int>& h) {
    int n = h.size();
    stack<int> st;
    vector<int> nse(n);
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && h[st.top()] >= h[i]) {
            st.pop();
        }
        nse[i] = st.empty() ? n : st.top(); 
        st.push(i);
    }
    return nse;
}

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> pse = PSE(heights);
    vector<int> nse = NSE(heights);
    int maxArea = 0;
    
    for (int i = 0; i < n; i++) {
        int width = nse[i] - pse[i] - 1; 
        int area = heights[i] * width;  
        maxArea = max(maxArea, area);   
    }
    return maxArea;
    }

};