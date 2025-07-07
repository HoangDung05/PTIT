#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; 
    cin >> t;
    while (t--) {
        int n, k;
        long long ans = 0;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        for (int i = 0; i < n; i++)
        {
            ans += lower_bound(a + i + 1, a + n, a[i] + k) - (a + i + 1);
        }
        cout << ans << endl;
    }
    return 0;
}

// cach 2
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int t; 
//     cin >> t;
//     while (t--) {
//         int n, k;
//         long long count = 0;
//         cin >> n >> k;
//         vector<int> a(n);
//         for (int i = 0; i < n; i++)
//             cin >> a[i];

//         sort(a.begin(), a.end());

//         int j = 1; 
//         for (int i = 0; i < n; i++) {
//             while (j < n && a[j] - a[i] < k) {
//                 j++;
//             }
//             count += (j - i - 1); 
//         }
//         cout << count << endl;
//     }
//     return 0;
// }
