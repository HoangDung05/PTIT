//Dinh nghia dslk don; Xay dung cac thao tac
#include<bits/stdc++.h>
using namespace std;
//1.Dinh nghia node
struct Node{
    int data;
    Node *next;
};

//2. Dinh nghia dslk don
Node *head = NULL;

//3. Xay dung thao tac dslk don
void Insert(int newData)
{
    Node *newNode = new Node;
    newNode->data = newData;
    newNode->next = head;
    head = newNode;
}

//Thêm 1 node vào dslk
void Insert_position(int pos, int value)
{
    Node *pre = new Node;
    Node *cur = new Node;
    Node *temp = new Node;
    cur = head;
    for (int i = 1; i < pos; i++)
    {
        pre = cur;
        cur = cur->next
    }
    temp->data = value;
    pre->next = temp;
    temp->next = cur;
}

//Xóa 1 node tại vị trí pos khỏi dslk đơn
void delete_position(int pos)
{
    Node *current = new Node;
    Node *previous = new Node;
    current = head;
    for (int i = 1; i < pos; i++)
    {
        previous = current;
        current = current->next;
    }
    previous->next = current->next;
}

void Display()
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

int main()
{
    Insert(3);
    Insert(1);
    Insert(7);
    Insert(2);
    Insert(9);
    Display();
    return 0;
}