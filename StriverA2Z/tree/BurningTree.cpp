/*Given a binary tree and a node data called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.
Note: The tree contains unique values.

Examples : 

Input: root[] = [1,2,3,4,5,N,6,N,N,7,8,N,9,N,N,N,N,N,10],  target = 8
  
Output: 7
Explanation: If leaf with the value 8 is set on fire. 
After 1 sec: 5 catches fire.
After 2 sec: 2, 7 catches fire.
After 3 sec: 4, 1 catches fire.
After 4 sec: 3 catches fire.
After 5 sec: 6 catches fire.
After 6 sec: 9 catches fire.
After 7 sec: 10 catches fire.
It takes 7s to burn the complete tree.
Input: root[] = [1, 2, 3, 4, 5, N, 7, 8, N, 10], target = 10

Output: 5
Explanation: If leaf with the value 10 is set on fire. 
- After 1 sec: Node 5 catches fire.
- After 2 sec: Node 2 catches fire.
- After 3 sec: Nodes 1 and 4 catches fire.
- After 4 sec: Node 3 and 8 catches fire.
- After 5 sec: Node 7 catches fire.
It takes 5s to burn the complete tree.*/

class Solution {
    // Function to find the maximum distance using BFS
    int dist(unordered_map<Node*, Node*>& par, Node*& start) {
        queue<Node*> q;
        unordered_map<Node*, bool> vis;
        q.push(start);
        vis[start] = true;
        int maxi = 0;

        while (!q.empty()) {
            int size = q.size();
            int fl = 0;  // Flag to check if we are moving further
            while (size--) {
                Node* curr = q.front();
                q.pop();

                // Check left child
                if (curr->left && !vis[curr->left]) {
                    fl = 1;
                    q.push(curr->left);
                    vis[curr->left] = true;
                }

                // Check right child
                if (curr->right && !vis[curr->right]) {
                    fl = 1;
                    q.push(curr->right);
                    vis[curr->right] = true;
                }

                // Check parent (use find to avoid accessing invalid keys)
                if (par.find(curr) != par.end() && !vis[par[curr]]) {
                    fl = 1;
                    q.push(par[curr]);
                    vis[par[curr]] = true;
                }
            }
            if (fl) maxi++;  // Increase the distance if at least one new node is added
        }
        return maxi;
    }

    // Function to populate parent mapping and find target node
    Node* f(Node*& root, unordered_map<Node*, Node*>& par, int target) {
        if (!root) return nullptr;  // Base case

        queue<Node*> q;
        q.push(root);
        Node* t = nullptr;  // Initialize pointer

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            if (curr->data == target) t = curr;

            // Store parent mapping
            if (curr->left) {
                par[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                par[curr->right] = curr;
                q.push(curr->right);
            }
        }
        return t;  // Return the target node
    }

public:
    int minTime(Node* root, int target) {
        unordered_map<Node*, Node*> par;  // Map to store parent pointers
        Node* start = f(root, par, target);

        // If target node is not found, return 0
        if (!start) return 0;

        int maxi = dist(par, start);
        return maxi;
    }
};
