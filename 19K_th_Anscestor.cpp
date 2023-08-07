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

void solve(Node *root, int k, int n, vector<int> &res){
    if(root == NULL){
        return;
    }
    if(root->data == n){
        res.push_back(root->data);
        cout<<res[res.size()-k-1]<<endl;
    }
    res.push_back(root->data);
    solve(root->left, k, n, res);
    solve(root->right, k, n, res);
 
    res.pop_back();
}

void k_th_Ansector(Node *root , int k, int n){
    vector<int> res;
    int count = 0;
    solve(root, k, n, res);
}

int main(){
    struct Node* root = new Node(1); 
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);

    cout<<"Levelorder is: "<<endl;
    printLevelOrder(root);
    cout<<endl;

    cout<<"The 2nd Ancestor of 6 is: "<<endl;
    k_th_Ansector(root, 2, 6);
   

    return 0;
}
/* 

          1
        /  \
       2    3
     /   \       
    4     5                                 
         /  \                         
        6    7        
*/   
   
   
   
   
    