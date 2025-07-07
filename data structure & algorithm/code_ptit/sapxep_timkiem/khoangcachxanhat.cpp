#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<int> leftMin(n), rightMax(n);
        leftMin[0] = a[0], rightMax[n-1] = a[n-1];
        for (int i = 1; i < n; i++)
            leftMin[i] = min(a[i], leftMin[i-1]);
        for (int i = n - 2; i >= 0; i--)
            rightMax[i] = max(a[i], rightMax[i+1]);
        int i = 0, j = 0;
        int maxDis = -1;
        while (i < n && j < n)
        {
            if (leftMin[i] < rightMax[j])
            {
                maxDis = max(maxDis, j - i);
                j++;
            }
            else
                i++;
        }
        cout << maxDis << endl;
    }
    
    return 0;
}