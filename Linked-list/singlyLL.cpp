#include <iostream>  // For input/output
using namespace std;

// Node class representing each node of the linked list
class Node {
    public:
    int data;   // Data stored in the node
    Node* next; // Pointer to the next node
    
    // Constructor to initialize node with data
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    // Destructor to free memory
    ~Node() {
        if (this->next != NULL) {
            delete next;  // Recursively delete the next nodes
            this->next = NULL;
        }
        cout << "Node with data " << data << " is deleted" << endl;
    }
};

// Function to insert a node at the head of the linked list
void insertAtHead(Node* &head, int d) {
    Node* temp = new Node(d);  // Create a new node
    temp->next = head;         // New node points to the current head
    head = temp;               // Update the head to the new node
}

// Function to insert a node at the tail of the linked list
void insertAtTail(Node* &tail, int d) {
    Node* temp = new Node(d);  // Create a new node
    tail->next = temp;         // Tail's next points to the new node
    tail = temp;               // Update the tail to the new node
}

// Function to insert a node at a specific position in the linked list
void insertAtPos(Node* &head, Node* &tail, int pos, int d) {
    // If inserting at the head position
    if (pos == 1) {
        insertAtHead(head, d);
        return;
    }
    
    Node* temp = head;   // Start traversal from the head
    int cnt = 1;         // Counter to track position
    
    // Traverse to the node just before the desired position
    while (cnt < pos-1 && temp != NULL) {
        temp = temp->next;  // Move to the next node
        cnt++;
    }

    // If inserting at the tail
    if (temp->next == NULL) {
        insertAtTail(tail, d);  // Call insertAtTail if we are at the last node
        return;
    }

    // Normal insertion at the given position
    Node* nodeToInsert = new Node(d);  // Create a new node
    nodeToInsert->next = temp->next;   // New node points to the next of current node
    temp->next = nodeToInsert;         // Current node's next points to the new node
}

// Function to delete a node at a specific position in the linked list
void deleteAtPos(Node* &head, Node* &tail, int pos) {
    // If deleting the first node (head)
    if (pos == 1) {
        Node* temp = head;
        head = head->next;   // Update head to the next node
        temp->next = NULL;   // Unlink the node from the list
        delete temp;         // Delete the node
    } 
    // Deleting nodes from other positions
    else {
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;

        // Traverse to the node at the desired position
        while (cnt < pos) {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;  // Link previous node to the next node
        curr->next = NULL;        // Unlink the current node
        delete curr;              // Delete the current node
    }
}

// Function to print the linked list
void print(Node* head) {
    Node* temp = head;   // Start from the head
    while (temp != NULL) {   // Traverse till the end of the list
        cout << temp->data << " ";  // Print the data of the current node
        temp = temp->next;          // Move to the next node
    }
    cout << endl;  // Print newline after all nodes are printed
}

int main() {
    // Create the first node with data 10
    Node* node1 = new Node(10);
    
    // Initialize both head and tail to point to the first node
    Node* head = node1;
    Node* tail = node1;
    
    // Print the initial list
    print(head);  // Output: 10
    
    // Insert 12 at the head
    insertAtHead(head, 12);
    print(head);  // Output: 12 10
    
    // Insert 8 at the tail
    insertAtTail(tail, 8);
    print(head);  // Output: 12 10 8
    
    // Insert 9 at position 2
    insertAtPos(head, tail, 2, 9);
    print(head);  // Output: 12 9 10 8
    
    // Delete the node at position 3
    deleteAtPos(head, tail, 3);
    print(head);  // Output: 12 9 8

    // Deleting the remaining list and releasing memory
    delete head;

    return 0;
}
