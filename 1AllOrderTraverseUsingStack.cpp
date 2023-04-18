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

void preOrder(struct Node *root)
{
    stack<Node *> st;
    vector<int> ans;
    st.push(root);
    while (!st.empty())
    {
        root = st.top();
        st.pop();
        ans.push_back(root->data);
        if (root->right)
        {
            st.push(root->right);
        }
        if (root->left)
        {
            st.push(root->left);
        }
    }
    for (int i = 0; i < ans.size() - 1; i++)
    {
        cout << ans[i] << " ";
    }
}
void inOrder(struct Node *root)
{
    stack<Node *> st;
    vector<int> ans;
    st.push(root);
    Node *node = root;
    while (!st.empty())
    {
        if (node != NULL)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            if (st.empty())
            {
                break;
            }
            node = st.top();
            st.pop();
            ans.push_back(node->data);
            node = node->right;
        }
    }
    for (int i = 0; i < ans.size() - 1; i++)
    {
        cout << ans[i] << " ";
    }
}
void postOrder(struct Node *root)
{
    stack<Node *> st;
    vector<int> ans;
    st.push(root);
    Node *node = root;
    while (!st.empty())
    {
        if (node != NULL)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            if (st.empty())
            {
                break;
            }
            node = st.top();
            st.pop();
            ans.push_back(node->data);
            node = node->right;
            if (node == NULL)
            {
                node = st.top();
                node = node->right;
            }
        }
    }
    for (int i = 0; i < ans.size() - 1; i++)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);

    cout << "Preorder Using Stack is: " << endl;
    preOrder(root);
    cout << endl;
    cout << "Inorder Using Stack is: " << endl;
    inOrder(root);
    cout << endl;
    cout << "Postorder Using Stack is: " << endl;
    postOrder(root);

    return 0;
}

/*
          1
        /   \
       2     3
      / \   / \
     4   5 6   7

*/