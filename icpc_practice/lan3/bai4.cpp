// max(max_s-min_s; max_d-min_d)
#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct Point{
	ll x, y;
};

int main()
{
	int n; cin >> n;
	vector<Point> a(n);
	vector<ll> s(n), d(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].x >> a[i].y;
		s[i] = a[i].x + a[i].y;
		d[i] = a[i].x - a[i].y;
	}
	
	auto max_s1 = pair<ll, int>(LLONG_MIN, -1), max_s2 = max_s1;
	auto min_s1 = pair<ll, int>(LLONG_MAX, -1), min_s2 = min_s1;
	auto max_d1 = pair<ll, int>(LLONG_MIN, -1), max_d2 = max_d1;
	auto min_d1 = pair<ll, int>(LLONG_MAX, -1), min_d2 = min_d1;
	
	for (int i = 0; i < n; i++)
	{
		if (s[i] > max_s1.first)
		{
			max_s2 = max_s1;
			max_s1 = {s[i], i};
		}
		else if (s[i] > max_s2.first)
			max_s2 = {s[i], i};
		
		if (s[i] < min_s1.first)
		{
			min_s2 = min_s1;
			min_s1 = {s[i], i};
		}
		else if (s[i] < min_s2.first)
			min_s2 = {s[i], i};
		
		if (d[i] > max_d1.first)
		{
			max_d2 = max_d1;
			max_d1 = {d[i], i};
		}
		else if (d[i] > max_d2.first)
			max_d2 = {d[i], i};	
		
		if (d[i] < min_d1.first)
		{
			min_d2 = min_d1;
			min_d1 = {d[i], i};
		}
		else if (d[i] < min_d2.first)
			min_d2 = {d[i], i};
	}
	
	ll max_s, min_s, max_d, min_d;
	ll ans = LLONG_MAX;
	
	for (int i = 0; i < n; i++)
	{
		max_s = (i == max_s1.second) ? max_s2.first : max_s1.first;
		min_s = (i == min_s1.second) ? min_s2.first : min_s1.first;
		max_d = (i == max_d1.second) ? max_d2.first : max_d1.first;
		min_d = (i == min_d1.second) ? min_d2.first : min_d1.first;
		ll dis = max(max_s-min_s, max_d-min_d);
		ans = min(ans, dis);
	}
	cout << ans << endl;
	
	return 0;
}
