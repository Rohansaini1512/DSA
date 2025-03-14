/*You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

 

Example 1:


Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
Example 2:


Input: root = [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]
Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.
 */

class Solution {
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
    TreeNode* prev;

    void inorder(TreeNode* root) {
        if (root == NULL) return;

        // Left subtree
        inorder(root->left);

        // Find misplaced nodes
        if (prev != NULL && root->val < prev->val) {
            if (first == NULL) {
                first = prev;
                middle = root;
            } else {
                last = root;
            }
        }

        prev = root;

        // Right subtree
        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        first = last = middle = NULL;
        prev = new TreeNode(INT_MIN);  // Dummy node with smallest possible value

        inorder(root);

        // Fix swapped nodes
        if (first && last) 
            swap(first->val, last->val);
        else if (first && middle) 
            swap(first->val, middle->val);
    }
};
