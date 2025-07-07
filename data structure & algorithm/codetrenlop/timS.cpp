#include <iostream>

#include <iostream>
using namespace std;

void sum(int n) {
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += i;
    }
    cout << "The sum of the first " << n << " natural numbers is: " << sum << endl;
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    sum(n);

    return 0;
}