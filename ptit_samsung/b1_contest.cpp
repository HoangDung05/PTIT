#include<bits/stdc++.h>
using namespace std;

int min_index[1000005]; 
float sum_index[1000005];
void init_min(int n, vector<int> a){
    min_index[n - 1] = a[n - 1];
    sum_index[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--){
        min_index[i] = min(min_index[i + 1], a[i]);
        sum_index[i] = sum_index[i + 1] + a[i]; 
    }
}

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    init_min(n, a);
    int index;
    int result = 0;
    vector<vector<int>> save;
    for (int k = 1; k <= n - 2; k++) {
        int temp = (sum_index[k] - min_index[k])/(n-k-1);
        if (temp >= result)
        {
            index = k;
            result = temp;
            save[result].push_back(k);
        }
    }
    for (auto item: save[result])
        cout << item << " ";
    return 0;
}