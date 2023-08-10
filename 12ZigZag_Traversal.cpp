//Given a binary tree. Return true if, for every node X in the tree other than leaves, its value is equal to the sum of its left subtree's value and its right subtree's value else return false
/*  ex:
          3       
        /   \      3 = 1+2  
       1     2             

          26
        /    \      
       10     3
     /    \     \
    4      6      3
*/

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

void zigZagTrav(Node* root){
    	vector<int> res;
    	queue<Node*> q;
    	q.push(root);
    	bool leftToRight = true;
    	
    	while(!q.empty()) {
    	    int size = q.size();
    	    vector<int> ans(size);
    	    
    	    for(int i=0; i<size; i++) {
    	        Node* frontNode = q.front();
    	        q.pop();
                
    	        int index = leftToRight ? i : size - i - 1;
    	        ans[index] = frontNode -> data;
    	        
    	        if(frontNode->left)
    	            q.push(frontNode -> left);
    	            
    	        if(frontNode->right)
    	            q.push(frontNode -> right);
    	    }
    	    //direction changed
    	    leftToRight = !leftToRight;
    	   
    	  for(auto i: ans) {
    	      res.push_back(i);
    	  }  
    	}    
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }

}

int main(){
    struct Node* root = new Node(1); 
    root->left = new Node(2);
    root->right = new Node(3);

    root->right->left = new Node(4);
    root->right->right = new Node(5);

    cout<<"Levelorder is: "<<endl;
    printLevelOrder(root);
    cout<<endl;
 
    cout<<"The Zig Zag traversal: "<<endl;
    zigZagTrav(root);
    

    return 0;
}

/*        1              
        /   \   
       2     3             
            / \
           4   5            
*/