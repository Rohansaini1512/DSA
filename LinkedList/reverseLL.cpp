#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int val;
    Node* next;

    Node(int data ){
        val = data;
        next = NULL;
    }
};

class LinkedList{
    public:
       Node* head;

    LinkedList(){
        head=NULL;
    }

    void insertAtTail(int value){
        Node* new_node = new Node(value);
        if(head == NULL){
            head = new_node;
            return;
        }

        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }

    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->val<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

Node* reverseLL(Node* &head){
    Node* prevptr = NULL;
    Node* currptr = head;

    while(currptr != NULL){
        Node* nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }

    Node* new_head = prevptr;
    return new_head;
};

Node* reverseLLRecursion(Node* &head){

    // base case
    if(head == NULL || head->next == NULL){
        return head;
    }

    // recursive call
    Node* new_head = reverseLLRecursion(head->next);
    head->next->next = head;
    head->next = NULL;
    return new_head;
}

Node* reverseKLL(Node* &head , int k){
    Node* prevptr = NULL;
    Node* currptr = head;

    int counter = 0;
    while(currptr != NULL && counter<k){
        Node* nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        counter++;
    }
    if(currptr != NULL){
        Node* new_head = reverseKLL(currptr , k);
        head->next = new_head;
    }

    return prevptr;
    
}

int main(){

    LinkedList l1;
    l1.insertAtTail(1);
    l1.insertAtTail(2);
    l1.insertAtTail(3);
    l1.insertAtTail(4);
    l1.insertAtTail(5);
    l1.insertAtTail(6);
    l1.display();
    // l1.head = reverseLLRecursion(l1.head);
    l1.head = reverseKLL(l1.head , 2);
    l1.display();
}