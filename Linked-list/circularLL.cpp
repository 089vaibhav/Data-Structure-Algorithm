#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int d) {
        this->data = d;
        this->next = NULL;
    }
    ~Node() {
        int value = this->data;
        if (this->next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "Memory is freed for node with data " << value << endl;
    }
};

void insertNode(Node* &tail, int ele, int d) {
    if (tail == NULL) {
        Node* newNode  = new Node(d);
        tail = newNode;
        newNode->next = newNode;  
    } 
    else {
        Node* curr = tail;
        while (curr->data != ele) {
            curr = curr->next;
            if (curr == tail) {
                cout << "Element not found in the list." << endl;
                return;
            }
        }
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
        if (curr == tail) {
            tail = temp;
        }
    }
}

void del(Node* &tail, int val){
    if(tail==NULL){
        cout<<"list is empty"<<endl;
    }
    else{
        Node* prev = tail;
        Node* curr = prev->next;

        while(curr->data!=val){
            curr = curr->next;
            prev=prev->next;
        }
        prev->next = curr->next;
        if(curr == prev) {
            tail = NULL;
        }
        else if(tail == curr ) {
            tail = prev;
        }

        curr -> next = NULL;
        delete curr;
    }
}

void print(Node* tail) {
    if (tail == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = tail;
    do {
        cout << temp->next->data << " ";  
        temp = temp->next;
    } while (temp != tail);
    cout << endl;
}

bool detectLoop(Node* head) {
    if (head == NULL || head->next == NULL) {
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;        // Move slow by 1 step
        fast = fast->next->next;  // Move fast by 2 steps

        if (slow == fast) {
            return true;  // Loop detected
        }
    }
    
    return false;  // No loop
}


bool isCircularList(Node* head) {
    if(head == NULL) {
        return true;
    }

    Node* temp = head -> next;
    while(temp != NULL && temp != head ) {
        temp = temp -> next;
    }

    if(temp == head ) {
        return true;
    }

    return false;

}

int main() {
    Node* node1 = new Node(10);
    Node* tail = node1;
    node1->next = node1; 

    print(tail);

    insertNode(tail, 10, 20);
    insertNode(tail, 20, 30);
    insertNode(tail, 30, 40);
    del(tail, 40);
    print(tail);
    cout<<tail->data<<endl;

    if(isCircularList(tail)) {
        cout << " Linked List is Circular in nature" << endl;
    }
    else{
        cout << "Linked List is not Circular " << endl;
    }
    
    return 0;
}
