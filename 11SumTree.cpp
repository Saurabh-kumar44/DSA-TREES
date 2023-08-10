//Given a binary tree. Return true if, for every node X in the tree other than leaves, its value is equal to the sum of its left subtree's value and its right subtree's value else return false
/*  ex:
          3       
        /   \      3 = 1+2  
       1     2             

          26
        /    \      
       10     3
     /    \     \
    4      6      3
*/

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

pair<bool,int> isSumTreeFast(Node* root) {
    if(root == NULL) {
        pair<bool,int> p = make_pair(true, 0);
        return p;
    }
    if(root->left == NULL && root->right == NULL ) {
        // cout<<"d:"<<root->data<<" ";
        pair<bool,int> p = make_pair(true, root->data);
        return p;
    }
    pair<bool,int> leftAns = isSumTreeFast(root->left);
    pair<bool,int> rightAns = isSumTreeFast(root->right);
    
    bool isLeftSumTree = leftAns.first;
    bool isRightSumTree = rightAns.first;
    
    int leftSum = leftAns.second;
    int rightSum = rightAns.second;
    
    bool condn = root->data == leftSum + rightSum;
    
    pair<bool, int> ans;
    if(isLeftSumTree && isRightSumTree && condn) {
        ans.first = true;
        ans.second = root->data + leftSum + rightSum ;
        // ans.second = root->data + leftAns.second + rightAns.second;
    }
    else
    {
        ans.first = false;
    }
    return ans;
        
    }
bool isSumTree(Node* root){
    return isSumTreeFast(root).second;
}

int main(){
    struct Node* root = new Node(3); 
    root->left = new Node(1);
    root->right = new Node(2);

    cout<<"Levelorder is: "<<endl;
    printLevelOrder(root);
    cout<<endl;
 
    cout<<"The Tree is SumTree? "<<endl;
    cout<<isSumTree(root)<<endl;
    

    return 0;
}
