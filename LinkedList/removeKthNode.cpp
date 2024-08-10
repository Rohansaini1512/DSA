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

void removeKthNode(Node* &head, int k){
    Node* ptr1 = head;
    Node* ptr2 = head;
    int count = k;
    while(count--){
        ptr2 = ptr2->next;
    }

    while(ptr2->next!=NULL){
        ptr2 = ptr2->next;
        ptr1 = ptr1->next;
    }
    Node* temp = ptr1->next;
    ptr1->next = temp->next;
    free(temp);
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

    removeKthNode(l1.head , 2);
    l1.display();
}