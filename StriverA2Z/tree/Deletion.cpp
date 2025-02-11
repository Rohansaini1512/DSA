/*Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
 

Example 1:


Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

Example 2:

Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.
Example 3:

Input: root = [], key = 0
Output: []
 */

class Solution {
    // Helper function to find the rightmost node (maximum node) in a subtree
    TreeNode* findLast(TreeNode* root){
        if(root->right == NULL) return root; // If there's no right child, return the current node
        return findLast(root->right); // Otherwise, keep moving to the right
    }

    // Function to handle node deletion and restructuring of the BST
    TreeNode* Helper(TreeNode* root){
        // Case 1: Node has no left child → Return right child (or NULL if both are NULL)
        if(root->left == NULL) return root->right;

        // Case 2: Node has no right child → Return left child
        if(root->right == NULL) return root->left;

        // Case 3: Node has both left and right children
        TreeNode* rightChild = root->right;      // Store reference to the right subtree
        TreeNode* lastRight = findLast(root->left); // Find the rightmost node in the left subtree
        lastRight->right = rightChild; // Attach the original right subtree to the rightmost node of left subtree
        return root->left; // Return the left subtree as the new root
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL; // Base case: If tree is empty

        // If root itself is the key, process deletion directly
        if(root->val == key) return Helper(root);

        TreeNode* dummy = root; // Store reference to the original root

        while(root != NULL){
            if(root->val > key){ // Key lies in the left subtree
                if(root->left != NULL && root->left->val == key){
                    root->left = Helper(root->left); // Found the node to delete, call helper function
                    break; // Exit loop after deletion
                }else{
                    root = root->left; // Keep searching in the left subtree
                }
            }else{ // Key lies in the right subtree
                if(root->right != NULL && root->right->val == key){
                    root->right = Helper(root->right); // Found the node to delete, call helper function
                    break; // Exit loop after deletion
                }else{
                    root = root->right; // Keep searching in the right subtree
                }
            }
        }
        return dummy; // Return the original root of the modified tree
    }
};
