#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        this->data  = x;
        this->left  = NULL;
        this->right = NULL;
    }
};

Node* buildTree(Node* root){
    int data;
    cin>>data;
    root = new Node(data);
    if(data == -1){
        return NULL;
    }
    cout<<"Enter data for inserting in left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for inserting in right of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}
void buildTreeFromLevelOrder(Node *&root){
    queue<Node*> q;
    int data;
    cout<<"Enter the data for root: "<<endl;
    cin>>data;
    root = new Node(data);
    q.push(root);
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        cout<<"Enter the left of "<<temp->data<<endl;
        int leftData,rightData;
        cin>>leftData;
        if(leftData != -1){
            temp->left = new Node(leftData); 
            q.push(temp->left);
        }

        cout<<"Enter the right of "<<temp->data<<endl;
        cin>>rightData;
        if(rightData != -1){
            temp->right = new Node(rightData); 
            q.push(temp->right);
        }
    }
}
void  printInorder(Node *root){
    if(root == NULL){
        return;
    }
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}
//Without specifiying level
// void printLevelOrder(Node *root){
//     queue<Node*> q;
//     q.push(root);
//     while(!q.empty()){
//         Node* node = q.front();                                 
//         q.pop();
//         cout<<node->data<<" ";  
//         if(node->left){
//             q.push(node->left);
//         }
//         if(node->right){
//             q.push(node->right);
//         }                                           
//     }
// }

//Specifying Level
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

int main()
{
    Node *root = NULL; 
    //1,3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout<<"Enter the Root:"<<endl;
    // root = buildTree(root);//Normal Tree building
    buildTreeFromLevelOrder(root);
    cout<<"The inorder Traversel is: ";
    printInorder(root);
    cout<<endl;
    cout<<"The levelOrder Traversel is: "<<endl;
    printLevelOrder(root);
    

    return 0;
}

/*
                  1
            /           \
          3              5
       /     \         /   \ 
      7       11       17   -1
     / \     /  \     /   \
   -1  -1  -1   -1  -1    -1
*/