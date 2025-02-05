/*Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []*/

class Solution {
    void f(TreeNode* root , vector<vector<int>>& res) {
        queue<TreeNode*> q;
        bool leftToRight = true; // To track direction
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> temp; // Store current level nodes

            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                temp.push_back(curr->val);

                // Always push left first, then right
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            // Reverse temp if it's a right-to-left level
            if (!leftToRight) {
                reverse(temp.begin(), temp.end());
            }

            res.push_back(temp);
            leftToRight = !leftToRight; // Toggle direction
        }
    }

public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) return res;
        f(root, res);
        return res;
    }
};
