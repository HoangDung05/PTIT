#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n;
int x[100];

void swap(int &a,int &b){
    int tmp = a;
    a=b;
    b=tmp;
}

void taoxau(){
    for(int i=1;i<=n;i++){
        x[i]=i;
    }
}

bool check(){
    for(int i=1;i<=n;i++){
        if(x[i]!=n-i+1) return false;
    }
    return true;
}

void in(){
    for(int i=1;i<=n;i++) cout<<x[i];
    cout<<endl;
}

void xaunext(){
    int p=n-1,k=n;
    while(x[p]>x[p+1]) p--;
    while(x[k]<x[p]) k--;
    swap(x[p],x[k]);
    int l=p+1,r=k;
    while(l<r){
        swap(x[l],x[r]);
        l++;r--;
    }
}

int main(){
    cin>>n;
    taoxau();

    while(!check()){
        in();
        xaunext();
    }
    in();
}







