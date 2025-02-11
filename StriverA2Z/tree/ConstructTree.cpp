/*Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

*/

class Solution {
    TreeNode* Helper(vector<int>& preorder ,int prestart ,int preend , vector<int>& inorder , int instart , int inend , unordered_map<int , int>&mp){
        if (prestart > preend || instart > inend) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[prestart]);

        int rootIdx = mp[root->val];
        int leftSize = abs(instart - rootIdx);
        root->left = Helper(preorder , prestart+1 , prestart + leftSize , inorder , instart , rootIdx-1 , mp);
        root->right = Helper(preorder , prestart+leftSize+1 , preend , inorder , rootIdx+1 , inend , mp);
        return root;
    }
public:
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int , int>mp;
        for(int i = 0 ; i < inorder.size() ; i++){
            mp[inorder[i]] = i;
        }
        return Helper(preorder , 0 , preorder.size()-1 , inorder , 0 , inorder.size()-1 , mp);
    }
};
