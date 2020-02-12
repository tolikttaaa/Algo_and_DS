#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long
#define ull unsigned long long

int main() {
    ll n;
    cin >> n;
    ull x[n];
    ull y[n];
    ull sum = 0l;

    for (ll i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    sort(x, x + n);
    sort(y, y + n);

    for (ll i = 1; i < n; i++) {
        sum += (x[i] - x[i - 1]) * i * (n - i);
        sum += (y[i] - y[i - 1]) * i * (n - i);
    }

    sum = 2l * sum / (n * (n - 1));
    cout << sum;

    return 0;
}