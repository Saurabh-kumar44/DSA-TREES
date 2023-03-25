//Level order traversal 
//k th level sum

#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *left, *right;

    Node(int n){
        this->data = n;
        this->left = NULL;
        this->right = NULL;
    }
};

void printLevelOrder(Node* root)
{
	if (root == NULL){
		return;
    }
	queue<Node*> q;
	q.push(root);
    q.push(NULL);

	while (!q.empty()) {
		Node* node = q.front();
		q.pop();
        if(node != NULL){
		    cout << node->data << " ";
            if (node->left)
                q.push(node->left);
            if (node->right)
			    q.push(node->right);
        }
        else if(!q.empty()){
            q.push(NULL);
        }
	}
}

/* 
          1       L=0
        /   \
       2     3    L=1
      / \   / \ 
     4   5 6   7  L=2

*/

int sumAtK(Node * root , int k){
    if (root == NULL)
		return -1;
	queue<Node*> q;
	q.push(root);
    q.push(NULL);
    int level = 0;
    int sum =0;
	while (!q.empty()) {
		Node* node = q.front();
		q.pop();
        if(node != NULL){
		    if(level == k){
                sum +=node->data;
            }
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
			    q.push(node->right);
        }
        else if(!q.empty()){
            q.push(NULL);
            level++;
        }
	}
    return sum;
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

	cout << "Level Order traversal of binary tree is: ";
	printLevelOrder(root);
    int k = 2;
    cout<<sumAtK(root , k)<<endl;
	return 0;
}

/* 
          1       L=0
        /   \
       2     3    L=1
      / \   / \ 
     4   5 6   7  L=2

*/