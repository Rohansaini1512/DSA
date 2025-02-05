#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int value;
        Node *left;
        Node *right;
        Node(int v){
            value = v;
            left = right = NULL;
        }
};

void preOrder(Node *root){
    if(root == NULL){
        return;
    }
    cout<<root->value<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    preOrder(root);
    cout<<endl;
    return 0;
}