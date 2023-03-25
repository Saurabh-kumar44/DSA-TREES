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
// // //Time complexity = O(n^2) //1
// int hieghtOfTree(struct Node *root){
//     if(root == NULL){
//         return 0;
//     }
//     int leftHieght  = hieghtOfTree(root->left);
//     int rightHieght = hieghtOfTree(root->right);
    
//     int ans = max(leftHieght, rightHieght)+1;

//     return ans;
// }
// // //Time complexity = O(n^2) //1
// bool isBalanceTree(Node *root){
//     if(root == NULL){
//         return true;
//     }
//     bool lh = isBalanceTree(root->left);
//     bool rh = isBalanceTree(root->right);
//     bool diff = abs(hieghtOfTree(root->left)-hieghtOfTree(root->right)) <=1;
//     if(lh && rh && diff){
//         return true;
//     }
//     else{
//         return false;
//     }
// }

        //OR
//Time complexity = O(n) Optimized //2 
// first = boolean and second = height
pair<bool , int> isBalanceFast(Node *root){
    if(root == NULL){
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    pair<bool, int> left = isBalanceFast(root->left);
    pair<bool, int> right = isBalanceFast(root->right);

    bool leftAns = left.first;
    bool rightAns = left.first;
    bool diff = abs(left.second - right.second) <=1;

    pair<bool, int> ans;
    ans.second = max(left.second , right.second) + 1;
    if(leftAns && rightAns && diff){
        ans.first = true;
    }
    else{
        ans.first = false;
    }
    return ans;
}
int isBalanceTree(Node *root){
    return isBalanceFast(root).first;
}

            
int main(){
    struct Node* root = new Node(1); 
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->left->left->left = new Node(6);

    cout<<"Levelorder is: "<<endl;
    printLevelOrder(root);
    cout<<endl;

    cout<<"The Tree is: ";
    cout<<isBalanceTree(root);
    cout<<endl;




    return 0;
}
/* 
          1      
        /   \   Balanced      
       2     3             
      / \   
     4   5 

          1      Not Balanced
        /   \       
       2     3             
      / \   
     4   5 
    /
   6
*/   
   
   
   
   
    