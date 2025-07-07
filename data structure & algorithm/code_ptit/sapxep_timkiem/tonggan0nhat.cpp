#include<iostream>
#include<map>
#include<cmath>
using namespace std;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int closestSum = a[0] + a[1];
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int currentSum = a[i] + a[j];
                if (abs(currentSum) < abs(closestSum))
                {
                    closestSum = currentSum;
                }
                
            }
        }
        cout << closestSum << endl;
    }
    return 0;
}