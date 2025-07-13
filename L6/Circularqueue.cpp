/*
id: 22011136
name:NUR FARHAH SOLEHAH
group: g3
lab: L6
*/

#include <iostream>
#include <string>
using namespace std;

// Node class represents an element in the circular queue
class Node {
public:
    string name;         // Stores the name
    Node* next_ptr;      // Pointer to the next node

    // Constructor with default next_ptr
    Node(string name, Node* next_ptr = nullptr) {
        this->name = name;
        this->next_ptr = next_ptr;
    }
};

// Queue class using circular singly linked list
class Queue {
private:
    Node* front; // Pointer to front node (head)
    Node* rear;  // Pointer to rear node (tail)

public:
    // Constructor initializes an empty queue
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Add a node to the end of the queue
    void enqueue(Node* node) {
        if (!node)
            return;

        if (!front) {
            // If queue is empty
            front = rear = node;
            node->next_ptr = front; // Circular link
        } else {
            rear->next_ptr = node;
            rear = node;
            rear->next_ptr = front; // Maintain circular connection
        }
    }

    // Remove a node from the front of the queue
    void dequeue() {
        if (!front) {
            cout << "Queue is empty" << endl;
            return;
        }

        if (front == rear) {
            // Only one element
            cout << "Removing: " << front->name << endl;
            delete front;
            front = nullptr;
            rear = nullptr;
        } else {
            // More than one node
            Node* temp = front;
            cout << "Removing: " << temp->name << endl;
            front = front->next_ptr;
            rear->next_ptr = front; // Maintain circular link
            delete temp;
        }
    }

    // Display queue from front to rear
    void display_queue() {
        if (!front) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* current = front;
        do {
            cout << current->name << " <- ";
            current = current->next_ptr;
        } while (current != front);

        cout << "Front (" << front->name << ")" << endl;
    }

    // Get the front pointer for cleanup
    Node* get_front() const {
        return front;
    }
};

int main() {
    // Create nodes dynamically
    Node* node1 = new Node("Ali");
    Node* node2 = new Node("Ahmed");
    Node* node3 = new Node("Alee");
    Node* node4 = new Node("Abu");

    // Create queue and add nodes
    Queue queue;
    queue.enqueue(node1);
    queue.enqueue(node2);
    queue.enqueue(node3);
    queue.enqueue(node4);

    // Display the queue
    cout << "Queue content:" << endl;
    queue.display_queue();

    // Dequeue one element
    queue.dequeue();

    // Display queue after dequeue
    cout << "\nQueue after one dequeue:" << endl;
    queue.display_queue();

    // Clean up memory
    Node* front = queue.get_front();
    if (front) {
        Node* current = front->next_ptr;
        while (current != front) {
            Node* temp = current;
            current = current->next_ptr;
            delete temp;
        }
        delete front;
    }

    return 0;
}
