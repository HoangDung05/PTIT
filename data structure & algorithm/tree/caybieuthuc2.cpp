#include<bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    Node *left = NULL, *right = NULL;
    Node(char d)
    {
        this->data = d;
    }
};

int calc(string a[], int i)
{
    if (a[i] == "+")
        return calc(a, 2*i+1) + calc(a, 2*i+2);
    if (a[i] == "-")
        return calc(a, 2*i+1) - calc(a, 2*i+2);
    if (a[i] == "*")
        return calc(a, 2*i+1) * calc(a, 2*i+2);
    if (a[i] == "/")
        return calc(a, 2*i+1) / calc(a, 2*i+2);
    return stoi(a[i]);
}


int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << calc(a, 0) << endl;
    }    
    return 0;
}