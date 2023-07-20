#include <iostream>

// Binary Tree Node
template <typename T>
struct Node {
    T data;
    Node<T>* left;
    Node<T>* right;
};

// Binary Tree Class
template <typename T>
class BinaryTree {
private:
    Node<T>* root;

    // Private recursive function for inserting a node
    Node<T>* insertRecursive(Node<T>* currentNode, T newData) {
        if (currentNode == nullptr) {
            Node<T>* newNode = new Node<T>;
            newNode->data = newData;
            newNode->left = nullptr;
            newNode->right = nullptr;
            return newNode;
        }

        if (newData < currentNode->data) {
            currentNode->left = insertRecursive(currentNode->left, newData);
        }
        else {
            currentNode->right = insertRecursive(currentNode->right, newData);
        }

        return currentNode;
    }

    // Private recursive function for printing the tree in order
    void printInOrderRecursive(Node<T>* currentNode) {
        if (currentNode == nullptr) {
            return;
        }

        printInOrderRecursive(currentNode->left);
        std::cout << currentNode->data << " ";
        printInOrderRecursive(currentNode->right);
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    // Public function for inserting a node
    void insert(T newData) {
        root = insertRecursive(root, newData);
    }

    // Public function for printing the tree in order
    void printInOrder() {
        printInOrderRecursive(root);
        std::cout << std::endl;
    }
};

int main() {
    BinaryTree<int> bt;

    bt.insert(50);
    bt.insert(30);
    bt.insert(20);
    bt.insert(40);
    bt.insert(70);
    bt.insert(60);
    bt.insert(80);

    std::cout << "In Order: ";
    bt.printInOrder();

    return 0;
}
