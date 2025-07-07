#include <iostream>
using namespace std;

class NhanVien
{
    private:
        string ma, ten;
        float hs;
        long lcb, pc;
    public:
        void nhap()
        {
            cin >> ma;
            cin.ignore();
            getline(cin,ten);
            cin >> hs >> lcb >> pc;
        }
    public:static float sum_salary;
        void tongluong()
        {
            sum_salary += hs * lcb + pc;
        }
};

float NhanVien::sum_salary;
int main(int argc, char* argv[])
{
    int n;
    cin >> n;
    NhanVien a[n];
    for (int i = 0; i < n; i++)
        a[i].nhap();
    for (int i = 0; i < n; i++)
        a[i].tongluong();
    cout << a[n-1].sum_salary;
}
