/*
id: 22011136
name: nur farhah solehah
group: g3
lab: L4
*/

#include <iostream>
#include <string>
using namespace std;

// Node class represents each element in the doubly circular linked list
class Node {
public:
    string name;         // Stores the name (data)
    Node* next;          // Pointer to the next node
    Node* prev;          // Pointer to the previous node

    // Constructor initializes node with name and optional pointers
    Node(string name, Node* next = nullptr, Node* prev = nullptr) {
        this->name = name;
        this->next = next;
        this->prev = prev;
    }
};

// Class to manage operations on a doubly circular linked list
class DoublyCircularList {
private:
    Node* head; // Pointer to the head (first node)
    Node* tail; // Pointer to the tail (last node)

public:
    // Constructor initializes empty list
    DoublyCircularList() {
        head = nullptr;
        tail = nullptr;
    }

    // Function to insert node at the end based on given name
    void insert_node_by_name(string name) {
        Node* new_node = new Node(name); // Create a new node

        if (head == nullptr) {
            // Case: List is empty
            head = tail = new_node;
            head->next = head;
            head->prev = head;
        } else {
            // Case: List has elements
            new_node->next = head;
            new_node->prev = tail;
            tail->next = new_node;
            head->prev = new_node;
            tail = new_node; // Update tail to the new node
        }
    }

    // Function to delete a node based on name
    void delete_node_by_value(string name) {
        if (!head) return; // Case: List is empty

        Node* current = head;
        do {
            if (current->name == name) {
                // Node found with matching name
                if (current == head && current == tail) {
                    // Case: Only one node in the list
                    delete current;
                    head = nullptr;
                    tail = nullptr;
                    return;
                } else {
                    // Case: Multiple nodes in the list
                    current->prev->next = current->next;
                    current->next->prev = current->prev;

                    if (current == head)
                        head = current->next; // Update head if needed
                    if (current == tail)
                        tail = current->prev; // Update tail if needed

                    delete current;
                    return;
                }
            }
            current = current->next;
        } while (current != head); // Traverse until full circle
    }

    // Function to display list contents from head to tail
    void display_list() {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }

        Node* current = head;
        do {
            cout << current->name << endl;
            current = current->next;
        } while (current != head); // Stop when we circle back to head
    }

    // Getter for head node (used for cleanup)
    Node* get_head() {
        return head;
    }
};

// Main function to test the DoublyCircularList
int main() {
    DoublyCircularList std_names;

    // Inserting nodes into the list
    std_names.insert_node_by_name("Papa");
    std_names.insert_node_by_name("Mama");
    std_names.insert_node_by_name("Pama");

    // Display list before deletion
    cout << "Before delete:" << endl;
    std_names.display_list();

    // Delete a node by value
    std_names.delete_node_by_value("Mama");

    // Display list after deletion
    cout << "\nAfter delete:" << endl;
    std_names.display_list();

    // Clean up memory (manually delete nodes)
    if (std_names.get_head()) {
        Node* current = std_names.get_head();
        Node* start = current;
        do {
            Node* temp = current;
            current = current->next;
            delete temp;
        } while (current != start); // Stop when full circle is completed
    }

    return 0;
}
