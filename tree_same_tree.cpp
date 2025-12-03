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

bool same_tree(node* p, node* q)
{
    if(p == NULL && q == NULL)
    {
        return 1;
    }
    else if(p == NULL || q == NULL)
    {
        return false;
    }
    if(p->data != q->data)
    {
        return false;
    }
    same_tree(p->left, q->left);
    same_tree(p->right, q->right);

    return true;
}
node* invert(node* root)
{
    if(root == NULL)
    {
        return NULL;
    }
    node* temp = invert(root->right);
    root->right = invert(root->left);
    root->left = temp;
    return root;
}
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

    display(a);
    cout << "\n";
    a = invert(a);
    display(a);
}