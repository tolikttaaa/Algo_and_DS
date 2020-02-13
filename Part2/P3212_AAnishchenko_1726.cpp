#include <iostream>

using namespace std;

#define ll long long
#define ull unsigned long long

const int MAX_N = 100001;
ull x[MAX_N];
ull y[MAX_N];

void sort_x(int left, int right) {
    int i = left;
    int j = right;

    ull mid = x[(left + right) / 2];

    while (i <= j) {
        while (x[i] < mid) {
            i++;
        }
        while (mid < x[j]) {
            j--;
        }

        if (i <= j) {
            swap(x[i], x[j]);

            i++;
            j--;
        }
    }

    if (i < right) {
        sort_x(i, right);
    }
    if (left < j) {
        sort_x(left, j);
    }
}

void sort_y(int left, int right) {
    int i = left;
    int j = right;

    ull mid = y[(left + right) / 2];

    while (i <= j) {
        while (y[i] < mid) {
            i++;
        }
        while (mid < y[j]) {
            j--;
        }

        if (i <= j) {
            swap(y[i], y[j]);

            i++;
            j--;
        }
    }

    if (i < right) {
        sort_y(i, right);
    }
    if (left < j) {
        sort_y(left, j);
    }
}

int main() {
    ll n;
    cin >> n;
    ull sum = 0l;

    for (ll i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    sort_x(0, (int) n - 1);
    sort_y(0, (int) n - 1);

    for (ll i = 1; i < n; i++) {
        sum += (x[i] - x[i - 1]) * i * (n - i);
        sum += (y[i] - y[i - 1]) * i * (n - i);
    }

    sum = 2l * sum / (n * (n - 1));
    cout << sum;

    return 0;
}