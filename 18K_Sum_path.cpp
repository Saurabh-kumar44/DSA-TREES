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

void solve(Node *root, int k, int &count, vector<int> &path){
    if(root == NULL){
        return;
    }
    path.push_back(root->data);

    solve(root->left, k, count, path);
    solve(root->right, k,count, path);

    int size = path.size();
    int sum=0;
    for(int i = size-1; i >= 0; i--){
        sum += path[i];
        if(sum == k){
            count++;
        }
    }
    path.pop_back();
    
}

int sumK(Node *root , int k){
    vector<int> path;
    int count = 0;
    solve(root, k, count, path);
    return count;
}

int main(){
    struct Node* root = new Node(1); 
    root->left = new Node(2);
    root->right = new Node(-1);
    root->left->left = new Node(1);
    root->left->right = new Node(2);
    root->right->left = new Node(3);
    root->right->left->left = new Node(2);
    root->right->left->right = new Node(5);

    cout<<"Levelorder is: "<<endl;
    printLevelOrder(root);
    cout<<endl;

    cout<<"Total paths sum equal to k is: "<<endl;
    cout<<sumK(root, 3)<<endl;
   

    return 0;
}
/* 

           1
        /     \
       2       -1
    /    \     /   
   1     2    3                             
            /  \                         
           2    5        
*/   
   
   
   
   
    