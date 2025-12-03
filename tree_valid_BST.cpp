#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int Max(node* root)
{
    if(root == NULL)
    {
        return INT_MIN;
    }
    return max(root->data, max(Max(root->left), Max(root->right)));
}
void valid_BST(node* root)
{
    if(root == NULL)
    {
        return;
    }
    if(root->data > Max(valid_BST(root->left)) && root->data < Max(valid_BST(root->right)))
    {
        cout << "Valid\n";
        return;
    }
    cout << "Invalid\n";
}

int main()
{
    node* a = new node(1);
    node* b = new node(2);
    node* c = new node(3);
    node* d = new node(4);
    node* e = new node(5);
    node* f = new node(6);
    node* g = new node(7);
    node* h = new node(8);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    f->right = h;

    cout << Max(a);
    cout << "\n";
    valid_BST(a);
}