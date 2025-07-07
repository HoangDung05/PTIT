#include<bits/stdc++.h>
using namespace std;
int n, x[100] = {0};
bool OK = true;

void Init()
{
    cin >> n;
    if (n < 6)
        OK = false;
    for (int i = 0; i < n; i++)
        x[i] = 6;
}

bool check()
{
    if (x[0] != 8 || x[n-1] != 6)
        return false;
    for (int i = 0; i < n; i++)
    {
        if (x[i] == x[i+1])
        {
            if (x[i] == 8)
                return false;
            if (x[i] == 6)
                if(x[i] == x[i+2] && x[i] == x[i+3])
                    return false;
        }
    }
    return true;
}

void Result()
{
    for (int i = 0; i < n; i++)
        cout << x[i];
    cout << endl;
}

void Next_Bits_String()
{
    int i = n - 1; 
    while (i >= 0 && x[i] == 8)
    {
        x[i] = 6;
        i--;
    }
    if (i >= 0)
    {
        x[i] = 8;
    }
    else
        OK = false;
}

int main()
{
    Init(); // Thiết lập cấu hình đầu tiên
    while (OK)
    {
        if (check())
            Result(); // In ra kết quả 
        Next_Bits_String(); // Tìm xâu nhị phân kế tiếp
        
    }
    return 0;
}