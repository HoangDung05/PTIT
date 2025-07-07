//Liet ke xau nhi phan: Sinh ke tiep
#include<bits/stdc++.h>
using namespace std;
int n, x[100];
bool OK = true;

void Init()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        x[i] = 0;
    }
}

void Result()
{
    for (int i = 0; i < n; i++)
        cout << x[i] << " ";
    cout << endl;
}

void Next_Bits_String()
{
    int i = n - 1; 
    while (i >= 0 && x[i])
    {
        x[i] = 0;
        i--;
    }
    if (i >= 0)
        x[i] = 1;
    else
        OK = false;
}

int main()
{
    Init(); // Thiết lập cấu hình đầu tiên
    while (OK)
    {
        Result(); // In ra kết quả 
        Next_Bits_String(); // Tìm xâu nhị phân kế tiếp
    }
    return 0;
}