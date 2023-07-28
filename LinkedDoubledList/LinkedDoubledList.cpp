#include <iostream>
#include "DLL.hpp"

// Doubly Linked List Node

int main() {
    DoublyLinkedList<int> dll;
    std::cout << "Select Menu :"<< std::endl;
    std::cout << "1. Insert"<< std::endl;
    std::cout << "2. Print"<< std::endl;
    std::cout << "3. Delete" << std::endl;

    
    dll.insertAtBeginning(5);
    dll.insertAtBeginning(4);
    dll.insertAtEnd(6);
    dll.insertAtEnd(7);
    dll.insertAtBeginning(10);

    std::cout << "Forward: ";
    dll.printForward();

    std::cout << "Backward: ";
    dll.printBackward();

    dll.Delete(5);

    dll.printForward();

    return 0;
}
