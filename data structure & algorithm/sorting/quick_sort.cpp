#include<iostream>
#include<algorithm>
using namespace std;

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            swap(a[j], a[i]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1); //Đệ quy sắp xếp phần bên trái
        quickSort(a, pi + 1, high); //Đệ quy sắp xếp phần bên phải
    }
}
int main()
{
    int a[] = {8, 4, 7, 3, 9, 1};
    int n = sizeof(a)/sizeof(a[0]);
    quickSort(a, 0, n - 1);
    for(auto x: a)
    {
        cout << x << " ";
    }
    return 0;
}