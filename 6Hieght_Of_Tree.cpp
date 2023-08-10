#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int n){
        data = n;
        left = NULL;
        right = NULL;
    }
};

void inOrder(struct Node* root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

int hieghtOfTree(struct Node *root){
    if(root == NULL){
        return 0;
    }
    int leftHieght  = hieghtOfTree(root->left);
    // cout<<" "<<root->data<<" ";
    int rightHieght = hieghtOfTree(root->right);
    
    int ans = max(leftHieght, rightHieght)+1;


    return ans;
}


int main(){
    struct Node* root = new Node(1); 
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    root->left->left->left  = new Node(10);
    root->left->left->right = new Node(11);

    cout<<"Inorder is: "<<endl;
    inOrder(root);
    cout<<endl;
    cout<<"The height of the Tree is: "<<endl;
    cout<<hieghtOfTree(root)<<endl;

    return 0;
}

/* 
          1         hieght = 4
        /   \
       2     3             
      / \   / \
     4   5 6   7
    / \ 
   10  11
*/