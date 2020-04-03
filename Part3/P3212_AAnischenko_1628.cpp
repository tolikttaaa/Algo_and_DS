#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool comp1(pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first) {
        return a.first < b.first;
    } else {
        return a.second < b.second;
    }
}

bool comp2(pair<int, int> a, pair<int, int> b) {
    if (a.second != b.second) {
        return a.second < b.second;
    } else {
        return a.first < b.first;
    }
}

int main() {
    int m, n, k;
    int res = 0;

    cin >> m >> n >> k;

    vector<pair<int, int>> point;
    vector<pair<int, int>> single_point;

    for (int i = 0; i < k; ++i) {
        pair<int, int> p;
        cin >> p.first >> p.second;
        p.first--;
        p.second--;
        point.push_back(p);
    }

    for (int i = 0; i < m; i++) {
        pair<int, int> p = {i, -1};
        pair<int, int> p2 = {i, n};
        point.push_back(p2);
        point.push_back(p);
    }

    for (int i = 0; i < n; i++) {
        pair<int, int> p = {-1, i};
        pair<int, int> p2 = {m, i};
        point.push_back(p2);
        point.push_back(p);
    }

    sort(point.begin(), point.end(), comp1);

    for (int i = 0; i < point.size() - 1; i++) {
        if (point[i].first == point[i + 1].first) {
            if (point[i + 1].second - point[i].second - 1 > 1) {
                res++;
            } else if (point[i + 1].second - point[i].second - 1 == 1) {
                pair<int, int> p(point[i].first, point[i].second + 1);
                single_point.push_back(p);
            }
        }
    }

    sort(point.begin(), point.end(), comp2);

    for (int i = 0; i < point.size() - 1; i++) {
        if (point[i].second == point[i + 1].second) {
            if (point[i + 1].first - point[i].first - 1 > 1) {
                res++;
            } else if (point[i + 1].first - point[i].first - 1 == 1) {
                pair<int, int> p(point[i].first + 1, point[i].second);
                single_point.push_back(p);
            }
        }
    }

    sort(single_point.begin(), single_point.end(), comp1);

    if (single_point.size() > 1) {
        for (int i = 0; i < single_point.size() - 1; i++) {
            if (single_point[i] == single_point[i + 1]) {
                res++;
                i++;
            }
        }
    }

    cout << res;

    return 0;
}