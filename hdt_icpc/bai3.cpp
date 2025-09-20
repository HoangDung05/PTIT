#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    long long a[n + 1], pre[n + 1];
    memset(pre, 0, sizeof(pre));
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    sort(a + 1, a + n + 1);
    pre[1] = a[1];
    for (int i = 2; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }

    long long sum = 0;
    for (int i = 2; i <= n; i++) {
        sum += (a[i] * (i-1) - pre[i - 1]);
    }
    cout << sum;
}