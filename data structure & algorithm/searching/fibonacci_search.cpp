#include<iostream>
using namespace std;

int fibonacciSearch(int a[], int n, int x)
{
    int fib2 = 0, fib1 = 1, fib = fib1 + fib2;
    //tìm số fibonacci nhỏ nhất lớn hơn hoặc bằng độ dài mảng
    while (fib < n)
    {
        fib2 = fib1;
        fib1 = fib;
        fib = fib1 + fib2;
    }
    int offset = -1; //điểm bắt đầu tìm kiếm
    while (fib > 1)
    {
        //đảm bảo i nằm trong phạm vi mảng
        int i = min(offset + fib2, n - 1);
        
        //nếu x lớn hơn giá trị tại i, tìm kiếm phần phải
        if (x > a[i])
        {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        }
        //nếu x nhỏ hơn giá trị tại i, tìm kiếm phần bên trái
        else if (x < a[i])
        {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
        else
            return i;
    }
    //kiểm tra phần tử cuối cùng
    if (fib1 && a[offset + 1] == x)
        return offset + 1;
    return -1;
}

int main()
{
    int a[] = {2, 5, 8, 19, 45, 87, 90, 95};
    int x; cin >> x;
    int n = sizeof(a) / sizeof(a[0]);
    cout << fibonacciSearch(a, n, x);
    return 0;
}