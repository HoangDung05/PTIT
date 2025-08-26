#include<bits/stdc++.h>
using namespace std;

bool cmp(int x, int y) {
    string a = to_string(x), b = to_string(y);
    return a + b > b + a;
}

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    sort(a.begin(), a.end(), cmp);
    string ans = "";
    for (int i = 0; i < 3; i++)
        ans += to_string(a[i]);
    cout << ans;

    return 0;
}
