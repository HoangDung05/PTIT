#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int a, b; cin >> a >> b;
    if (a < b) 
        while (b--)
        {
            cout << a;
        }
        
    else 
        while (a--)
        {
            cout << b;
        }
    return 0;
}