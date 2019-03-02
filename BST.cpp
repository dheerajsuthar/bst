//
// Created by Dheeraj Suthar on 2019-03-01.
//


#include "BST.h"

static void d(std::string s) {
//    std::cout << "debug: " << s << std::endl;
}

SearchResult BST::find(const int data) {
    Node *current, *parent;
    current = parent = root;
    while (current) {
        if (current->data == data) {
            return std::make_pair(true, current);
        } else if (current->data > data) {
            parent = current;
            current = current->left;
        } else {
            parent = current;
            current = current->right;
        }
    }

    if (root) return std::make_pair(false, parent);
    else return std::make_pair(false, nullptr);
}

void BST::insert(const int data) {
    SearchResult searchResult = find(data);
    Node *parent = searchResult.second;
    if (!searchResult.first && !parent) root = new Node(data);
    else if (!searchResult.first) {
        parent->data > data ? parent->left = new Node(data, parent->depth + 1, parent) :
                parent->right = new Node(data, parent->depth + 1, parent);
    }
}

void BST::inorder(const Node *current) {
    if (current) {
        inorder(current->left);
        std::cout << std::setw(10) << current->data;
        inorder(current->right);
    }
}

void BST::levelOrder(std::deque<const Node *> &q, std::deque<const Node *> &res) {
    if (q.size() > 0) {
        const Node *current = q.front();
        if (current->left) q.push_back(current->left);
        if (current->right) q.push_back(current->right);
        res.push_back(current);
        q.pop_front();
        levelOrder(q, res);
    }

}

void BST::print(Order order) {
    if (!root) {
        std::cout << "Tree empty!" << std::endl;
        return;
    }
    switch (order) {
        case Order::InOrder: {
            inorder(root);
            break;
        }
        case Order::LevelOrder: {
            std::deque<const Node *> q;
            std::deque<const Node *> res;
            q.push_back(root);
            levelOrder(q, res);
            for (auto &node: res) {
                std::cout << std::setw(10) << node->data << "("
                          << (node->parent ? node->parent->data : -1) << ")";
            }
            break;
        }
        default:
            inorder(root);
    }
    std::cout << std::endl;
}

void BST::remove(const int data) {
    SearchResult searchResult = find(data);
    if (searchResult.first) {
        Node *target = searchResult.second;

        if (target->left && target->right) {
            Node *current = target;
            target = target->left;
            while (target->right) target = target->right;
            current->data = target->data;
        }

        splice(target);
    }

}

void BST::splice(Node *target) {
    if (!target->left && !target->right) {
        if (target->parent) {
            if (target->parent->left == target) {
                target->parent->left = nullptr;
            } else {
                target->parent->right = nullptr;
            }
        }
        if (target == root) root = nullptr;
    } else if (!target->right) {
        if (target->parent) {
            if (target->parent->left == target) {
                target->parent->left = target->left;
            } else {
                target->parent->right = target->left;
            }
        }
        target->left->parent = target->parent;
        if (target == root) root = target->left;
    } else if (!target->left) {
        if (target->parent) {
            if (target->parent->left == target) {
                target->parent->left = target->right;
            } else {
                target->parent->right = target->right;
            }
        }
        target->right->parent = target->parent;
        if (target == root) root = target->right;
    }
    delete target;
}