#include <iostream>

using namespace std;

bool compare(pair<char, int> a, pair<char, int> b) {
    if(a.first != b.first) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

const int MAX_N = 100001;
pair<char, int> arr[MAX_N];

void sort(int left, int right) {
    int i = left;
    int j = right;

    pair<char, int> x = arr[(left + right) / 2];

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
    string s;
    int l;
    cin >> l >> s;
    l--;

    int n = s.length();

    for (int i = 0; i < n; i++) {
        arr[i].first = s[i];
        arr[i].second = i;
    }

    sort(0, n - 1);

    int ans[n];

    for (int i = 0; i < n; i++) {
        ans[i] = arr[i].second;
    }

    int cur = l;

    for (int i = 0; i < n; i++) {
        cout << arr[cur].first;
        cur = ans[cur];
    }

    return 0;
}