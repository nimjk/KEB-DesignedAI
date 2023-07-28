#pragma once

template <typename T>
struct Node {
    T data;
    Node<T>* prev;
    Node<T>* next;
};

// Doubly Linked List Class
template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
public:
    DoublyLinkedList() {
        head = nullptr;
    }

    // Insert a node at the beginning of the list
    void insertAtBeginning(T newData) {
        Node<T>* newNode = new Node<T>;
        newNode->data = newData;
        newNode->prev = nullptr;
        newNode->next = head;

        if (head != nullptr) {
            head->prev = newNode;
        }

        head = newNode;
    }

    // Insert a node at the end of the list
    void insertAtEnd(T newData) {
        Node<T>* newNode = new Node<T>;
        newNode->data = newData;
        newNode->next = nullptr;

        if (head == nullptr) {
            newNode->prev = nullptr;
            head = newNode;
            return;
        }

        Node<T>* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = newNode;
        newNode->prev = current;
    }

    // Print the list in forward direction
    void printForward() {
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Print the list in reverse direction
    void printBackward() {
        Node<T>* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }

        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->prev;
        }
        std::cout << std::endl;
    }

    void Delete(T intData) {
        Node<T>* current = head; 

        if (current->data == intData) {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete(current);
        }
        else{
            current = current->next;
        }

        
    }
};