#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
//1. Khai bao lop
class NhanVien
{
    //Thuoc tinh
    public:
        string maNV, hoTen;
        float hs;
        long lcb, pc;
    //Phuong Thuc
    void nhap()
    {
        cin >> maNV;
        cin.ignore();
        getline(cin, hoTen);
        cin >> hs >> lcb >> pc;
    }
    void ghiFile(ofstream& f1)
    {
        f1 << maNV << endl;
        f1 << hoTen << endl;
        f1 << hs << endl;
        f1 << lcb << endl;
        f1 << pc << endl;
    }
    void docFile(ifstream& f2)
    {
        f2 >> maNV;
        f2.ignore();
        getline(f2, hoTen);
        f2 >> hs >> lcb >> pc;
    }
    void intongluong()
    {
        cout << "Tong luong cua " << hoTen << " la: " << hs * lcb + pc << endl;
    }
};

bool cmp(NhanVien a, NhanVien b)
{
    return (a.hs * a.lcb + a.pc) < (b.hs * b.lcb + b.pc);
}

int main(){
    ofstream f1("NhanVien.txt");
    ifstream f2("NhanVien.txt");
    NhanVien a[10];

    // Ghi vao File
     for (int i = 0; i < 10; i++)
     {
         a[i].nhap();
         a[i].ghiFile(f1);
     }
    for (int i = 0; i < 10; i++)
    {
        a[i].docFile(f2);
        a[i].intongluong();
    }
    sort(a, a + 10, cmp);
    cout << "Nhan vien co tong luong cao nhat la: " << a[9].hoTen << endl;
    cout << "Nhan vien co tong luong thap nhat la: " << a[0].hoTen << endl;
    f2.close();
    f1.close();
    return 0;
}


