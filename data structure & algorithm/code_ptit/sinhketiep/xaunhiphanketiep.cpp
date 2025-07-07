//Liet ke xau nhi phan: Sinh ke tiep
#include<bits/stdc++.h>
using namespace std;
int n;
string x;
// string s;

void Init()
{
    cin >> x;
    n = x.length();
}

void Result()
{
    cout << x << endl;
}

void Next_Bits_String()
{
    int i = n - 1; 
    while (i >= 0 && x[i] == '1')
    {
        x[i] = '0';
        i--;
    }
    if (i >= 0)
    {
        x[i] = '1';
    }
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        Init(); // Thiết lập cấu hình đầu tiên
        Next_Bits_String(); // Tìm xâu nhị phân kế tiếp
        Result(); // In ra kết quả 
    }
    return 0;
}