#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n,K,S;
int x[100],a[100];

void input(){
    cin>>n>>K>>S;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
}

void in(){
    for(int i=1;i<=n;i++)  cout<<x[i];
    cout<<endl;
}

void quaylui(int i){
    for(int j=0;j<=1;j++){
        x[i]=j;
        if(i==n) {
            int sumx=0,suma=0;
            for(int l=1;l<=n;l++){
                sumx+= x[l];
            }
            for(int l=1;l<=n;l++){
                suma+= x[l]*a[l];
            }
            if(sumx==K && suma==S) in();
        }
        else quaylui(i+1);
    }
}

int main(){
    input();
    quaylui(1);
    return 0;
}