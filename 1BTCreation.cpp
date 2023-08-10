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

vector<int> arr;
int order(struct Node* root){
        if(root==NULL){
            return 0;
        }
        else{
            order(root->left);
            arr.push_back(root->data);
            // cout<<root->data<<" "; 
            order(root->right);        
        }
        return arr;
}

int main(){
    struct Node* root = new Node(1); 
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    cout<<order(root);

    return 0;
}

/* 
          1
        /   \
       2     3
      / \   / \
     4   5 6   7

*/