#include <iostream>
#include <algorithm>

using namespace std;

bool compare(pair<char, int> a, pair<char, int> b) {
    if(a.first != b.first) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main() {
    string s;
    int l;
    cin >> l >> s;
    l--;

    int n = s.length();
    pair<char, int> arr[n];

    for (int i = 0; i < n; i++) {
        arr[i].first = s[i];
        arr[i].second = i;
    }

    sort(arr, arr + n, compare);

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