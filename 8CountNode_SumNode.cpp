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
int countNode(Node *root){
    if(root == NULL){
        return 0;
    }
    return countNode(root->left) + countNode(root->right) + 1;
}
int sum=0;
int sumNode(Node *root){
    if(root == NULL){
        return 0;
    }
    // return sumNode(root->left) + sumNode(root->right) + root->data;
         //OR
    int left = sumNode(root->left);
    int right = sumNode(root->right);
    int sum = left + right + root->data;
    // cout<<sum<<" ";
    return sum;


}

int main(){
    struct Node* root = new Node(1); 
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->right = new Node(10);

    root->left->left->left  = new Node(8);
    root->left->left->left->left  = new Node(11);
    root->left->left->right = new Node(9);


    cout<<"Levelorder is: "<<endl;
    printLevelOrder(root);
    cout<<endl;
    cout<<"The no. of nodes is: "<<endl;
    cout<<countNode(root)<<endl;
    cout<<"The sum of Nodes is: "<<endl;
    cout<<sumNode(root)<<endl;
    

    return 0;
}
/* 
          1         hieght = 4
        /   \       diameter = 8 (11-8-4-2-1-3-7-10)
       2     3             
      / \   / \
     4   5 6   7
    / \         \
   8   9         10
  /
 11

*/