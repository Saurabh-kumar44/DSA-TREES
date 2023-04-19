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

Node *deleteFromBST(Node *root, int k){
    // base case
    if (root == NULL)
    {
        return root;
    }
    if (root->data == k){
        // 0 child
        if (root -> left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        // 1 child
        //left child
        if(root->left  != NULL && root->right == NULL){
            Node *temp = root->left;
            delete root;
            return temp;
        }
        //right child
        if(root->left  == NULL && root->right != NULL){
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // 2 child
        if(root->right != NULL && root->left !=NULL){
            int minV = minValue(root->right)->data;
            root->data = minV;
            root->right = deleteFromBST(root->right , minV);
            return root;
        }
    }
        else if (root->data > k){
            root->left = deleteFromBST(root->left, k);
            // return root;
        }
        else{
            root->right = deleteFromBST(root->right, k);
            // return root;
        }
        return root;
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

    deleteFromBST(root, 4);

    cout << "Levelorder after Deletion: " << endl;
    printLevelOrder(root);
    cout << endl;

    return 0;
}
/*

          4
         /  \
        2    5
       /  \   \
      1    3   6
*/
