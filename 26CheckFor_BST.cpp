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

bool isBST(Node *root , Node *min, Node *max){
    if(root == NULL){
        return true;
    }
    if(min != NULL && root->data <= min->data){
        return false;
    }
    if(max != NULL && root->data >= max->data){
        return false;
    }

    bool leftValid = isBST(root->left, min, root);
    bool rightValid = isBST(root->right,root, max);
    return leftValid and rightValid;

}

int main()
{
    struct Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->right->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    cout << "Levelorder Before is: " << endl;
    printLevelOrder(root);
    cout << endl;

    if(isBST(root, NULL, NULL)){
        cout<<"It is a BST"<<endl;
    }
    else{
        cout<<"Not a BST"<<endl;
    }

    return 0;
}
/*

          4
         /  \
        2    5
       /  \   \
      1    3   6
*/
