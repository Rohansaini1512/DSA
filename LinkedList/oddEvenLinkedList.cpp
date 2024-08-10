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

Node* oddEvenLinkedList(Node* &head){
    Node* evenHead = head->next;
    Node* oddptr = head;
    Node* evenptr = evenHead;

    while(evenptr && evenptr->next){
        oddptr->next = oddptr->next->next;
        evenptr->next = evenptr->next->next;
        oddptr = oddptr->next;
        evenptr = evenptr->next;
    }
    oddptr->next = evenHead;
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

    l1.head = oddEvenLinkedList(l1.head);
    l1.display();
}