/*
id: 22011136
name:NUR FARHAH SOLEHAH
group: g3
lab: L5
*/

#include <iostream>
#include <string>
using namespace std;

// Node class represents an element in the stack
class Node {
public:
    string name;         // Stores the data (name)
    Node* next_ptr;      // Pointer to the next node in the stack

    // Constructor with default next_ptr = nullptr
    Node(string name, Node* next_ptr = nullptr) {
        this->name = name;
        this->next_ptr = next_ptr;
    }
};

// Stack class using singly linked list logic
class Stack {
private:
    Node* top; // Pointer to the top of the stack

public:
    // Constructor initializes an empty stack or sets given top
    Stack(Node* top = nullptr) {
        this->top = top;
        if (top)
            top->next_ptr = nullptr;
    }

    // Push a new node onto the top of the stack
    void push(Node* node) {
        if (!node)
            return;

        node->next_ptr = top; // New node points to old top
        top = node;           // Update top to new node
    }

    // Pop the top element from the stack
    void pop() {
        if (!top) {
            cout << "Stack is empty" << endl;
            return;
        }

        Node* temp = top;
        top = top->next_ptr; // Move top to next node
        delete temp;         // Delete the popped node
    }

    // Return the value at the top without removing it
    string peek() const {
        if (!top) {
            cout << "Stack is empty" << endl;
            return "";
        }
        return top->name;
    }

    // Display all elements in the stack
    void display_stack() {
        Node* current = top;
        if (!current) {
            cout << "Stack is empty" << endl;
            return;
        }

        cout << "Stack: ";
        while (current != nullptr) {
            cout << current->name;
            current = current->next_ptr;
            if (current != nullptr)
                cout << " -> ";
        }
        cout << endl;
    }

    // Getter for the top node (used in cleanup)
    Node* get_top() const {
        return top;
    }

    // Check if the stack is empty
    bool is_empty() const {
        return top == nullptr;
    }
};

// Main function to demonstrate stack operations
int main() {
    // Create nodes dynamically
    Node* node1 = new Node("Papa");
    Node* node2 = new Node("Mama");
    Node* node3 = new Node("Pama");

    // Create a stack and push the nodes
    Stack stack;
    stack.push(node1);   // Stack: Papa
    stack.push(node2);   // Stack: Mama -> Papa
    stack.push(node3);   // Stack: Pama -> Mama -> Papa

    // Display the stack
    stack.display_stack();

    // Peek at the top element
    cout << "Top element: " << stack.peek() << endl;

    // Display stack again (unchanged by peek)
    cout << "Stack after peek: ";
    stack.display_stack();

    // Pop the top element (Pama)
    cout << "After popping top element: ";
    stack.pop();
    stack.display_stack();

    // Clean up remaining memory
    Node* current = stack.get_top();
    while (current) {
        Node* temp = current;
        current = current->next_ptr;
        delete temp;
    }

    return 0;
}
