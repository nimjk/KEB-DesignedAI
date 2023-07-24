#include <iostream>
#include "bitree.hpp"

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
