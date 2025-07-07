#include<bits/stdc++.h>
using namespace std;
short n, a[100];
void Init()
{
    cin >> n;
    for (short i = 0; i < n; i++)
        cin >> a[i];
}

int MaxCrossingSum(short l, short m, short r)
{
    int sum = 0, leftSum = INT_MIN, rightSum = INT_MIN;
    for(short i = m; i >= l; i--)
    {
        sum += a[i];
        if(sum > leftSum)
            leftSum = sum;
    }
    sum = 0;
    for (short i = m+1; i <= r; i++)
    {
        sum += a[i];
        if(sum > rightSum)
            rightSum = sum;
    }
    return leftSum + rightSum;
}

int MaxSubArray(short l, short r) // tìm tổng lớn nhất của dãy mảng liên tục/dãy ban đầu
{
            // Bài toán con 1: Tìm tổng lớn nhất của mảng liên tục/dãy bên trái middle
            // Bài toán con 2: Tìm tổng lớn nhất của mảng liên tục/dãy bên phải middle
            // Bài toán con 3: Tìm tổng lớn nhất của mảng liên tục/dãy gồm 1 số phần tử bên trái và bên phải middle
            if(l==r)
                return a[l];
            short m = (l+r)/2;
            int maxLeft = MaxSubArray(l, m);
            int maxRight = MaxSubArray(m+1, r);
            int maxleftRight = MaxCrossingSum(l, m, r);
            return max(max(maxLeft,maxRight), maxleftRight);
}
int main()
{
    short t;
    cin >> t;
    while (t--)
    {
        Init();
        cout << MaxSubArray(0, n-1) << endl;
    }
    return 0;
}