#include <algorithm>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
int m = 0;

struct HocSinh
{
    double diem[10];
    string ten, ma;
    double diemtb;
};

int cmp(HocSinh a, HocSinh b)
{
    if (a.diemtb != b.diemtb)
        return a.diemtb > b.diemtb;
    else
        return a.ma < b.ma;
}

int main(int argc, char* argv[])
{
    int n;
    cin >> n;
    HocSinh hs[n];
    for (int i = 0; i < n; i++)
    {
        ++m;
        if (m < 10)
            hs[i].ma = "HS0" + to_string(m);
        else
            hs[i].ma = "HS" + to_string(m);
        cin.ignore();
        getline(cin, hs[i].ten);
        for (int j = 0; j < 10; j++)
        {
            cin >> hs[i].diem[j];
            if (j == 0 || j == 1)
                hs[i].diemtb += hs[i].diem[j] * 2;
            else
                hs[i].diemtb += hs[i].diem[j];
        }
        hs[i].diemtb /= 12;
    }
    sort(hs, hs + n, cmp);
    for (int i = 0; i < n; i++)
    {
        cout << hs[i].ma << " " << hs[i].ten << " " << fixed << setprecision(1) << hs[i].diemtb << " ";
        if (hs[i].diemtb >= 9)
            cout << "XUAT SAC" << endl;
        else if (hs[i].diemtb >= 8)
            cout << "GIOI" << endl;
        else if (hs[i].diemtb >= 7)
            cout << "KHA" << endl;
        else if (hs[i].diemtb >= 5)
            cout << "TB" << endl;
        else
            cout << "YEU" << endl;
    }
    return 0;
}

// 3
// Luu Thuy Nhi
// 9.3  9.0  7.1  6.5  6.2  6.0  8.2  6.7  4.8  5.5
// Le Van Tam
// 8.0  8.0  5.5  9.0  6.8  9.0  7.2  8.3  7.2  6.8
// Nguyen Thai Binh
// 9.0  6.4  6.0  7.5  6.7  5.5  5.0  6.0  6.0  6.0
