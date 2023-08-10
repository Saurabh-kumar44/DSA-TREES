// #include<bits/stdc++.h>
// using namespace std;

// class Node{
//     public:
//         int data;
//         Node *left;
//         Node *right;
//     Node(int x){
//         data=x;
//         left=NULL;
//         right=NULL;
//     }
// };

// Node* buildTree(Node *root){
//     int x;
//     cin>>x;
//     root = new Node(x);
//     if(x == -1){
//         return NULL;
//     }
//     cout<<"Enter the left of "<<x<<endl;
//     root->left = buildTree(root->left);
//     cout<<"Enter the right of "<<x<<endl;
//     root->right = buildTree(root->right);

//     return root;
// }

// void buildLevelOrder(Node *&root){
//     queue<Node*> q;
//     int data;
//     cin>>data;
//     root = new Node(data);
//     q.push(root);
//     while(!q.empty()){
//         Node *temp = q.front();
//         q.pop();
//         cout<<"ENter the left of "<<temp->data<<endl;
//         int leftData, rightData;
//         cin>>leftData;
//         if(leftData!=-1){
//             temp->left = new Node(leftData);
//             q.push(temp->left);
//         }
//         cout<<"Enter the right of "<<temp->data<<endl;
//         cin>>rightData;
//         if(leftData!=-1){
//             temp->right = new Node(rightData);
//             q.push(temp->right);
//         }
//     }
// }

// void levelOrder(Node *&root){
//     queue<Node*> q;
//     q.push(root);
//     q.push(NULL);
//     while(!q.empty()){
//        Node *temp = q.front();
//        q.pop();
//        if(temp!=NULL){
//             cout<<temp->data<<" ";
//             if(temp->left){
//                     q.push(temp->left);
//             }
//             if(temp->right){
//                     q.push(temp->right);
//             }
//        }
//        else if(!q.empty()){
//         q.push(NULL);
//         cout<<endl;
//        }

//     }
// }

// void inorder(Node *root){
//     if(root==NULL){
//         return;
//     }
//     inorder(root->left);
//     cout<<root->data<<" ";
//     inorder(root->right);
// }

// int main()
// {
//     Node* root = NULL;
//     cout<<"Enter the root"<<endl;
//     // root = buildTree(root);
//     buildLevelOrder(root);
//     cout<<"Inorder traversal"<<endl;
//     inorder(root);
//     cout<<"Level ORder"<<endl;
//     levelOrder(root);
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;


int main()
{
      int x = 10;

  int y = 20;

  x = y++;

  cout << x << endl;

  return 0;

    return 0;
}