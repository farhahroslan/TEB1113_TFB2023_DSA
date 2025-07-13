/*
id: 22011136
name:NUR FARHAH SOLEHAH
group: g3
lab: L7
*/

#include <iostream>
using namespace std;

// Node class represents each node in the binary tree
class Node {
public:
    string name;              // Data stored in the node
    Node* left = nullptr;     // Pointer to left child
    Node* right = nullptr;    // Pointer to right child

    // Constructor initializes the node with a name
    Node(string n) : name(n) {}
};

// Tree class manages binary tree structure and operations
class Tree {
public:
    Node* root = nullptr;     // Pointer to the root of the tree

    // Function to add root node
    void add_root(const string& name) {
        root = new Node(name);
    }

    // Function to add a left child to a parent node
    void add_left(Node* parent, const string& name) {
        if (parent) parent->left = new Node(name);
    }

    // Function to add a right child to a parent node
    void add_right(Node* parent, const string& name) {
        if (parent) parent->right = new Node(name);
    }

    // Function to display the tree structure
    void display_tree() const {
        if (!root) return;  // Exit if tree is empty
        cout << "Root: " << root->name << endl;
        cout << "Left child of root: " << root->left->name << endl;
        cout << "Right child of root: " << root->right->name << endl;
        cout << "Left child of " << root->left->name << ": " << root->left->left->name << endl;
        cout << "Right child of " << root->left->name << ": " << root->left->right->name << endl;
        cout << "Left child of " << root->right->name << ": " << root->right->left->name << endl;
        cout << "Right child of " << root->right->name << ": " << root->right->right->name << endl;
    }
};

int main() {
    Tree tree;

    tree.add_root("A");                                   // Add root node A
    tree.add_left(tree.root, "B");                        // Add B as left child of A
    tree.add_right(tree.root, "C");                       // Add C as right child of A
    tree.add_left(tree.root->left, "D");                  // Add D as left child of B
    tree.add_right(tree.root->left, "E");                 // Add E as right child of B
    tree.add_left(tree.root->right, "F");                 // Add F as left child of C
    tree.add_right(tree.root->right, "G");                // Add G as right child of C

    tree.display_tree();                                  // Display the tree structure

    return 0;
}
