#include<bits/stdc++.h>
using namespace std;
int t[10] = {1,2,5,10,20,50,100,200,500,1000};
int n;
void Init()
{
    cin >> n;
}

void Greedy() // min f(x): số tờ tiền ít nhất
{
    // x=(x1,x2...,xn): phương án nhặt tờ tiền -> 
    // -> xây dựng phương án tối ưu cục bộ: xi -> f(x)min
    int tong = 0;
    for(int i = 9; i >= 0; i--)
    {
        tong += n/t[i];
        n %= t[i];
        if(n==0)
            break;
    }
    cout << tong << endl;
}


int main()
{
    int t; cin >> t;
    while (t--)
    {
        Init();
        Greedy();
    }
    return 0;
    
}