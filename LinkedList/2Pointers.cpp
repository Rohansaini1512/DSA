#include<bits/stdc++.h>

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

bool Pointer(Node* head1, Node* head2) {
    Node* temp1 = head1;
    Node* temp2 = head2;
    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->val != temp2->val) {
            return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return (temp1 == NULL && temp2 == NULL);
}

int getLength(Node* head) {
    Node* temp = head;
    int length = 0;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
}

Node* moveHeadByK(Node*& head, int k) {
    Node* ptr = head;
    while (k--) {
        ptr = ptr->next;
    }
    return ptr;
}

int findIntersect(Node* head1, Node* head2) {
    int l1 = getLength(head1);
    int l2 = getLength(head2);
    Node* ptr1;
    Node* ptr2;
    if (l1 > l2) {
        int k = l1 - l2;
        ptr1 = moveHeadByK(head1, k);
        ptr2 = head2;
    } else {
        int k = l2 - l1;
        ptr2 = moveHeadByK(head2, k);
        ptr1 = head1;
    }

    while (ptr1 && ptr2) {
        if (ptr1 == ptr2) {
            return ptr1->val;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return -1; // No intersection found
}

int main() {
    LinkedList l1, l2;
    l1.insertAtTail(1);
    l1.insertAtTail(2);
    l1.insertAtTail(3);
    l1.insertAtTail(4);
    l1.insertAtTail(5);
    l1.insertAtTail(6);
    l1.display();

    l2.insertAtTail(10);
    l2.insertAtTail(20);
    l2.insertAtTail(30);
    l2.insertAtTail(44);
    l2.insertAtTail(5);
    l2.insertAtTail(8);
    l2.display();

    cout << "Are lists identical? " << (Pointer(l1.head, l2.head) ? "Yes" : "No") << endl;
    int intersectValue = findIntersect(l1.head, l2.head);
    if (intersectValue != -1) {
        cout << "Intersecting Node value: " << intersectValue << endl;
    } else {
        cout << "No intersection found." << endl;
    }

    return 0;
}
