// Given a binary tree, print boundary nodes of the binary tree Anti-Clockwise starting from the root.

//  The boundary includes 

// left boundary (nodes on left excluding leaf nodes)
// leaves (consist of only the leaf nodes)
// right boundary (nodes on right excluding leaf nodes)
// The left boundary is defined as the path from the root to the left-most node. The right boundary is defined as the path from the root to the right-most node. If the root doesn’t have left subtree or right subtree, then the root itself is left boundary or right boundary. Note this definition only applies to the input binary tree, and not apply to any subtrees.
// The left-most node is defined as a leaf node you could reach when you always firstly travel to the left subtree if it exists. If not, travel to the right subtree. Repeat until you reach a leaf node.
// The right-most node is also defined in the same way with left and right exchanged. 
// For example, boundary traversal of the following tree is “20 8 4 10 14 25 22”

// This is how we write the traversal:

// root : 20

// left- boundary nodes: 8

// leaf nodes: 4 10 14 25

// right – boundary nodes: 22 

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

void printLevelOrder(Node *root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* node = q.front();                                 
        q.pop();
        if(node != NULL){
            cout<<node->data<<" ";  
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }                                           
        }
        else if(!q.empty()){
            q.push(NULL);
            // cout<<endl;
        }
    }
}

void traverseLeft(Node *root, vector<int> &ans){
    if((root == NULL) || root->left == NULL && root->right == NULL){
        return;
    }
    ans.push_back(root->data);
    if(root->left){
        traverseLeft(root->left,ans);
    }
    else{
        traverseLeft(root->right,ans);
    }
}

void traverseLeaf(Node *root, vector<int> &ans){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
        return;
    }
    
    traverseLeaf(root->left,ans);
    traverseLeaf(root->right,ans);
}

void traverseRight(Node *root, vector<int> &ans){
    if((root == NULL) || root->left == NULL && root->right == NULL){
        return;
    }
    if(root->right){
        traverseRight(root->right, ans);
    }
    else{
        traverseRight(root->left, ans);
    }
    ans.push_back(root->data);
}

void boundary(Node *root){
    vector<int> ans;
    if(root == NULL){
        return;
    }
    // ans.push_back(root->data);

    traverseLeft(root, ans);

    //For leaf of left subtree
    traverseLeaf(root->left, ans);
    //For leaf of right subtree
    traverseLeaf(root->right, ans);

    traverseRight(root->right, ans);

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}


int main(){
    struct Node* root = new Node(20); 
    root->left = new Node(8);
    root->right = new Node(22);
    root->right->right = new Node(25);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    cout<<"Levelorder is: "<<endl;
    printLevelOrder(root);
    cout<<endl;

    cout<<"The boundary Nodes are: "<<endl;
    boundary(root);



    return 0;
}
/* 

          20      Not Balanced
        /    \       
       8     22             
      / \      \
     4   12     25
        /  \   
       10   14
*/   
   
   
   
   
    