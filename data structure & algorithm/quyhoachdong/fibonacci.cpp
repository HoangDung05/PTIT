// tính số fibonacci thứ n bằng pp quy hoạch động
#include<bits/stdc++.h>
using namespace std;
int main()
{
    //1. khai báo bảng phương án
    int f[n+1];
    //2. khoi tao gia tri ban dau cho bang phuong an: bai toan con co so
    f[0] = 0, f[1] = 1;
    //3. truy vet bang phuong an, su dung cong thuc truy hoi de tinh gia tri bai toan con i
    for (int i = 2; i <= n; i++)
        f[i] = f[i-1] + f[i-2];
    cout << f[n];
    return 0
}