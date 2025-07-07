#include <bits/stdc++.h>
using namespace std;

int a[100], m[100], n, k, B;
void in(int a[], int n, int B){
    int tong=0;
    for(int i=1; i<=n; i++) m[i]=i;
    for(int i=1; i<=n; i++){
        tong+=a[i]*m[i];
    }
    if(tong==B){
        int tmp=0;
        for(int i=1; i<=n; i++){
            if(a[i]!=0) tmp++;
        }
        if(tmp==k){
            for(int i=1; i<=n; i++){
                if(a[i]!=0) cout << m[i] << ' ';
            }
            cout << '\n';
        }
    }
}
void Try(int i){
    for(int y=0; y<=1; y++){
        a[i]=y;
        if(i==n)    in(a, n, B);
        else  Try(i+1);
    }
}
int main()
{
    cin >> n >> k >> B;
    Try(1);
    return 0;
}