#include <iostream>
#include <bits/atomic_lockfree_defines.h>
using namespace std;

int sumDigits(string s)
{
    int tong = 0;
    for (int i = 0; i < s.length(); i++)
        tong += s[i] - '0';
    string tongStr = to_string(tong);
    if (tongStr.length() == 1)
        return tong;
    else
        return sumDigits(tongStr);
}

int main(int argc, char* argv[])
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        if (sumDigits(s) == 9)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}
