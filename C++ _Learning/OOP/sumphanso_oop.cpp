#include <iostream>
using namespace std;
typedef long long ll;

int gcd(int a, int b)
{
    while (b != 0)
        {
            int res = a % b;
            a = b;
            b = res;
        }
}

class PhanSo
{
private:
    int tu, mau;
public:
    PhanSo(ll a, ll b)
    {
        this->a = a
        mau = 1;
    }
    friend istream &operator >> (istream &is, PhanSo &ps)
    {
        is >> ps.tu >> ps.mau;
        return is;
    }
    friend ostream &operator << (ostream &os, PhanSo ps)
    {
        os << ps.tu << "/" << ps.mau;
    }
    friend PhanSo &operator +(PhanSo a, PhanSo b)
    {
        PhanSo t(1,1);
        t.tu = a.tu*b.mau + b.tu*a.mau;
        t.mau = a.mau * b.mau;

    }
};


int main() {
    PhanSo p(1,1), q(1,1);
    cin >> p >> q;
    cout << p + q;
    return 0;
}