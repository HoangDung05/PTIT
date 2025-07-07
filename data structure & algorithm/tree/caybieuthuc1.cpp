#include<bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    Node *left = NULL, *right = NULL;
    Node(char data)
    {
        this->data = data;
    }
};

typedef struct Node* node;

void inOrder(node root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data;
    inOrder(root->right);
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        stack<node> st;
        for (char c: s)
        {
            node p = new Node(c);
            if (isalpha(c))
                st.push(p);
            else
            {
                p->right = st.top(); st.pop();
                p->left = st.top(); st.pop();
                st.push(p);
            }
        }
        inOrder(st.top());
        cout << endl;
    }
    return 0;
}