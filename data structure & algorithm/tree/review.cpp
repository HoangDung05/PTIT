#include<bits/stdc++.h>
using namespace std;

//1.Dinh nghia node cho cay
struct Node
{
    int data;
    Node *left;
    Node *right;
};

typedef struct Node* node;

//2. Khai bao cay
node root = NULL;

//3. Xay dung cac thao tac/cay
//3.1 Tao node cho cay
node makeNode(int x){
    node p = new Node();
    p->data = x;
    p->right = NULL;
    p->left = NULL;
}

//3.2 Duyet cay
void NLR(node root){
    if (root != NULL)
    {
        cout << root->data << " ";
        NLR(root->left);
        NLR(root->right);
    }
}

void LNR(node root){
    if (root != NULL){
        LNR(root->left);
        cout << root->data << " ";
        LNR(root->right);
    }
}

void RNL(node root){
    if (root != NULL){
        RNL(root->right);
        cout << root->data << " ";
        RNL(root->left);
    }
}

int main(){
    //Tao node
    root = makeNode(50);
    node node40 = makeNode(40);
    node node60 = makeNode(60);
    node node30 = makeNode(30);
    node node20 = makeNode(20);
    node node65 = makeNode(65);
    node node70 = makeNode(70);
    node node25 = makeNode(25);
    node node15 = makeNode(15);

    //Ket noi cac node vao cay
    root->left = node40;
    root->right = node60;
    node40->left = node30;
    node40->right = node20;
    node60->left = node65;
    node60->right = node70;
    node20->left = node25;
    node20->right = node15;
}
