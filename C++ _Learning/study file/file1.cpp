#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{
    ofstream f1("Check.txt");
    int k, f;
    cin >> k >> f;
    f1 << k << endl << f;
    f1.close();
    ifstream f2("Check.txt");
    string k1;
    string ff;
    f2 >> k1 >> ff;
    cout << k1 + f1;
    f2.close();
}

