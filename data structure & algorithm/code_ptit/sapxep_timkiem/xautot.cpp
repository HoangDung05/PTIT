#include<bits/stdc++.h>
#define ll long long
#define FORD(i,l,r) for(int i=l;i<r;i++)
using namespace std;

int main() {
	int n;
	string s;
	cin >> n >> s;
	ll res = 0, tmp = 1;
	FORD(i, 1, n)
		if (s[i] == s[i - 1])tmp++, res += i - (tmp<=i);
		else res += i - tmp, tmp = 1;
	cout << res << endl;
	return 0;
}