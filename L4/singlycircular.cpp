/*
id: 22011136
name: nur farhah solehah
group: g3
lab: L4
*/

#include <iostream>
#include <string>
using namespace std;

// Node class represents each node in the circular singly linked list
class Node {
public:
    string name;         // Stores the name
    Node* next_ptr;      // Points to the next node

    // Constructor with default next_ptr set to nullptr
    Node(string name, Node* next_ptr = nullptr) {
        this->name = name;
        this->next_ptr = next_ptr;
    }
};

// LinkedList class handles insertion, deletion, display, and cleanup
class LinkedList {
private:
    Node* head; // Points to the first node
    Node* tail; // Points to the last node

public:
    // Constructor initializes an empty list
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Insert a new node with given name into the circular list
    void insert_node_by_name(string name) {
        Node* new_node = new Node(name); // Create new node

        if (!head) {
            // If list is empty, new node becomes both head and tail
            head = tail = new_node;
            new_node->next_ptr = head; // Point to itself to make it circular
        } else {
            // Insert at the end and update tail
            tail->next_ptr = new_node;
            tail = new_node;
            tail->next_ptr = head; // Maintain circular link
        }
    }

    // Delete a node from the list by value (name)
    void delete_node_by_value(string name) {
        if (!head) return; // List is empty

        Node* current = head;
        Node* previous = tail;
        bool found = false;

        // Search for the node to delete
        do {
            if (current->name == name) {
                found = true;
                break;
            }
            previous = current;
            current = current->next_ptr;
        } while (current != head);

        if (!found) return; // Name not found

        if (head == tail && head->name == name) {
            // Case: Only one node
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            // Relink to bypass the node
            previous->next_ptr = current->next_ptr;

            // Update head or tail if needed
            if (current == head) head = current->next_ptr;
            if (current == tail) tail = previous;

            delete current;
        }
    }

    // Display the list content from head onward
    void display_list() {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }

        Node* current = head;
        do {
            cout << current->name << " -> ";
            current = current->next_ptr;
        } while (current != head);
        cout << "head (" << head->name << ")" << endl;
    }

    // Getter for head node
    Node* get_head() const {
        return head;
    }

    // Getter for tail node
    Node* get_tail() const {
        return tail;
    }
};

// Main function to test the LinkedList class
int main() {
    LinkedList std_names;

    // Insert three nodes
    std_names.insert_node_by_name("Papa");
    std_names.insert_node_by_name("Mama");
    std_names.insert_node_by_name("Pama");

    // Display the list before deletion
    cout << "Before delete:\n";
    std_names.display_list();

    // Delete node with name "Alice"
    std_names.delete_node_by_value("Mama");

    // Display the list after deletion
    cout << "\nAfter delete:\n";
    std_names.display_list();

    // Cleanup: delete all dynamically allocated nodes
    Node* head = std_names.get_head();
    Node* tail = std_names.get_tail();

    if (head) {
        Node* current = head->next_ptr;
        while (current != head) {
            Node* temp = current;
            current = current->next_ptr;
            delete temp;
        }
        delete head;
    }

    return 0;
}
