#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int n)
    {
        data = n;
        left = NULL;
        right = NULL;
    }
};

void printLevelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        if (node != NULL)
        {
            cout << node->data << " ";
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        else if (!q.empty())
        {
            q.push(NULL);
            // cout<<endl;
        }
    }
}

Node *minValue(Node *root){
    Node *temp = root;

    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}
Node *maxValue(Node *root){
    Node * temp = root;

    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}


int main()
{
    struct Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->right->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    cout << "Levelorder is: " << endl;
    printLevelOrder(root);
    cout << endl;

    cout<<"The min value of BST is: "<<endl;
    cout<<minValue(root)->data<<endl;
    cout<<"Then max value of BST is: "<<endl;
    cout<<maxValue(root)->data<<endl;

    return 0;
}
/*

          4
         /  \
        2    5
       /  \   \
      1    3   6
*/
