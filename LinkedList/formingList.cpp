#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int val;
    Node* next;

    Node(int data){
        val = data;
        next = NULL;
    }
};

void insertAtHead(Node* &head , int val){
    Node* new_node = new Node(val);
    new_node->next = head;
    head = new_node;
}

void insertAtTail(Node* &head , int val){
    Node* new_node = new Node(val);
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_node;
}

void insertAtKth(Node* &head , int k , int val){
    Node* new_node = new Node(val);
    Node* temp = head;
    int curr_pos = 0;

    if(k==0){
        insertAtHead(head , val);
    }

    while(curr_pos != k-1){
        temp = temp->next;
        curr_pos++;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

void updateAtKth(Node* &head , int k , int val){
    Node* temp = head;
    int curr_pos = 0;
    while(curr_pos != k){
        temp = temp->next;
        curr_pos ++;
    }
    temp->val = val;

}

void deleteAtStart(Node* &head){
    Node* temp = head;
    head = head->next;
    free(temp);
}

void deleteAtTail(Node* &head){
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    Node* last = temp->next;
    temp->next = NULL;
    free(last);
}

void deleteAtKth(Node* &head , int k){
    int curr_pos = 0;
    Node* pos = head;

    if(k == 0){
        deleteAtStart(head);
    }
    while(curr_pos != k-1){
        pos = pos->next;
        curr_pos ++;
    }
    Node* temp = pos->next;
    pos->next = pos->next->next;
    free(temp);
}

void deleteAlternate(Node* &head){
    Node* curr = head;

    while(curr != NULL && curr->next != NULL){
        Node* temp = curr->next;
        curr->next = temp->next;
        free(temp);
        curr = curr->next;
    }
}

void display(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->val<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){

    Node* head = NULL;
    insertAtHead(head , 1);
    // display(head);
    insertAtHead(head , 2);
    // display(head);
    insertAtHead(head , 3);
    // display(head);
    insertAtTail(head , 5);
    insertAtTail(head , 6);
    display(head);
    insertAtKth(head , 2 , 7);
    display(head);
    updateAtKth(head , 3 , 10);
    display(head);
    // deleteAtStart(head);
    // display(head);
    // deleteAtTail(head);
    // display(head);
    // deleteAtKth(head , 2);
    // display(head);
    deleteAlternate(head);
    display(head);
    
    return 0;
}