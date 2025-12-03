#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node* left;
    node* right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
}

node* search_in_BST(node* root, int val)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root->data == val)
    {
        return root;
    }
    else if(root->data < val)
    {
        search_in_BST(root->right, val);
    }
    else
    {
        search_in_BST(root->left, val);
    }
}
int main()
{

}