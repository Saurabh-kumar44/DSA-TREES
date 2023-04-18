#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;

        Node(int d){
            this->data = d;
            this->left = NULL;
            this->right = NULL;
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
            cout<<endl;
        }
    }
}

Node *insertIntoBST(Node *root, int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }
    if(data > root->data){
        root->right = insertIntoBST(root->right, data);
    }
    else{
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}

void takeInput(Node *&root){
    int data;
    cin>>data;

    while(data != -1){
        root = insertIntoBST(root, data);
        cin>>data;
    }
}
int main(){
    Node *root = NULL;
    cout<<"Enter the data to create to BST:"<<endl;
    takeInput(root);

    cout<<"Levelorder of BST is: "<<endl;
    printLevelOrder(root);
    cout<<endl;
}

/*
           10      BST- binary search Tree
         /    \    
        8      34            
       /  \    /  \
     5    9  22   65
*/