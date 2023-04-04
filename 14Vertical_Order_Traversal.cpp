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
void verticalOrderTrav(Node *root){
   map<int , map<int, vector<int>> > nodes;// horizontal distance, levels, nodes->data
   queue<pair<Node*, pair<int, int>> >q;   // nodes, horizontal distance, levels
   vector<int> ans;

   q.push(make_pair(root, make_pair(0,0)));

   while(!q.empty()){
      pair<Node*, pair<int, int>> temp = q.front();
      q.pop();
      Node *frontNode = temp.first;
      int hd = temp.second.first;
      int lv = temp.second.second;

      nodes[hd][lv].push_back(frontNode->data);
      
      if(frontNode->left){
         q.push(make_pair(frontNode->left, make_pair(hd-1,lv+1)));
      }
      if(frontNode->right){
         q.push(make_pair(frontNode->right, make_pair(hd+1,lv+1)));
      }
   }
   for(auto i: nodes){
      for(auto j:i.second){
         for(auto k:j.second){
            ans.push_back(k);
         } 
      }
   }
   for(int i=0; i<ans.size();i++){
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

    cout<<"The Vertical order traversal is: "<<endl;
    verticalOrderTrav(root);
   



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
   
   
   
   
    