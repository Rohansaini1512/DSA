#include <iostream>
using namespace std;

class Node{
    public:
    
    int value;
    Node* left;
    Node* right;
    Node(int v){
        value = v;
        left = right = NULL;
    }
};

class BST{
    public:
    Node* root;
    BST(){
        root = NULL;
    }
};

void insert(Node* &root , int val){
    Node* newNode = new Node(val);
    if(root == NULL){
        root = newNode;
        return;
    }
    Node* currNode = root;
    while(true){
        if(currNode->value > newNode->value){
            if(currNode->left == NULL){
                currNode->left = newNode;
                return;
            }
            currNode = currNode->left;
        }else{
            if(currNode->right == NULL){
                currNode->right = newNode;
                return;
            }
            currNode = currNode->right;
        }
    }
}

Node* recursiveInsert(Node* &root , int val){
    if(root == NULL){
        Node* newNode = new Node(val);
        return newNode;
    }
    
    if(root->value > val){
        root->left =  recursiveInsert(root->left , val);
    }
    else{
        root->right =  recursiveInsert(root->right , val);
    }
    
    return root;
}

void inorderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    
    inorderTraversal(root->left);
    cout << root->value <<" ";
    inorderTraversal(root->right);
}

bool searchBST(Node* root , int key){
    if(root == NULL){
        return false;
    }
    if(root->value == key){
        return true;
    }
    if(root->value > key){
        return searchBST(root->left , key);
    }else{
        return searchBST(root->right , key);
    }
}

Node* largestNode(Node* root){
    Node* curr = root;
    while(curr && curr->right){
        curr = curr->right;
    }
    return curr;
}

Node* deleteBST(Node* root , int key){
    if(root == NULL){
        return root;
    }
    if(root->value > key){ // The key is smaller, go left
        root->left = deleteBST(root->left , key);
    }
    else if(root->value < key){ // The key is larger, go right
        root->right = deleteBST(root->right, key);
    }
    else{
        if(root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }
        // node has 1 child node
        else if(root->left == NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }
        // node has 2 child nodes
        else{
            Node* justSmaller = largestNode(root->left);
            root->value = justSmaller->value;
            root->left = deleteBST(root->left , justSmaller->value);
        }
    }
    return root; // Make sure to return the modified root at the end of the function
}


int main()
{
    BST bst1;
    bst1.root = recursiveInsert(bst1.root , 4);
    recursiveInsert(bst1.root , 5);
    recursiveInsert(bst1.root , 3);
    recursiveInsert(bst1.root , 1);
    inorderTraversal(bst1.root);
    cout<<endl;
    
    cout<<searchBST(bst1.root , 3);
    cout<<endl;
    
    bst1.root = deleteBST(bst1.root , 3);
    inorderTraversal(bst1.root);
    cout<<endl;

    return 0;
}