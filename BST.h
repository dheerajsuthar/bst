//
// Created by Dheeraj Suthar on 2019-03-01.
//

#ifndef BST_BST_H
#define BST_BST_H

#include <utility>
#include <iostream>
#include <iomanip>
#include <deque>
#include "Node.h"

typedef std::pair<bool, Node *> SearchResult;

enum Order {
    PreOrder,
    InOrder,
    PostOrder,
    LevelOrder
};

class BST {
public:
    Node *root;

    BST() : root(nullptr) {

    }

    SearchResult find(const int data);

    void insert(const int data);

    void inorder(const Node *);

    void levelOrder(std::deque<const Node *> &, std::deque<const Node *> &);

    void print(Order = Order::InOrder);

    void remove(const int data);

    void splice(Node *target);


};


#endif //BST_BST_H
