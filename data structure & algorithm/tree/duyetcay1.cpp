#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left = NULL, *right = NULL;
    Node(int data)
    {
        this->data = data;
    } 
};

typedef struct Node* node;

int n, pre[1001], curIdx;
map<int, int> indexOf;

node build(int left, int right)
{
    if (left > right)
        return NULL;
    node root = new Node(pre[curIdx]);
    int m = indexOf[pre[curIdx]]; curIdx++; // m lưu vị trí của root trong mảng inorder
    root->left = build(left, m - 1);
    root->right = build(m + 1, right);
    return root;
}

void postOrder(node root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        cin >> n; 
        for (int i = 0; i < n; i++)
        {
            int e; cin >> e;
            indexOf[e] = i;
        }
        for (int i = 0; i < n; i++)
            cin >> pre[i];

        curIdx = 0;
        node root = build(0, n-1);
        postOrder(root);
        cout << endl;

        indexOf.clear();
    }

    
    return 0;
}

