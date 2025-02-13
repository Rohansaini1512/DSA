/*You're given a binary tree. Your task is to find the size of the largest subtree within this binary tree that also satisfies the properties of a Binary Search Tree (BST). The size of a subtree is defined as the number of nodes it contains.

Note: A subtree of the binary tree is considered a BST if for every node in that subtree, the left child is less than the node, and the right child is greater than the node, without any duplicate values in the subtree.

Examples :

Input: root = [5, 2, 4, 1, 3]
Root-to-leaf-path-sum-equal-to-a-given-number-copy
Output: 3
Explanation:The following sub-tree is a BST of size 3
Balance-a-Binary-Search-Tree-3-copy
Input: root = [6, 7, 3, N, 2, 2, 4]

Output: 3
Explanation: The following sub-tree is a BST of size 3:
*/

class Solution {
    struct NodeValue {
        int minNode, maxNode, maxSize;
        
        NodeValue(int minNode, int maxNode, int maxSize)
            : minNode(minNode), maxNode(maxNode), maxSize(maxSize) {}
    };

    NodeValue Helper(Node* root) {
        if (!root) {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }
        
        auto left = Helper(root->left);
        auto right = Helper(root->right);
        
        // Check if the current subtree is a valid BST
        if (left.maxNode < root->data && root->data < right.minNode) {
            return NodeValue(min(root->data, left.minNode), 
                             max(root->data, right.maxNode), 
                             left.maxSize + right.maxSize + 1);
        }

        // If not a BST, return max size found in left/right subtree
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }

public:
    int largestBst(Node* root) {
        return Helper(root).maxSize;
    }
};
