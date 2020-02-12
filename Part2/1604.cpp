#include <iostream>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

int main() {
    int n;
    cin >> n;

    pair<int, int> arr[n];

    int sum = 0;

    for (int i = 0; i < n; i++) {
        arr[i].first = i + 1;
        cin >> arr[i].second;
        sum += arr[i].second;
    }

    sort(arr, arr + n, compare);

    /*
    while (p[0].second > 0) {
        cout << p[0].first << " ";
        p[0].second--;

        if (p[1].second > 0) {
            cout << p[1].first << " ";
            p[1].second--;

            for (int j = 1; j < n - 1; j++) {
                if (p[j].second < p[j + 1].second) {
                    int t = p[j].second;
                    p[j].second = p[j + 1].second;
                    p[j + 1].second = t;

                    t = p[j].first;
                    p[j].first = p[j + 1].first;
                    p[j + 1].first = t;
                } else {
                    break;
                }
            }
        }

        for (int j = 0; j < n - 1; j++) {
            if (p[j].second < p[j + 1].second) {
                int t = p[j].second;
                p[j].second = p[j + 1].second;
                p[j + 1].second = t;

                t = p[j].first;
                p[j].first = p[j + 1].first;
                p[j + 1].first = t;
            } else {
                break;
            }
        }
    }
    */

    int ans[sum];

    if (arr[0].second > (sum + 1) / 2) {
        bool done = false;
        int j = 1;
        int i = n - 1;
        while (j < sum) {
            ans[j] = arr[i].first;
            arr[i].second--;
            if (arr[i].second == 0) {
                i--;
            }

            j += 2;
            if (j > sum - 1 && !done) {
                j = 0;
                done = true;
            }
        }
    } else {
        bool done = false;
        int j = 0;
        int i = 0;

        while (j < sum) {
            ans[j] = arr[i].first;
            arr[i].second--;

            if (arr[i].second == 0) {
                i++;
            }

            j += 2;

            if (j > sum - 1 && !done) {
                j = 1;
                done = true;
            }
        }
    }

    for (int i = 0; i < sum; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
