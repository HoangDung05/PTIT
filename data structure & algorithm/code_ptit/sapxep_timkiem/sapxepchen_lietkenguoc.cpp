#include<iostream>
#include<vector>
using namespace std;

void insertion_Sort(vector<int>& a, int n)
{
    vector<vector<int>> steps;
    for (int i = 0; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
        steps.push_back(a);
    }
    
    for (int i = steps.size() - 1; i >= 0; i--)
    {
        cout << "Buoc " << i << ": ";
        for (int j = 0; j < i + 1; j++)
        {
            cout << steps[i][j] << " ";
        }
        cout << endl;
    }
    
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    insertion_Sort(a, n);
    return 0;
}