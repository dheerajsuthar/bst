//
// Created by Dheeraj Suthar on 2019-03-01.
//

#ifndef BST_NODE_H
#define BST_NODE_H


class Node {
public:
    int data;
    int depth;
    Node *parent;
    Node *left;
    Node *right;

    explicit Node(int data,
                  int depth = 0,
                  Node *parent = nullptr,
                  Node *left = nullptr,
                  Node *right = nullptr) : data(data), depth(depth), parent(parent), left(left), right(right) {}

};


#endif //BST_NODE_H
