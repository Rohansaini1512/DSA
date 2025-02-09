/*Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.
Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
Example 2:

Input: root = [1], target = 1, k = 3
Output: []
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    // Function to create a parent mapping for each node in the tree
    void Mark(TreeNode* &root, TreeNode* &target, unordered_map<TreeNode*, TreeNode*>& mp) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            // If the current node has a left child, store its parent in the map
            if (curr->left) {
                mp[curr->left] = curr;  // Mapping child to parent
                q.push(curr->left);
            }

            // If the current node has a right child, store its parent in the map
            if (curr->right) {
                mp[curr->right] = curr;  // Mapping child to parent
                q.push(curr->right);
            }
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> mp; // Map to store parent references for each node
        Mark(root, target, mp); // Call function to populate the parent map

        unordered_map<TreeNode*, bool> vis; // Map to track visited nodes
        queue<TreeNode*> q;
        q.push(target); // Start BFS from the target node
        vis[target] = true; // Mark target as visited

        int currL = 0; // Current level distance from the target node

        // Perform BFS to find nodes at distance k
        while (!q.empty()) {
            int size = q.size();
            if (currL++ == k) break; // Stop if we've reached the required level

            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                // Check left child
                if (curr->left && !vis[curr->left]) {
                    q.push(curr->left);
                    vis[curr->left] = true;
                }

                // Check right child
                if (curr->right && !vis[curr->right]) {
                    q.push(curr->right);
                    vis[curr->right] = true;
                }

                // Check parent node
                if (mp[curr] && !vis[mp[curr]]) {
                    q.push(mp[curr]);
                    vis[mp[curr]] = true;
                }
            }
        }

        vector<int> res;
        // Collect all nodes that are exactly at distance k
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            res.push_back(curr->val);
        }

        return res; // Return result
    }
};

