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

Node* reOrder(Node* &head){
    Node* slow = head;
    Node* fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* curr = slow->next;
    slow->next = NULL;
    Node* prev = slow;
    while(curr){
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    Node* ptr1 = head;
    Node* ptr2 = prev;

    while(ptr1 != ptr2){
        Node* temp = ptr1->next;
        ptr1->next = ptr2;
        ptr1 = ptr2;
        ptr2 = temp;
    }

    return head;
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

    l1.head = reOrder(l1.head);
    l1.display();
}