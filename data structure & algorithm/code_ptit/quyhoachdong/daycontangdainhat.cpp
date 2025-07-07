#include<bits/stdc++.h>
using namespace std;

void Init(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
        cin >> nums[i];
}

void Dynamic(vector<int> nums, int n)
{
    //1. khai bao bang phuong an: luu do dai cua day con tang dai nhat tai moi vi tri
    //2. khoi tao gia tri ban dau cho bang phuong an: bai toan con co so
    vector<int> dp(n,1);
    //3. truy vet bang phuong an, su dung cong thuc truy hoi de tinh gia tri bai toan
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
                dp[i] = max(dp[i], dp[j]+1);
        }
    }
    cout << *max_element(dp.begin(), dp.end());
}

int main()
{
    int n; cin >> n;
    vector<int> nums(n);
    Init(nums);
    Dynamic(nums, n);
    return 0;
}