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

bool cycleDetct(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            cout<<slow->val<<endl;
            return true;
        }
    }
    return false;
};

void removeCycle(Node* &head){
    Node* slow = head;
    Node* fast = head;

    do{
        slow = slow->next;
        fast = fast->next->next;
    }while(slow!=fast);

    fast = head;
    while(slow->next != fast->next){
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = NULL;
    cout<<endl;
};

int main(){

    LinkedList l1;
    l1.insertAtTail(1);
    l1.insertAtTail(2);
    l1.insertAtTail(3);
    l1.insertAtTail(4);
    l1.insertAtTail(5);
    l1.insertAtTail(6);
    l1.insertAtTail(7);
    l1.insertAtTail(8);
    l1.head->next->next->next->next->next->next = l1.head->next->next->next;
    // l1.display();

    cout<<cycleDetct(l1.head)<<endl;
    removeCycle(l1.head);
    cout<<cycleDetct(l1.head)<<endl;
    l1.display();
}