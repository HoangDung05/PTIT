#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

void form_ten(string &s)
{
    s[0] = toupper(s[0]);
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i-1] == ' ')
            s[i] = toupper(s[i]);
        else
            s[i] = tolower(s[i]);
    }
}

void form_ngaysinh(string &s)
{
    if (s[1] == '/')
        s.insert(0, "0");
    if (s[4] == '/')
        s.insert(3, "0");
}

struct SinhVien
{
    string ma, ten, ngaysinh, lop, nam, thang, ngay;
    double gpa;
};

void nhap(SinhVien &a)
{
    cin >> a.ma;
    cin.ignore();
    getline(cin, a.ten);
    cin >> a.ngaysinh >> a.lop >> a.gpa;
    form_ten(a.ten);
    form_ngaysinh(a.ngaysinh);
    a.ngay.insert(0, a.ngaysinh, 0, 2);
    a.thang.insert(0, a.ngaysinh, 3, 2);
    a.nam.insert(0, a.ngaysinh, 6, 4);
}

int cmp(SinhVien a, SinhVien b)
{
    if (a.nam != b.nam)
        return a.nam < b.nam;
    if (a.thang != b.thang)
        return a.thang < b.thang;
    if (a.ngay != b.ngay)
        return a.ngay < b.ngay;
    return a.ma < b.ma;
}

void in(SinhVien a)
{
    cout << a.ma << " " << a.ten << " " << a.ngaysinh << " " << a.lop << fixed << setprecision(2) << " " << a.gpa << endl;
}

int main(int argc, char* argv[])
{
    int n; cin >> n;
    SinhVien sv[n];
    for (int i = 0; i < n; i++)
    {
        nhap(sv[i]);
    }
    sort(sv, sv + n, cmp);
    for (int i = 0; i < n; i++)
    {
        in(sv[i]);
    }
    return 0;
}

