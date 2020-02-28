#include <iostream>

using namespace std;

double a1, b1;
long long a, b;

int main() {
    cin >> a1 >> b1;
    a = a1 * 1e9 + 0.2;
    b = b1 * 1e9 + 0.2;
    cout << a / b << "\n";
}