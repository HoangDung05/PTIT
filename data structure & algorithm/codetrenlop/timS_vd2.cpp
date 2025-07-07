#include<iostream>
using namespace std;
int main()
{
    int n; cin >> n;
    double S = 0;
    for(int i = 0; i <= n; i++)
    {
        S += (double)(2*i+1)/(2*i+2);
    }
    cout << S;
}