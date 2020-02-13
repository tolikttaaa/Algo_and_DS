#include <iostream>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

const int MAX_K = 10001;
pair<int, int> arr[MAX_K];

void sort(int left, int right) {
    int i = left;
    int j = right;

    pair<int, int> x = arr[(left + right) / 2];

    while (i <= j) {
        while (compare(arr[i], x)) {
            i++;
        }
        while (compare(x, arr[j])) {
            j--;
        }

        if (i <= j) {
            swap(arr[i], arr[j]);

            i++;
            j--;
        }
    }

    if (i < right) {
        sort(i, right);
    }
    if (left < j) {
        sort(left, j);
    }
}

int main() {
    int k;
    cin >> k;

    int sum = 0;

    for (int i = 0; i < k; i++) {
        arr[i].first = i + 1;
        cin >> arr[i].second;
        sum += arr[i].second;
    }

    sort(0, k - 1);

    int ans[sum];

    if (arr[0].second > (sum + 1) / 2) {
        bool done = false;
        int j = 1;
        int i = k - 1;

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
