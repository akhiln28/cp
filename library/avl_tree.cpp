/*
    title: avl_tree.cpp
    author: Akhil
    date: 2020-09-27
    time: 18:50:52
*/

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <numeric>
#include <cmath>
#include <stdio.h>

using namespace std;

struct avl_tree
{
    // a class for node
    struct node
    {
    public:
        int id, height; 
        node *left, *right; 
        // constructor
        node(int id)
        {
            this->id = id;
            left = nullptr;
            right = nullptr;
            height = 1;
        }
    };

    int getHeight(node *n){
        if(n != nullptr){
            return n->height;
        }
        return 0;    
    }

    int heightDiff(node *n){
        if(n != nullptr){
            return getHeight(n->left) - getHeight(n->right);
        }
        return 0;
    }


    node *leftRotate(node *x){
        node *y = x->right;
        node *T2 = y->left;

        // rotation
        x->right = T2;
        y->left = x;

        // update height
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        return y; 
    }

    node *rightRotate(node *y){
        node *x = y->left;
        node *T2 = x->right;

        // rotation
        y->left = T2;
        x->right = y;

        // update height
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        return x;
    }


    // insertion in AVL tree
    node *insert(node *root, int id){
        if(root == nullptr){
            root = new node(id);
            return root; 
        }
        else if(id > root->id)
        {
            // go to right sub tree
            root->right = insert(root->right, id);
        }
        else
        {
            // go to left sub tree
            root->left = insert(root->left, id);
        }
        // update height
        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        int diff = heightDiff(root);

        // left left case
        if(diff > 1 and (root->left and id < root->left->id)){
            return rightRotate(root);
        }
        // left right case
        if (diff > 1 and (root->left and id > root->left->id)){
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        // right right case
        if (diff < -1 and (root->right and id > root->right->id)){
            return leftRotate(root);
        }
        // right left case
        if (diff < -1 and (root->right and id < root->right->id)){
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        return root; 
    }

    node *root;
    avl_tree()
    {
        root = nullptr; 
    }
    void insert(int id)
    {
        root = insert(root, id); 
    }

    void inorder(node *root)
    {
        if (root == nullptr) return;
        inorder(root->left); 
        cout << root->id << " ";
        inorder(root->right); 
    }

    void inorder()
    {
        inorder(root); 
    }
};



int main(){
    avl_tree avl; 
    for (int i = 100; i > 0; i--)
    {
        avl.insert(i); 
    }
    avl.inorder(); cout << endl;
    return 0;
}