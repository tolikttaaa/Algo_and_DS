#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;
    stack<int> balls;
    int tmp_max = 0;
    bool isCheater = false;

    for (int i = 0; i < n; i++) {
        int cur;
        cin >> cur;

        if (cur > tmp_max) {
            for (int j = tmp_max + 1; j < cur; j++) {
                balls.push(j);
            }

            tmp_max = cur;
        } else {
            if (cur == balls.top()) {
                balls.pop();
            } else {
                isCheater = true;
            }
        }
    }

    if (isCheater) {
        cout << "Cheater" << endl;
    } else {
        cout << "Not a proof" << endl;
    }

    return 0;
}