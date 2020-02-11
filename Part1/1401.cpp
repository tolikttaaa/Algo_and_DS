#include <iostream>

using namespace std;

int arr[512][512];
int m = 3;

// simple `pow` for small numbers
int get_n(int n) {
    int ans = 1;

    while (n-- > 0) {
        ans *= 2;
    }

    return ans;
}

void generate(int n, int x, int y, int hx, int hy) {
    if (n == 2) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                if (x + i != hx || y + j != hy) {
                    arr[x + i][y + j] = m++ / 3;
                }
            }
        }

        return;
    }

    // Middle triangle
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (x + i * n / 2 > hx || hx >= x + i * n / 2 + n / 2 || y + j * n / 2 > hy || hy >= y + j * n / 2 + n / 2) {
                arr[x + n / 2 - 1 + i][y + n / 2 - 1 + j] = m++ / 3;
            }
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            // Block contains the hole
            if (x + i * n / 2 <= hx && hx < x + i * n / 2 + n / 2 && y + j * n / 2 <= hy && hy < y + j * n / 2 + n / 2) {
                generate(n / 2, x + i * n / 2, y + j * n / 2, hx, hy);
            // Does not contain the hole
            } else {
                generate(n / 2, x + i * n / 2, y + j * n / 2, x + n / 2 - 1 + i, y + n / 2 - 1 + j);
            }
        }
    }
}

int main() {
    int n, px, py;
    cin >> n >> px >> py;

    n = get_n(n);

    generate(n, 0, 0, px - 1, py - 1);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}