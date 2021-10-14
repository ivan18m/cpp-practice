/**
 * @file tree_traversal.cpp
 * @author Ivan Mercep
 * @brief
 * This program contains_
 * Binary Tree traversal methods: preorder, inorder, postorder.
 * Functions to print and swap the binary tree.
 * @version 0.1
 * @date 2021-09-06
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>

struct Node
{
    int data;
    Node *left;
    Node *right;
};

// <root> <left> <right>
void preorder(Node *pRoot)
{
    if (pRoot == nullptr)
        return;

    std::cout << pRoot->data << " ";
    preorder(pRoot->left);
    preorder(pRoot->right);
}

// <left> <root> <right>
void inorder(Node *pRoot)
{
    if (pRoot == nullptr)
        return;

    inorder(pRoot->left);
    std::cout << pRoot->data << " ";
    inorder(pRoot->right);
}

// <left> <right> <root>
void postorder(Node *pRoot)
{
    if (pRoot == nullptr)
        return;

    postorder(pRoot->left);
    postorder(pRoot->right);
    std::cout << pRoot->data << " ";
}

Node *getNewNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

Node *insert(Node *pRoot, int data)
{
    if (pRoot == nullptr)
        pRoot = getNewNode(data);
    else if (data <= pRoot->data)
        pRoot->left = insert(pRoot->left, data);
    else
        pRoot->right = insert(pRoot->right, data);
    return pRoot;
}

Node *swap(Node *pRoot)
{
    if (pRoot == nullptr)
        return pRoot;
    Node *temp = pRoot->left;
    pRoot->left = pRoot->right;
    pRoot->right = temp;

    swap(pRoot->left);
    swap(pRoot->right);
    return pRoot;
}

int main()
{
    Node *root = nullptr;
    root = insert(root, 15);
    root = insert(root, 20);
    root = insert(root, 25);
    root = insert(root, 18);
    root = insert(root, 1);

    /*
        15
        /\
       1  20
          /\
        18  25
    */

    inorder(root);
    std::cout << "\n";

    swap(root);

    inorder(root);
    std::cout << "\n";

    delete root;
    return 0;
}