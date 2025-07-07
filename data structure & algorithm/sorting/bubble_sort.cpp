#include<iostream>
#include<stdbool.h>
#include<algorithm>
using namespace std;
int main(){
    int a[5] = {4, 2, 10, 7, 5};
    for (int i = 0; i < 5; i++)
    {
        bool check = false;
        for (int j = i; j < 5 - i - 1; j++)
        {
            if (a[j] > a[j+1])
            {
                check = true;
                swap(a[j], a[j+1]);
            }
        }
        if(!check) break;
    }
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}