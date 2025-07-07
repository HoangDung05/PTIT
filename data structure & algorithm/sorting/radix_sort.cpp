#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Hàm phụ trợ: Counting Sort theo chữ số hiện tại
void countingSort(vector<int>& arr, int exp)
{
    int n = arr.size();
    vector<int> output(n); // Mảng kết quả tạm thời
    int count[10] = {0};

    // đếm số lần xuất hiện của từng chữ số
    for (int i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }

    // chuyển đổi count[i] để chỉ ra vị trí thực tế trong output[]
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1]; 
    }

    // xây dựng mảng kết quả theo thứ tự ổn định (Stable Sort)
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    //sao chép mảng đã sắp xếp vào arr[]
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

// hàm chính Radix Sort
void radixSort(vector<int>& arr)
{
    int maxVal = *max_element(arr.begin(), arr.end()); // tìm số lớn nhất

    // chạy counting sort cho từng chữ số từ đơn vị đến hàng lớn nhất
    for(int exp = 1; maxVal / exp > 0; exp *= 10)
    {
        countingSort(arr, exp);
    }
}

int main()
{
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    radixSort(arr);
    for (auto c: arr)
    {
        cout << c << " ";
    }
    return 0;
}