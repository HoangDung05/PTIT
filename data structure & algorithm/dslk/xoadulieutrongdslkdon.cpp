#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

typedef struct Node* node;

void insertLast(node &head, int value)
{
    node p = new Node();
    p->data = value;
    p->next = NULL;

    if (head == NULL)
    {
        head = p;
    }
    else
    {
        node tmp = head;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = p;
    }
}

void Display(node &head)
{
    node p = head;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

void solve(node &head, int x){
    node tmp = head;
    if (tmp->data == x){
        while (tmp->data == x){
            tmp = tmp->next;
        }
        head = tmp;
    }
    node truoc = head;
    while (tmp != NULL)
    {
        if (tmp->data != x){
            truoc = tmp;
        }
        else{
            truoc->next = tmp->next;
        }
        tmp = tmp->next;
    }
}

int main()
{
    int n; cin >> n;
    node head = NULL;
    for (int i = 0; i < n; i++)
    {
        int value; cin >> value;
        insertLast(head, value);
    }
    int x; cin >> x;
    solve(head, x);

    Display(head);
}