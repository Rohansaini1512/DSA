#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int data) {
        val = data;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    void insertAtTail(int value) {
        Node* new_node = new Node(value);
        if (head == NULL) {
            head = new_node;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

void reArrangement(Node* &head, int k) {
    if (!head || k == 0) return;

    int n = 1;
    Node* ptr1 = head;
    while (ptr1->next) {
        n++;
        ptr1 = ptr1->next;
    }

    k = k % n;
    if (k == 0) return;

    int x = 1;
    Node* ptr2 = head;
    while (x != n - k) {
        x++;
        ptr2 = ptr2->next;
    }

    Node* new_head = ptr2->next;
    ptr2->next = NULL;
    ptr1->next = head;
    head = new_head;
}

int main() {
    LinkedList l1;
    l1.insertAtTail(1);
    l1.insertAtTail(2);
    l1.insertAtTail(3);
    l1.insertAtTail(4);
    l1.insertAtTail(5);
    l1.insertAtTail(6);
    l1.display();

    reArrangement(l1.head, 3);
    l1.display();
}
