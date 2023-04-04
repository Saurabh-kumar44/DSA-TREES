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
void topView(Node *root){
    vector<int> ans;
    map<int,int> topNode;//<horizontal distance, node->data>
    queue<pair<Node*, int>> q;// <node, horizontal distance>
    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        q.pop();
        Node *frontNode = temp.first;
        int hd = temp.second;

        //maintaining 1-1 mapping(if one value is present for horizontal mapping the do nothing) 
        if(topNode.find(hd) == topNode.end()){
            topNode[hd] = frontNode->data;
        }

        if(frontNode->left){
            q.push(make_pair(frontNode->left,hd-1));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right,hd+1));
        }
    }
    for(auto i: topNode){
        ans.push_back(i.second);
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
}

void bottomView(Node *root){
    vector<int> ans;
    map<int,int> topNode;//<horizontal distance, node->data>
    queue<pair<Node*, int>> q;// <node, horizontal distance>
    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        q.pop();
        Node *frontNode = temp.first;
        int hd = temp.second;

        topNode[hd] = frontNode->data;

        if(frontNode->left){
            q.push(make_pair(frontNode->left,hd-1));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right,hd+1));
        }
    }
    for(auto i: topNode){
        ans.push_back(i.second);
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
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

    cout<<"The Top view is: "<<endl;
    topView(root);
    cout<<"The Bottom view is: "<<endl;
    bottomView(root);
   



    return 0;
}
/* 

          20      Not Balanced
        /    \       
       8     22             
     /  \       \
    4     12     25
         /   \   
      10     14
*/   
   
   
   
   
    