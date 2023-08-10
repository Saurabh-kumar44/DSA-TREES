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

// 1
//Here for searching the postion in in order O(n) time taking
int inorderPos(int inorder[], int start, int end, int curr){
    for(int i=0; i<=end; i++){
        if(inorder[i]==curr){
            return i;
        }
    }
    return -1;
}

Node* buildTree(int preorder[], int inorder[], int start, int end){
    static int idx = 0;
    if(start > end){
        return NULL;
    }
    int curr = preorder[idx];
    idx++;
    Node *root = new Node(curr);        
    if(start == end){
        return root;
    }
    int pos = inorderPos(inorder, start, end, curr);
    root->left  = buildTree(preorder, inorder, start, pos-1);
    root->right = buildTree(preorder, inorder, pos+1,end);

    return root;
}
void inorderPrint(Node *root){
    if(root == NULL){
        return;
    }
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

//2
// void inorderPos(int inorder[], int end, map<int, int> &nodeToIndex){
//     for(int i=0; i<=end; i++){
//         nodeToIndex[inorder[i]] = i;
//     }
// }

// Node* buildTree(int preorder[], int inorder[], int start, int end, map<int,int> &nodeToIndex){
//     static int idx = 0;
//     if(start > end){
//         return NULL;
//     }
//     int curr = preorder[idx];
//     idx++;
//     Node *root = new Node(curr);
//     if(start == end){
//         return root;
//     }
//     int pos = nodeToIndex[curr];
//     root->left  = buildTree(preorder, inorder, start, pos-1,nodeToIndex);
//     root->right = buildTree(preorder, inorder, pos+1, end, nodeToIndex);

//     return root;
// }
// void inorderPrint(Node *root){
//     if(root == NULL){
//         return;
//     }
//     inorderPrint(root->left);
//     cout<<root->data<<" ";
//     inorderPrint(root->right);
// }

int main(){
    int preorder[] = {1,2,4,3,5};
    int inorder[] =  {4,2,1,5,3};

    // map<int ,int> nodeToIndex;//2
    // inorderPos(preorder,4,nodeToIndex);//2
    // map<int, int>::iterator it = nodeToIndex.begin();//2
    // while(it!=nodeToIndex.end()){
    //     cout<<it->first<<" "<<it->second<<endl;
    //     it++;
    // }
    //Build Tree
    // Node *root = buildTree(preorder,inorder,0,4,nodeToIndex);//2
    Node *root = buildTree(preorder,inorder,0,4);
    cout<<"The corresponding Inorder from preorder Tree is: ";
    inorderPrint(root);
    cout<<endl;


    return 0;
}