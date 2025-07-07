#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n,W,K;
int x[100],a[100],c[100];

void input(){
    cin>>n>>W>>K;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
}

void in(){
    for(int i=1;i<=n;i++) cout<<x[i];
    cout<<endl;
}

void quaylui(int i){
    for(int j=0;j<=1;j++){
        x[i]=j;
        if(i==n) {
            int suma=0,sumc=0;
            for(int l=1;l<=n;l++){
                sumc += x[l]*c[l];
            }
            for(int l=1;l<=n;l++){
                suma += x[l]*a[l];
            }
            if(sumc==K && suma<=W) in();
        }
        else quaylui(i+1);
    }
}

int main(){
    input();
    quaylui(1);
    return 0;
}