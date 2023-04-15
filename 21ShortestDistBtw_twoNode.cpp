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

Node* LCA(Node *root, int n1, int n2){
    if(root == NULL){
        return NULL;
    }
    if(root->data == n1 || root->data == n2){
        return root;
    }
    Node *leftAns = LCA(root->left, n1, n2);
    Node *rightAns = LCA(root->right, n1, n2);

    if(leftAns != NULL && rightAns != NULL){
        return root;
    }
    else if(leftAns == NULL && rightAns != NULL){
        return rightAns;
    }
    else if(leftAns != NULL && rightAns == NULL){
        return leftAns;
    }
    else{
        return NULL;
    }
}
int findDis(Node *tempRoot, int k, int dis){
    if(tempRoot == NULL){
        return -1;
    }
    if(tempRoot->data == k){
        return dis;
    }

    int left = findDis(tempRoot->left, k, dis+1);
    if(left != -1){
        return left;
    }
    return findDis(tempRoot->right, k, dis+1);
}
void  distBtwnode(Node *root, int n1, int n2){
    Node *lca = LCA(root, n1,n2);
    int d1 = findDis(lca, n1, 0); //0 - initial(level=distance)
    int d2 = findDis(lca, n2, 0);

    cout<<d1+d2<<endl;
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

    cout<<"The Lowest common ancestor of 10 and 14 is: "<<endl;
    distBtwnode(root, 4, 14);
   

    return 0;
}
/* 

          20      LCA of 4 and 14 = 8
        /    \    Shortest distance = 3
       8     22             
     /  \       \
    4     12     25
         /   \   
      10     14
*/   
   
   
   
   
    