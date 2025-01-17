// Given a rows x cols binary matrix filled with 0's and 1's, 
//find the largest rectangle containing only 1's and return its area.

class Solution {
public:

int lHist(vector<int>& heights) {
    int n = heights.size();
    stack<int> st;
    int maxArea = 0;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] > heights[i]) {
            int height = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : (i - st.top() - 1);
            maxArea = max(maxArea, height * width);
        }
        st.push(i);
    }

    while (!st.empty()) {
        int height = heights[st.top()];
        st.pop();
        int width = st.empty() ? n : (n - st.top() - 1);
        maxArea = max(maxArea, height * width);
    }

    return maxArea;
}


int maximalRectangle(vector<vector<char>>& matrix) {
    int n = matrix.size();
    if (n == 0) return 0; 
    int m = matrix[0].size();

    vector<vector<int>> pre(n, vector<int>(m, 0));
    for (int j = 0; j < m; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (matrix[i][j] - '0'); 
            if (matrix[i][j] == '0') sum = 0; 
            pre[i][j] = sum; 
        }
    }

    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        maxArea = max(maxArea, lHist(pre[i]));
    }

    return maxArea;
}

};