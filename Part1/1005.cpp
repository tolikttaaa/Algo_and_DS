#include <iostream>
#include <vector>

using namespace std;

int main() {
    int ans = 100000;

    vector<int> a;
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int q;
        cin >> q;
        a.push_back(q);
    }

    for (int m = 0; m < 1 << n; m++) {
        int s1 = 0;
        int s2 = 0;

        int cur = m;
        for (int j = 0; j < n; j++) {
            if (cur % 2 == 1) {
                s1 += a[j];
            } else {
                s2 += a[j];
            }
            cur /= 2;
        }

        ans = min(ans, abs(s1 - s2));
    }

    cout << ans;
    return 0;
}