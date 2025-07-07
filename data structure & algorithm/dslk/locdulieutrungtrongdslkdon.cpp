#include<bits/stdc++.h>
using namespace std;

int save[1000000] = {0};

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

void solve(node &head){
    node tmp = head;
    node truoc = tmp;
    while (tmp != NULL)
    {
        if (save[tmp->data] < 1)
        {
            truoc = tmp;
            save[tmp->data]++;
        }
        else if (save[tmp->data] >= 1)
        {
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
    solve(head);
    Display(head);
}