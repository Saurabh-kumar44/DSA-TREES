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
void solve(Node *root, int len, int &maxLen, int sum, int &maxSum){
    if(root == NULL){
        if(len > maxLen){
            maxLen = len;
            maxSum = sum;
        }
        else if(len == maxLen){
            maxSum = max(sum, maxSum);
        }
        return;
    }
    // cout<<maxSum<<" ";
    sum = sum + root->data;
    solve(root->left, len+1, maxLen, sum, maxSum);
    solve(root->right, len+1, maxLen, sum, maxSum);
}
void LongestPathSum(Node *root){
    int sum=0;
    int maxSum=INT_MIN;
    int len=0;
    int maxLen=INT_MIN;
    solve(root, len, maxLen, sum, maxSum);
    cout<<maxSum<<endl;
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

    cout<<"The Longest path sum is: "<<endl;
    LongestPathSum(root);
    



    return 0;
}
/* 

          20      Not Balanced
        /    \       Longest path sum is: 54
       8     22             
     /  \       \
    4     12     25
         /   \   
      10     14
*/   
   
   
   
   
    