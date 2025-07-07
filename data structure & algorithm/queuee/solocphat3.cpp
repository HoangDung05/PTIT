#include<iostream>
#include<queue>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        queue<string> q; 
        q.push("6");
        q.push("8");
        vector<string> luckyNumber;
        while (1)
        {
            string x = q.front();
            q.pop();
            if (x.size() > n) break;
            luckyNumber.push_back(x);
            q.push(x+"6");
            q.push(x+"8");
        }
        cout << luckyNumber.size() << endl;
        for (int i = luckyNumber.size()-1; i >= 0; i--)
        {
            cout << luckyNumber[i] << " ";
        }
        cout << endl;
    }
    
}