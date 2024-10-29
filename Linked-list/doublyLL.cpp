#include<iostream> 
using namespace std;

// Node class representing each element of the doubly linked list
class Node {
    public:
    int data;        // Data contained in the node
    Node* prev;     // Pointer to the previous node
    Node* next;     // Pointer to the next node

    // Constructor to initialize a node with given data
    Node(int d) {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

     // Destructor to free the memory of the node
    ~Node() {
        // No specific action needed here since we're managing memory at the list level
    }
};

// Function to insert a new node at the head of the list
void insertAtHead(Node* &head, Node* &tail, int d) {
    Node* temp = new Node(d);  // Create a new node
    temp->next = head;          // Link new node to the current head
    if (head != NULL) {         // If the list is not empty
        head->prev = temp;      // Set the previous pointer of the old head
    } else {
        tail = temp;            // If the list is empty, update the tail
    }
    head = temp;                // Update the head to the new node
}

// Function to insert a new node at the tail of the list
void insertAtTail(Node* &tail, int d) {
    Node* temp = new Node(d);  // Create a new node
    temp->prev = tail;          // Set the previous pointer to the current tail
    if (tail != NULL) {         // If the list is not empty
        tail->next = temp;      // Link the current tail to the new node
    }
    temp->next = NULL;          // The new node will be the last node
    tail = temp;                // Update the tail to the new node
}

// Function to insert a new node at a specific position
void insertAtPos(Node* &head, Node* &tail, int pos, int d) {
    if (pos == 1) {             // If inserting at the head
        insertAtHead(head, tail, d);
        return;
    }
    
    Node* temp = head;
    int cnt = 1;

    // Traverse to the position before where we want to insert
    while (cnt < pos - 1 && temp != NULL) {
        temp = temp->next;
        cnt++;
    }

    // If we're inserting at the end of the list
    if (temp->next == NULL) {
        insertAtTail(tail, d);
        return;
    }

    // Create the new node and adjust pointers to insert it
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;  // Link the new node to the next node
    temp->next->prev = nodeToInsert;   // Link the next node back to the new node
    temp->next = nodeToInsert;          // Link the current node to the new node
    nodeToInsert->prev = temp;          // Set the previous pointer of the new node
}

// Function to delete a node at a specific position
void del(Node* &head, Node* &tail, int pos) {
    if (pos == 1) {  // If deleting the head
        Node* temp = head;      // Store the current head
        head = temp->next;      // Move the head pointer to the next node
        if (head != NULL) {     // If the list is not empty after deletion
            head->prev = NULL;   // Update the previous pointer of the new head
        } else {
            tail = NULL;         // If the list becomes empty, update the tail
        }
        temp->next = NULL;       // Clear the next pointer of the deleted node
        delete temp;             // Free the memory of the deleted node
    } else {
        Node* curr = head;
        int cnt = 1;

        // Traverse to the position of the node to be deleted
        while (cnt < pos && curr != NULL) {
            curr = curr->next;
            cnt++;
        }

        if (curr != NULL) {       // If the node is found
            if (curr->next == NULL) { // If it's the last node
                tail = curr->prev; // Update the tail
                tail->next = NULL; // Set the next pointer of the new tail to NULL
            } else {
                curr->prev->next = curr->next; // Link the previous node to the next node
                curr->next->prev = curr->prev;   // Link the next node back to the previous node
            }
            curr->next = curr->prev = NULL; // Clear pointers of the deleted node
            delete curr;             // Free the memory of the deleted node
        }
    }
}

// Function to print the entire list
void print(Node* &head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " "; // Print node data
        temp = temp->next;          // Move to the next node
    }
    cout << endl; // New line after printing all nodes
}

// Main function to demonstrate the linked list operations
int main() {
    Node* node1 = new Node(10); // Create the first node
    Node* head = node1;         // Initialize head pointer
    Node* tail = node1;         // Initialize tail pointer

    print(head);                // Print initial list

    insertAtHead(head, tail, 12); // Insert at head
    print(head);                // Print after insertion

    insertAtTail(tail, 14);     // Insert at tail
    print(head);                // Print after insertion

    insertAtPos(head, tail, 2, 13); // Insert at position 2
    print(head);                // Print after insertion

    insertAtPos(head, tail, 1, 22); // Insert at position 1
    print(head);                // Print after insertion

    del(head, tail, 5);         // Delete node at position 5
    print(head);                // Print after deletion

    cout << "Head: " << head->data << " & Tail: " << tail->data << endl; // Print head and tail data

    return 0; // End of program
}
