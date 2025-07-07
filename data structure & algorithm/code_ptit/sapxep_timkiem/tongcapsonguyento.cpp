#include<bits/stdc++.h>
using namespace std;

set<int> prime;

void eratosthenes(int n)
{
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= sqrt(n); i++)
        if (isPrime[i])
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
    for (int i = 2; i <= n; i++)
        if (isPrime[i]) 
            prime.insert(i);
}

int main()
{
    int t; cin >> t;
    eratosthenes(1000000);
    while (t--)
    {
        int n; cin >> n;
        bool check = false;
        for (auto c: prime)
        {
            if (c > n/2)
                break;
            if (prime.find(n - c) != prime.end())
            {
                check = true;
                cout << c << " " << n - c << endl;
                break;
            }
        }
        if (check == false)
            cout << -1 << endl;
    }
    
    return 0;
}