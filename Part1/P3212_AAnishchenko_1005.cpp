#include <iostream>

using namespace std;

int main() {
    int ans = 100000;

    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int m = 0; m < 1 << n; m++) {
        int s1 = 0;
        int s2 = 0;

        int cur = m;
        for (int j = 0; j < n; j++) {
            if (cur % 2 == 1) {
                s1 += arr[j];
            } else {
                s2 += arr[j];
            }
            cur /= 2;
        }

        ans = min(ans, abs(s1 - s2));
    }

    cout << ans;
    return 0;
}