#include <iostream>
#include <fstream>
using namespace std;

struct NhanVien
{
    char ms[20];
    char hoten[50];
    float hs;
    long lcb, pc;
};

void NhapNV()
{
    //1. Mo file
    fstream f;
    f.open("NhanVien.txt", ios::out | ios::binary);

    //2. Ghi du lieu vao file o che do nhi phan
    int n; cin >> n;
    while (n--)
    {
        cin.ignore();
        NhanVien nv;
        cin >> nv.ms;
        cin.ignore();
        gets(nv.hoten);
        cin >> nv.hs >> nv.lcb >> nv.pc;
        f.write(reinterpret_cast<char*>(&nv), sizeof(NhanVien));
    }

    //3. Dong file
    f.close();
}

void DocNV()
{
    //1. Mo file
    fstream f;
    f.open("NhanVien.txt", ios::in | ios::binary);

    //2. Doc du lieu du file o che do nhi phan
    NhanVien nv;
    while (f.read(reinterpret_cast<char*>(&nv), sizeof(NhanVien)))
    {
        cout << nv.ms << " " << nv.hoten << ": " << nv.hs*nv.lcb+nv.pc << endl;
    }
}

int main(int argc, char* argv[])
{
    // NhapNV();
    DocNV();
    return 0;

}
