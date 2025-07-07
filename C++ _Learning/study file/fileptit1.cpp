#include <iostream>
#include <fstream>
#include <set>
#include <map>
using namespace std;

int main(int argc, char* argv[])
{
    ifstream f;
    f.open("DATA.in");
    set<int> se1, se2;
    map<int, int> mp;
    int n, m;
    f >> n >> m;
    while (n--)
    {
        int k;
        f >> k;
        se1.insert(k);
    }
    while (m--)
    {
        int k;
        f >> k;
        se2.insert(k);
    }
    for (auto c: se1)
        mp[c]++;
    for (auto c: se2)
        mp[c]++;
    for (auto c: mp)
        if (c.second == 2)
            cout << c.first << " ";
    f.close();
    return 0;
}
