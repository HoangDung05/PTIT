#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

class HocVien
{
public:
    string ma, ten, lop, ngaysinh;
    float diem;
    int static m;
    HocVien()
    {
        ma = "";
        ten = "";
        lop = "";
        ngaysinh = "";
        diem = 0;
    }
    friend istream &operator >> (istream &is, HocVien &hv)
    {
        if (m < 10)
            hv.ma = "B20DCCN00" + to_string(m);
        else
            hv.ma = "B20DCCN0" + to_string(m);
        is.ignore();
        getline(is, hv.ten);
        is >> hv.lop;
        is >> hv.ngaysinh >> hv.diem;
        m++;
        return is;
    }
    friend ostream &operator << (ostream &os, HocVien &hv)
    {
        for (int i = 0; i < hv.ten.length(); i++)
        {
            hv.ten[i] = tolower(hv.ten[i]);
        }
        stringstream ss(hv.ten);
        string s;
        hv.ten = "";
        while (ss >> s)
        {
            s[0] = toupper(s[0]);
            hv.ten += s + " ";
        }
        // hv.ten = hv.ten - " ";
        if (hv.ngaysinh[1] == '/')
            hv.ngaysinh.insert(0, "0");
        if (hv.ngaysinh[4] == '/')
            hv.ngaysinh.insert(3, "0");
        os << hv.ma << " " << hv.ten << hv.lop << " " << hv.ngaysinh << " " << fixed << setprecision(2) << hv.diem << endl;
        return os;
    }
};

int cmp(HocVien a, HocVien b)
{
    return a.diem > b.diem;
}

void sapxep(HocVien ds[], int N)
{
    sort(ds, ds + N, cmp);
}

int HocVien::m = 1;
int main(){
    HocVien ds[50];
    int N, i;
    cin >> N;
    for(i=0;i<N;i++){
        cin >> ds[i];
    }
    sapxep(ds, N);
    for(i=0;i<N;i++){
        cout << ds[i];
    }
    return 0;
}

// 2
// quACh Van tUaN
// D20DCCN01-B
// 2/12/2002
// 2.17
// Le tHI mAi
// D20DCCN02-B
// 1/9/2002
// 3.0