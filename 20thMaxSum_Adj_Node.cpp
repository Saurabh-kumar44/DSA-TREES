#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int n)
    {
        data = n;
        left = NULL;
        right = NULL;
    }
};

void printLevelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        if (node != NULL)
        {
            cout << node->data << " ";
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        else if (!q.empty())
        {
            q.push(NULL);
            // cout<<endl;
        }
    }
}

pair<int, int> solve(Node *root)
{
    if (root == NULL){
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left  = solve(root->left);
    pair<int, int> right = solve(root->right);

    pair<int, int> ans;
    ans.first = root->data + left.second + right.second;
    ans.second = max(left.first, left.second) + max(right.first, right.second);

    return ans;
}

int max_SumOfNonAdjNode(Node *root)
{
    pair<int, int> res = solve(root);

    return max(res.first, res.second);
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);

    cout << "Levelorder is: " << endl;
    printLevelOrder(root);
    cout << endl;

    cout << "The Max sum of non Adjcent nodes is: " << endl;
    cout<<max_SumOfNonAdjNode(root)<<endl;z z   

    return 0;
}

/*

          1
        /  \
       2    3
      /    / \
     4    5   6
*/
