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

// //Time complexity = O(n^2) //1
// int diameterOfTree(Node *root){
//     if(root == NULL){
//         return 0;
//     }
//     int lDia = diameterOfTree(root->left);
//     int rDia = diameterOfTree(root->right);
//     int currDia = hieghtOfTree(root->left) + hieghtOfTree(root->right)+1;

//     int dia = max(lDia, max(rDia,currDia));

//     return dia;
// }

            // OR
// Time complexity = O(n) //2 Optimized
// int diameterOfTree(Node *root, int *hieght){
//     if(root==NULL){
//         *hieght = 0;
//         return 0;
//     }

//     int lh=0, rh=0;
//     int lDiameter = diameterOfTree(root->left, &lh);
//     int rDiameter = diameterOfTree(root->right, &rh);

//     int currDia = lh + rh + 1;
//     *hieght = max(lh, rh) + 1;

//     return max(currDia, max(lDiameter,rDiameter));
// }

            //OR
//Time complexity = O(n) //3 Optimized
// int ans = 0;
// int hieght(Node *root){
//     if(root == NULL){
//         return 0;
//     }
//     int lh = hieght(root->left);
//     int rh = hieght(root->right);
//     ans = max(ans, lh+rh+1);

//     return 1 + max(lh, rh);
// }
// int diameterOfTree(Node *root){
//     int data = hieght(root);

//     return ans;
// }

//Time complexity = O(n) //4 Optimized

// first = diameter , second = hieght
pair<int, int> diameterFast(Node *root){
    if(root == NULL){
        pair<int , int> p = make_pair(0,0);
        return p;
    }
    pair<int, int> left = diameterFast(root->left);   //contain diameter
    pair<int, int> right = diameterFast(root->right);

    int op1 = left.first; //it consist diameter
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(op1, max(op2 , op3));
    ans.second = max(left.second , right.second) + 1;

    return ans;
}

int diameterOfTree(Node *root){
    return diameterFast(root).first;
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
    // cout<<"The hieght of the Tree is: "<<endl;
    // cout<<hieghtOfTree(root)<<endl;
    cout<<"The diameter of the Tree is: ";
    // cout<<diameterOfTree(root)<<endl;//1

    //Optimized 2
    // int hieght=0;
    // cout<<diameterOfTree(root,&hieght)<<endl;

    //Optimized 3
    // cout<<diameterOfTree(root);
    // cout<<endl;

    // Optimized 4
    cout<<diameterOfTree(root);
    cout<<endl;




    return 0;
}
/* 
          1         hieght = 5
        /   \       diameter = 8 (11-8-4-2-1-3-7-10)
       2     3             
      / \   / \
     4   5 6   7
    / \         \
   8   9         10
  /
 11

*/