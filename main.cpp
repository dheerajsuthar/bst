#include <iostream>
#include "BST.h"

int main() {
    int arr[] = {7, 3, 11, 1, 5, 9, 13, 4, 6, 8, 12, 14};
    BST bst;

    for (int i: arr) {
        bst.insert(i);
    }

    bst.print(Order::LevelOrder);
    for (int i: arr) {
        bst.remove(i);
        bst.print(Order::LevelOrder);

    }

    return 0;
}