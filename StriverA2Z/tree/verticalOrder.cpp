/*Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.
Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation:
Column -1: Only node 9 is in this column.
Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
Column 1: Only node 20 is in this column.
Column 2: Only node 7 is in this column.

*/

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int,multiset<int>>>nodes;
        queue<pair<TreeNode* , pair<int,int>>>to;
        to.push({root , {0,0}});
        while(!to.empty()){
            auto p = to.front();
            to.pop();
            TreeNode* node = p.first;
            int x = p.second.first , y = p.second.second;
            nodes[x][y].insert(node->val);
            if(node->left){
                to.push({node->left , {x-1 , y+1}});
            }
            if(node->right){
                to.push({node->right , {x+1 , y+1}});
            }
        }
        vector<vector<int>>ans;
        for(auto p:nodes){
            vector<int>c;
            for(auto q:p.second){
                c.insert(c.end() , q.second.begin() , q.second.end());
            }
            ans.push_back(c);
        }
        return ans;
    }
};
