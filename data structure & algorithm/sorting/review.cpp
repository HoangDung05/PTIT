#include<iostream>
using namespace std;

void selectionSort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int key = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[key])
            {
                key = j;
            }
        }
        swap(a[i], a[key]);
    }
}

void insertSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (a[j] > key && j >= 0)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
        
    }
}

void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool check = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                check = true;
                swap(a[j], a[j+1]);
            }
        }
        if (check == false)
            break;
    }
}

// bat dau ham cua thuat toan quick sort
int partition(int a[], int low, int high)
{
    int j = low - 1, pivot = a[high];
    for (int i = low; i < high; i++)
    {
        if (a[i] <= pivot)
        {
            j++;
            swap(a[j], a[i]);
        }
    }
    swap(a[high], a[j+1]);
    return j + 1;
}

void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
    
}
//ket thuc ham thuat toan quick sort

int main()
{
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // gọi hàm sắp xếp
    bubbleSort(a, n);
    for (auto c: a)
        cout << c << " ";
    return 0;
}