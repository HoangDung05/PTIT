#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ll x, y;
	cin >> x >> y;
	if (llabs(x - y) <= 1)
		cout << "Bob";
	else 
		cout << "Alice";
	return 0;	
}
