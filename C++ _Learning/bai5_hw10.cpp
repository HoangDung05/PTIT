#include <bits/stdc++.h>
using namespace std;

int a[100], m[100], n, k;
void in(int a[], int n, int k){
    int tong=0;
    for(int i=1; i<=n; i++) m[i]=i;
    for(int i=1; i<=n; i++){
        tong+=a[i]*m[i];
    }
    if(tong==k){
        for(int i=1; i<=n; i++){
            if(a[i]!=0) cout << m[i] << ' ';
        }
        cout << '\n';
    }
}
void Try(int i){
    for(int y=0; y<=1; y++){
        a[i]=y;
        if(i==n)    in(a, n, k);
        else  Try(i+1);
    }
}
int main()
{
    cin >> n >> k;
    Try(1);
    return 0;
}