/*
id: 22011136
name:NUR FARHAH SOLEHAH
group: g3
lab: L6
*/

#include <iostream>
#include <string>
using namespace std;

// Node class represents each element in the queue
class Node {
public:
    string name;         // Stores the name (data)
    Node* next_ptr;      // Pointer to the next node in the queue

    // Constructor with default next_ptr set to nullptr
    Node(string name, Node* next_ptr = nullptr) {
        this->name = name;
        this->next_ptr = next_ptr;
    }
};

// Queue class using singly linked list logic
class Queue {
private:
    Node* front; // Points to the front of the queue
    Node* rear;  // Points to the rear of the queue

public:
    // Constructor initializes an empty queue
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Enqueue: Add a new node to the rear of the queue
    void enqueue(Node* node) {
        if (!node) return;

        node->next_ptr = nullptr; // Make sure new node doesn't point anywhere

        if (!front) {
            // If queue is empty
            front = rear = node;
        } else {
            // Link the new node to the rear and update rear
            rear->next_ptr = node;
            rear = node;
        }
    }

    // Dequeue: Remove node from the front of the queue
    void dequeue() {
        if (!front) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = front;
        cout << "Removing: " << temp->name << endl;
        front = front->next_ptr;

        if (!front) rear = nullptr; // If list becomes empty after dequeue

        delete temp;
    }

    // Display all elements in the queue from front to rear
    void display_queue() {
        if (!front) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* current = front;
        while (current) {
            cout << current->name << " <- ";
            current = current->next_ptr;
        }
        cout << "NULL" << endl;
    }

    // Getter for the front pointer (used for cleanup)
    Node* get_front() const {
        return front;
    }
};

// Main function to demonstrate queue operations
int main() {
    // Create nodes dynamically
    Node* node1 = new Node("Ali");
    Node* node2 = new Node("Ahmed");
    Node* node3 = new Node("Alee");
    Node* node4 = new Node("Abu");

    // Create queue and enqueue nodes
    Queue queue;
    queue.enqueue(node1);
    queue.enqueue(node2);
    queue.enqueue(node3);
    queue.enqueue(node4);

    // Display the queue
    cout << "Initial Queue:\n";
    queue.display_queue();

    // Dequeue example
    queue.dequeue();
    cout << "After Dequeue:\n";
    queue.display_queue();

    // Clean up dynamically allocated memory
    Node* current = queue.get_front();
    while (current) {
        Node* temp = current;
        current = current->next_ptr;
        delete temp;
    }

    return 0;
}
