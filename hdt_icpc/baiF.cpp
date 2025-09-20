#include<bits/stdc++.h>
using namespace std;
bool solve(string s){
    int l = 0, r = s.length() - 1;
    int dem = 0;
    while (l <= r)
    {
        if (s[l] != s[r]) {
            dem++;
            if (dem > 1) {
                return false;
            }
        }
        l++;
        r--;
    }
    if (dem <= 1) 
        return true;
    return false;
}
int main() {
    int t; cin >> t;
    while (t--)
    {
        int cnt = 0;
        int a, b; cin >> a >> b;
        for (int i = a; i <= b; i++) {
            
            if (solve(to_string(i)))
                cnt++;
        }
        cout << cnt << endl;
    }
}
