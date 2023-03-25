//Level order traversal 
//k th level sum

#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *left, *right;

    Node(int n){
        this->data = n;
        this->left = NULL;
        this->right = NULL;
    }
};

void inorderPrint(Node *root){
    if(root == NULL){
        return;
    }
    inorderPrint(root->left);
    if(root->left==NULL && root->right==NULL){
        cout<<root->data<<" ";
    }
    inorderPrint(root->right);
}

/* 
          1       L=0
        /   \
       2     3    L=1
      / \   / \ 
     4   5 6   7  L=2

*/

int main()
{
	struct Node* root = new Node(1); 
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

	cout << "The leaf Node are: ";
    inorderPrint(root);
	return 0;
}

/* 
          1       L=0
        /   \
       2     3    L=1
      / \   / \ 
     4   5 6   7  L=2

*/