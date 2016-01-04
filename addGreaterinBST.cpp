#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* newNode(int key) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void printTree(TreeNode* root) {
    if (!root) return; // base case
    printTree(root->left);
    cout<<root->val<<" ";
    printTree(root->right);
}

void reverseInorder(TreeNode* root, int &sum) {
    if (!root) return; // base case
    reverseInorder(root->right, sum);
    sum+=root->val;
    root->val = sum;
    reverseInorder(root->left, sum);
}

void addGreater(TreeNode* root) {
    int sum = 0;
    reverseInorder(root, sum);
}

int main() {
    TreeNode* root = newNode(6);
    root->left = newNode(2);
    root->left->left = newNode(1);
    root->left->right = newNode(4);
    root->left->right->left = newNode(3);
    root->left->right->right = newNode(5);
    root->right = newNode(7);
    addGreater(root);
    printTree(root);
    getchar();
}