#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        queue<long> q; //luu tru cac so duoc tao ra boi so 9 va so 0
        q.push(9);
        while (1)
        {
            if (q.front()%n==0)
            {
                cout << q.front() << endl;
                break;
            }
            else
            {
                q.push(q.front()*10);
                q.push(q.front()*10+9);
                q.pop();
            }
        }
        
    }
    
}