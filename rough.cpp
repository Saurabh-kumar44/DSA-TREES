#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;
        Node (int x){
            this->data = x;
            this->left = NULL;
            this->right = NULL;
        }
};

void levelOrder(Node *root){
    queue<Node*> q;
    int level = 0;
    vector<vector<int> > arr;
    vector<int> temp;
    // if(root==NULL){
    //   return arr;  
    // }
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* node = q.front();                                 
        q.pop();
        if(node != NULL){ 
            temp.push_back(node->data);
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }                                           
        }
        else if(!q.empty()){
            q.push(NULL);
            level++;
            arr.push_back(temp);
            temp.clear();
        }
    }
    arr.push_back(temp);
    cout<<"TempL "<<endl;
    for(int i=0; i<temp.size(); i++){
        cout<<temp[i]<<" ";
    }
    cout<<endl;
    cout<<"ANS: "<<endl;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}


int main()
{
	struct Node* root = new Node(1); 
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);

    root->right->right->left = new Node(10);
    root->right->right->right = new Node(11);

    

	cout << "Level Order traversal of binary tree is: "<<endl;
	levelOrder(root);

return 0;
}

/* 
          1       L=0
        /   \
       2     3    L=1
      / \   / \ 
     4   5 6   7  L=2

*/