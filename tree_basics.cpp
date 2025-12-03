#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node*left;
    node*right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
void display(node* root)
{
    if(root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    display(root->left);
    display(root->right);
}
int sum(node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int x = root->data + sum(root->right) + sum(root->left);
    return x;
}
int size(node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    return 1 + size(root->left) + size(root->right);
}
int max_size(node* root)
{
    if(root == NULL)
    {
        return INT_MIN;
    }
    return max(root->data, max(max_size(root->left), max_size(root->right)));
}
int level(node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    return 1 + max(level(root->left), level(root->right)); 
}
int main()
{
    node* a = new node(1);
    node* b = new node(2);
    node* c = new node(3);
    node* d = new node(40);
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
    node* root = a;
    // int x = 0;
    display(root);
    cout << "\n";
    // sum(root,&x);
    cout << "the sum is : << " << sum(root) << "\n";
    cout << "The size is : " << size(root) << "\n";
    cout << "The max is : " << max_size(root) << "\n";
    cout << "The level is : " << level(root) << "\n";
}