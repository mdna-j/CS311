/**
 * Implementation of BST class.
 */
//You must complete the TODO parts and then complete LinkedList.cpp. Delete "TODO" after you are done.
//You should always comments to each function to describe its PURPOSE and PARAMETERS

// =======================================================
// Your name: ??? (TODO: Add your name)
// Compiler:  g++
// File type: cpp file BST.cpp
// @brief This class implements a BST search tree
//=======================================================

#include "BST.h"
#include <iostream>
#include <algorithm>
using namespace std;

/**
 * Implement the BST constructor
 */
BST::BST() {
    root = nullptr;
    numElements = 0;
}

/**
 * Implement the BST destructor
 */
BST::~BST() {
    // Must release memory correctly to avoid memory leaks
    clear();
}

/**
 * Implement size() correctly
 */
unsigned int BST::size() const {
    return numElements;
}

/**
 * Implement clear() correctly without memory leaks
 */
void BST::clear() {
    release(root);
    numElements = 0;
    root = nullptr;
}

void BST::release(Node *node) {
    if (node == nullptr) {
        return;
    }
    release(node->leftChild);
    release(node->rightChild);
    delete node;  // Free the current node
}

/**
 * Implement insert() correctly
 */
bool BST::insert(T element) {
    if (root == nullptr) {
        root = new Node(element);
        numElements++;  // Increment the number of elements when adding the first node
        return true;
    }

    Node *curr = root;
    while (true) {
        if (element < curr->data) {
            if (curr->leftChild == nullptr) {
                curr->leftChild = new Node(element);
                curr->leftChild->parent = curr;
                numElements++;  // Increment on successful insertion
                return true;
            } else {
                curr = curr->leftChild;
            }
        } else if (element > curr->data) {
            if (curr->rightChild == nullptr) {
                curr->rightChild = new Node(element);
                curr->rightChild->parent = curr;
                numElements++;  // Increment on successful insertion
                return true;
            } else {
                curr = curr->rightChild;
            }
        } else {
            return false;  // Element already exists, do nothing
        }
    }
    return false;
}

/**
 * Implement find() correctly
 */
bool BST::find(const T &query) const {
    Node *curr = root;
    while (curr != nullptr) {
        if (query == curr->data) {
            return true;
        } else if (query < curr->data) {
            curr = curr->leftChild;
        } else {
            curr = curr->rightChild;
        }
    }
    return false;
}

/**
 * Implement the height() function correctly
 */
int BST::height() const {
    return height(root);
}

int BST::height(Node *node) const {
    if (node == nullptr) {
        return -1;
    }
    return 1 + std::max(height(node->leftChild), height(node->rightChild));
}

/**
 * Implement the getRoot() function correctly
 */
BST::Node* BST::getRoot() {
    return root;
}

/**
 * Print the subtree at node using inorder traversal
 * @param node a pointer to node in BST
 */
void BST::printInorder(Node* node) {
    if (node == nullptr) {
        return;
    }
    printInorder(node->leftChild);
    std::cout << node->data << " ";
    printInorder(node->rightChild); 
}

/**
 * Print the subtree at node using preorder traversal
 * @param node a pointer to node in BST
 */
void BST::printPreorder(Node* node) {
    if (node == nullptr) {
        return;
    }
    std::cout << node->data << " ";
    printPreorder(node->leftChild);
    printPreorder(node->rightChild);
}

/**
 * Print the subtree at node using postorder traversal
 * @param node a pointer to node in BST
 */
void BST::printPostorder(Node* node) {
    if (node == nullptr) {
        return;
    }
    printPostorder(node->leftChild);
    printPostorder(node->rightChild);
    std::cout << node->data << " ";
}

/**
 * Implement the getLeftMostNode() function correctly
 */
BST::Node* BST::getLeftMostNode() {
    return getLeftMostNode(root);
}

BST::Node* BST::getLeftMostNode(BST::Node *node) {
    if (node == nullptr) {
        return nullptr;
    }
    while (node->leftChild != nullptr) {
        node = node->leftChild;
    }
    return node;  // Base case: return node when there's no left child
}

/**
 * Implement the BST successor function correctly
 */
BST::Node* BST::successor(Node *node) {
    if (node->rightChild != nullptr) {
        return getLeftMostNode(node->rightChild);
    } else {
        Node* parent = node->parent;
        while (parent != nullptr && node == parent->rightChild) {
            node = parent;
            parent = parent->parent;
        }
        return parent;  // Return parent if it's the successor
    }
}
