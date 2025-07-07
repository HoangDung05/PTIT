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
    ifstream inFile("DT.INP");
    ofstream outFile("DT.OUT");
    if (inFile.is_open())
    {
        int t, n, tongbac = 0;
        vector<vector<int>> a;
        inFile >> t >> n; // đọc dòng đầu vào biến t
        // đọc các số từ các dòng còn lại vào mảng 2 chiều
        string line; 
        while (getline(inFile, line))
        {
            vector<int> row; // hàng trong mảng 2 chiều
            stringstream ss(line);
            int num;
            while (ss >> num)
            {
                if (num)
                    tongbac++;
                row.push_back(num);
            }
            if (!row.empty())
                a.push_back(row);
        }
        inFile.close();
        if (t == 1)
        {
            for (int i = 0; i < n; i++)
            {
                int cnt = 0;
                for (int j = 0; j < n; j++)
                {
                    if (a[i][j])
                        cnt++;
                }
                outFile << cnt << " ";
            }
        }
        else if (t == 2)
        {
            outFile << n << " " << tongbac/2 << endl;
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (a[i][j])
                        outFile << i + 1 << " " << j + 1 << endl;
                }
            }
        }
        outFile.close();
    }
    else
    {
        cout << "khong mo duoc tep";
    }
    return 0;
}