#include <iomanip>
#include <iostream>
using namespace std;

class SinhVien
{
private:
    string maSV, hoTen, lop, ngaySinh;
    float gpa;
public:
    SinhVien()
    {
        maSV = "B20DCCN001";
        hoTen = "";
        lop = "";
        ngaySinh = "";
        gpa = 0;
    }

    friend istream &operator >> (istream &is, SinhVien &sv)
    {
        getline(is, sv.hoTen);
        is >> sv.lop;
        is >> sv.ngaySinh >> sv.gpa;
        return is;
    }
    friend ostream &operator << (ostream &os, SinhVien &sv)
    {
        if (sv.ngaySinh[1] == '/')
            sv.ngaySinh.insert(0, "0");
        if (sv.ngaySinh[4] == '/')
            sv.ngaySinh.insert(3, "0");
        os << sv.maSV << " " << sv.hoTen << " " << sv.lop << " " << sv.ngaySinh << " " << fixed << setprecision(2) << sv.gpa;
        return os;
    }
};

int main(){
    SinhVien ds[50];
    int N, i;
    cin >> N;
    for(i=0;i<N;i++){
        cin >> ds[i];
    }
    for(i=0;i<N;i++){
        cout << ds[i];
    }
    return 0;
}