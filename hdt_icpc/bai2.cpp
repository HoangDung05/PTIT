#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> v;
set<ll> se;
int prime[100001]; // N = 10^7
void sang(){
        //Bước 1 : Coi tất cả các số từ 0 tới N là số nguyên tố
	for(int i = 0; i <= 100000; i++){
		prime[i] = 1;
	}
        //Bước 2 : Sàng
	prime[0] = prime[1] = 0;
	for(int i = 2; i * i <= 100000; i++){
		if(prime[i]){
			for(int j = i * i; j <= 100000; j += i){
				prime[j] = 0;
			}
		}
	}

    for(int i = 2; i <= 100000; i++){
		if (prime[i])
            v.push_back(i);
	}
}

void snt(ll x) {
    for (auto i: v) {
        if (i > x)
            return;
        if (x % i == 0) {
            while (x % i == 0)
            {
                x /= i;
            }
            se.insert(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie();
    sang();
    int n, m;
    cin >> n >> m;
    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        snt(a[i]);

    }
    vector<ll> vt(m+1, 1);
    for (auto x : se){
        for(int j=x; j<=m;j+=x){
            vt[j] = 0;
        }
    }
    int cnt = 0;
    vector <int> vt2;
    for(int i = 1; i<vt.size();i++){
        if(vt[i] == 1){
            cnt++;
            vt2.push_back(i);
        }
    }
    cout << cnt << endl;
    for(auto x:vt2){
        cout << x << " ";
    }
}