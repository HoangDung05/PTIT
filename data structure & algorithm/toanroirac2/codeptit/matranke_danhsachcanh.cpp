// Dòng đầu chứa số nguyên dương t nhận giá trị 1 hoặc 2.
// Dòng thứ hai chứa số nguyên dương n không vượt quá 100 là số đỉnh của G.
// Trong n dòng tiếp theo, mỗi dòng chứa n số 0 hoặc 1 mô tả ma trận kề của G.
// Nếu t = 1 thì ghi ra một dòng gồm n số tự nhiên tương ứng là bậc của n đỉnh.
// Nếu t = 2 thì ghi ra theo qui cách
//           + Dòng đầu ghi ra hai số tự nhiên n và m là số đỉnh và số cạnh của G.
//           + Trong m dòng tiếp theo, mỗi dòng thứ i (1 <= i <= m) ghi hai số ui, vi là đỉnh đầu và đỉnh cuối của cạnh ei. Các cạn của G được đánh số theo thứ tự từ điển.



#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, tongbac = 0;
    cin >> t >> n; 
    int a[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            if (a[i][j])
                tongbac++;
        }
            
    if (t == 1)
    {
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (a[i][j])
                {
                    cnt++;
                }
                    
            }
            cout << cnt << " ";
        }
    }
    else if (t == 2)
    {
        cout << n << " " << tongbac/2 << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (a[i][j])
                    cout << i + 1 << " " << j + 1 << endl;
            }
        }
    }
    return 0;
}