#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
//0 sang phai, 1 di len
int m,n;
int x[100];

void taoxau(){
    for(int i=1;i<=m;i++){
        x[i]=0;
    }
    for(int i=m+1;i<=m+n;i++){
        x[i]=1;
    }
}

bool check(){
    for(int i=1;i<=n;i++){
        if(x[i]==0) return false;
    }
    for(int i=n+1;i<=m+n;i++){
        if(x[i]==1) return false;
    }
    return true;
}

void in(){
    int R=0,U=0,h=0,k=0;
    for(int i=1;i<=m+n;i++){
        if(x[i]==0) R++;
        else U++;
    }
    if(R==m && U==n){
        for(int i=1;i<=m+n;i++){
            if(x[i]==0) h++;
            else k++;
            cout<<"("<<h<<","<<k<<")";
        }
        cout<<endl;
    }
}

void xaunext(){
    for(int i=m+n;i>=1;i--){
        if(x[i]==0){
            x[i]=1;
            break;
        }else x[i]=0;
    }
}

int main(){
    cin>>m>>n;
    taoxau();
    while(!check()){
        in();
        xaunext();
    }
    in();
}







