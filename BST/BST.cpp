/*Khyati Gupta*/
#include <iostream>
using namespace ::std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node *insert(Node *root, int k)
{
    if (root == NULL)
        return new Node(k);
    if (root->data > k)
        root->left = insert(root->left, k);
    if (root->data < k)
        root->right = insert(root->right, k);
    return root;
}

void takeInput(Node *root)
{
    cout << "Enter the tree and -1 to end" << endl;
    int num;
    while (true)
    {
        cin >> num;
        if (num == -1)
            break;
        else
            root = insert(root, num);
    }
    return;
}

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << ", ";
    inorder(root->right);
}

Node *search(Node *root, int k)
{
    if (root == NULL || root->data == k)
        return root;
    else if (root->data < k)
        return search(root->right, k);
    else if (root->data > k)
        return search(root->left, k);
}

// find min/ max() -> go extreme left or right


int main()
{
    Node *root = new Node(8);
    takeInput(root);
    inorder(root);
    cout << endl;
    search(root, 8) == NULL ? cout << -1 : cout << root->data << endl;
    return 0;
}

// 8 3 9 10 85 0 6 2 -1