#include<iostream>
using namespace std;
int main(){
    int a[4] = {5, 3, 2, 7};
    for(int i = 0; i < 4; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
    for(int i = 0; i < 4; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}