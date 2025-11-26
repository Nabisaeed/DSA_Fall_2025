// Tree - Binery Search Tree
#include <iostream>
using namespace std;

// Node Class
class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data=value;
        left=right=NULL;
    }
};

// Insert a node into the BST
Node* insert(Node* root, int value) {
    if (root == NULL) return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Find the minimum value node in the BST
Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Delete a node from the BST
Node* deleteNode(Node* root, int value) {
    if (root == NULL) return root;

    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Pre-order Traversal
void preOrderTraversal(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// In-order Traversal
void inOrderTraversal(Node* root) {
    if (root == NULL) return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

// Post-order Traversal
void postOrderTraversal(Node* root) {
    if (root == NULL) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

// Example usage
int main() {
    Node* root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);
//
//    root = insert(root, 113);
//    root = insert(root, 100);
//    root = insert(root, 121);
//    root = insert(root, 60);
//    root = insert(root, 101);
//    root = insert(root, 186);
//    root = insert(root, 13);
//    root = insert(root, 67);
//    root = insert(root, 108);
//    root = insert(root, 171);
    
//    root = insert(root, 50);
//    root = insert(root, 25);
//    root = insert(root, 15);
//    root = insert(root, 10);
//    root = insert(root, 20);
//    root = insert(root, 25);
//    root = insert(root, 35);
//    root = insert(root, 45);
//    root = insert(root, 75);
//    root = insert(root, 65);
//    root = insert(root, 85);
//    root = insert(root, 95);
    
//    root = insert(root, 11);
//    root = insert(root, 8);
//    root = insert(root, 19);
//    root = insert(root, 6);
//    root = insert(root, 10);
//    root = insert(root, 4);
//    root = insert(root, 7);
//    root = insert(root, 43);
//    root = insert(root, 31);
//    root = insert(root, 29);
//    root = insert(root, 37);
//    root = insert(root, 49);

    cout << "In-order Traversal: ";
    inOrderTraversal(root);
    cout << endl;
    cout << "Pre-order Traversal: ";
    preOrderTraversal(root);
    cout << endl;
    cout << "Post-order Traversal: ";
    postOrderTraversal(root);
    cout << endl;

    root = deleteNode(root, 50);

    cout << "In-order Traversal after deletion: ";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}

