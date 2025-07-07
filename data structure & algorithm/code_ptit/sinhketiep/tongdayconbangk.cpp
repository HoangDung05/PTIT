//Liet ke xau nhi phan: Sinh ke tiep
#include<bits/stdc++.h>
using namespace std;
int n, k, x[100], a[100];
bool OK = true;

void nhap()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

void Init()
{
    for (int i = 0; i < n; i++)
    {
        x[i] = 0;
    }
}

void Result()
{
    for (int i = 0; i < n; i++)
        if (x[i])
            cout << a[i] << " ";
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

bool check()
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (x[i])
            sum += a[i];
    }
    if (sum == k)
        return true;
    return false;
}

int main()
{
    nhap();
    Init(); // Thiết lập cấu hình đầu tiên
    int cnt = 0;
    while (OK)
    {
        if (check())
        {
            cnt++;
            Result();
        } 
        Next_Bits_String(); // Tìm xâu nhị phân kế tiếp
    }
    cout << cnt;
    return 0;
}