#include <iostream>

using namespace std;

int main() {
    int test_count;
    cin >> test_count;

    for (int i = 0; i < test_count; i++) {
        long int n, k;
        cin >> n >> k;
        long m = n / k;
        long ost = n % k;
        long res = (k - ost) * m * (n - m);     //usual commands
        res += ost * (m + 1) * (n - m - 1);     //unusual commands
        cout << res / 2 << endl;
    }

    return 0;
}