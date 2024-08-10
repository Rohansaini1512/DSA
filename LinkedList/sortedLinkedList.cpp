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

Node* sortedLinkedList(Node* &head1 , Node* &head2){
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    Node* mergedLinkedList = new Node(-1);
    Node* ptr3 = mergedLinkedList; 
    while(ptr1 && ptr2){
        if(ptr1->val > ptr2->val){
            ptr3->next = ptr2; 
            ptr2 = ptr2->next;
        }else{
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }
        ptr3 = ptr3->next;
    }
    while(ptr1){
        ptr3->next = ptr1;
        ptr1 = ptr1->next;
        ptr3 = ptr3->next;
    }
    while(ptr2){
        ptr3->next = ptr2;
        ptr2 = ptr2->next;
        ptr3 = ptr3->next;
    }

    return mergedLinkedList->next;
}

Node* mergeKLinkedList(vector<Node*> &lists){
    if(lists.size() == 0){
        return NULL;
    }
    while(lists.size() > 1){
        Node* mergedHead = sortedLinkedList(lists[0], lists[1]);
        lists.push_back(mergedHead);
        lists.erase(lists.begin());
        lists.erase(lists.begin());
    }
    return lists[0];
}

int main(){

    LinkedList l1;
    l1.insertAtTail(2);
    l1.insertAtTail(4);
    l1.insertAtTail(6);
    l1.display();

    LinkedList l2;
    l2.insertAtTail(1);
    l2.insertAtTail(3);
    l2.insertAtTail(4);
    l2.insertAtTail(5);
    l2.display();

    LinkedList l3;
    l3.head = sortedLinkedList(l1.head , l2.head);
    l3.display();
}