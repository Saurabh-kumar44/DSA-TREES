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

int checkIfSame(Node *root1, Node *root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    if(root1 == NULL && root2 != NULL){
        return false;
    }
    if(root2 == NULL && root1 !=NULL)
    {
    return false;
    } 
    bool ifEqualLeft = checkIfSame(root1->left , root2->left); 
    bool ifEqualRight = checkIfSame(root1->right , root2->right);

    bool checkValue = root1->data == root2->data;

    if(ifEqualLeft && ifEqualRight && checkValue){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    struct Node* root1 = new Node(1); 
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->right->left = new Node(6);
    root1->right->right = new Node(7);

    struct Node* root2 = new Node(1); 
    root2->left = new Node(2);
    root2->right = new Node(3);

    root2->left->left = new Node(4);
    root2->left->right = new Node(5);

    root2->right->left = new Node(6);
    root2->right->right = new Node(7);
    // root2->right->right->left = new Node(8);

    cout<<"The two trees are: "<<endl;
    cout<<checkIfSame(root1, root2)<<endl;

    return 0;
}

/* root1    
          1         hieght = 4         
        /   \   
       2     3             
      / \   / \
     4   5 6   7                   
 
 root1    1         hieght = 4         
        /   \   
       2     3             
      / \   / \
     4   5 6   7            
*/