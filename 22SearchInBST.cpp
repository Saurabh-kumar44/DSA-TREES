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

//Here searching taking O(log(n))
Node *searchInBST(Node *root , int k){
    if(root == NULL){
        return NULL;
    }
    if(root->data == k){
        return root;
    }
    if(root->data > k){
        Node* left = searchInBST(root->left, k);
        return left;
    }
    else{
        Node* right = searchInBST(root->right, k);
        return right;
    }
}


int main(){
    struct Node* root = new Node(4); 
    root->left = new Node(2);
    root->right = new Node(5);
    root->right->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    cout<<"Levelorder is: "<<endl;
    printLevelOrder(root);
    cout<<endl;

    Node *temp = searchInBST(root, 6);
    if(temp==NULL){
        cout<<"Key doesn't exist"<<endl;
    }
    else{
        cout<<"Key is present"<<endl;
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
   
   
   
   
    