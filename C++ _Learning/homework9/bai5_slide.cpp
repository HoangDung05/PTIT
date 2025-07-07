#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n,k;
int x[100],y[100];


void taoxau(){
    x[1]=0;x[2]=1;
    for(int i=3;i<=n;i++){
        x[i]==0;
    }
    for(int i=1;i<=n;i++){
        y[i]=i;
    }
}

bool check(){
    for(int i=1;i<=n;i++){
        if(x[i]==0) return false;
    }
    return true;
}

void in(){
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+= x[i]*y[i];
    }
    if(sum==k){
        for(int i=1;i<=n;i++) if(x[i]==1) cout<<y[i]<<" ";
        cout<<endl;
    }
}

void xaunext(){
    for(int i=n;i>=1;i--){
        if(x[i]==0){
            x[i]=1;
            break;
        }else x[i]=0;
    }
}

int main(){
    cin>>n>>k;
    taoxau();
    while(!check()){
        in();
        xaunext();
    }
    in();
}







