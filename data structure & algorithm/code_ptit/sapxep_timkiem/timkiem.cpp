#include <iostream>
using namespace std;

int binarySearch(int a[], int n, int x)
{
    int low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x < a[mid])
            high = mid - 1;
        else if (x > a[mid])
            low = mid + 1;
        else
            return 1;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int t; cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << binarySearch(a, n, x);
        cout << endl;
    }
    return 0;
}
