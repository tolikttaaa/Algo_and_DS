#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int s = 0;
    int mx = 0;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        s += a;
        if (s < 0) {
            s = 0;
        }
        if (s > mx) {
            mx = s;
        }
    }

    cout << mx;
    return 0;
}