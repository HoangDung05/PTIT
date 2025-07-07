#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n,k;
int x[100];

void taoxau(){
    for(int i=1;i<=n;i++){
        x[i]==0;
    }
}

bool KiemTraXau1(){
    int legit=0;
    int i=1;
    while(i<=n){
        if(x[i]==1){
            int dodai=0;
            while(x[i]==1){
                dodai++;i++;
            }
            if(dodai>k) return false;
            else if(dodai==k) legit++;
        }
        else i++;
    }
    if(legit==1) return true;
    else return false;
}

bool check(){
    for(int i=1;i<=n;i++){
        if(x[i]==0) return false;
    }
    return true;
}

void in(){
    if(KiemTraXau1()){
        for(int i=1;i<=n;i++) cout<<x[i];
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







