#include<iostream>
using namespace std;

// hàm trộn hai mảng con đã sắp xếp vào mảng chính
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1; // Kích thước mảng con trái
    int n2 = right - mid; // Kích thước mảng con phải

    // tạo mảng tạm
    int L[n1], R[n2];

    // sao chép dữ liệu vào mảng tạm
    for(int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for(int i = 0; i < n2; i++)
    {
        R[i] = arr[mid + 1 + i];
    }

    // Merge hai mảng con vào arr[]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if(L[i] < R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // sao chép phần còn lại của L[] nếu có
    while (i < n1)
    {
        arr[k] = L[i];
        k++;
        i++;
    }

    // sao chép phần còn lại của R[] nếu có
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    } 
}

// Hàm Merge Sort
void mergeSort(int arr[], int left, int right)
{
    if(left < right)
    {
        int mid = left + (right - left) / 2; // tìm vị trí giữa

        // gọi đệ quy để sắp xếp hai nửa
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // trộn hai nửa đã sắp xếp
        merge(arr, left, mid, right);
    }
}


int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}