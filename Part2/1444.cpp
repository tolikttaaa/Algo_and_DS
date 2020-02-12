#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

#define ll long long
#define PI 3.14159265358979323846
#define EPS 1e-10

struct Point {
    ll x;
    ll y;
    double angle;
    int id;
    double len;
};

bool compare(Point p1, Point p2) {
    if (abs(p1.angle - p2.angle) > EPS) {
        return p1.angle < p2.angle;
    }

    return p1.len < p2.len;
}

int main() {
    int n;
    Point p[30001];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i].x;
        cin >> p[i].y;
        p[i].id = i;

        if (i == 0) {
            p[i].angle = INT64_MIN;
            p[i].len = 0;
            continue;
        }

        if (p[i].x == p[0].x) {
            p[i].angle = (p[i].y > p[0].y) ? 90 : -90;
            p[i].len = abs(p[i].y - p[0].y);
            continue;
        }

        p[i].angle = atan((double) (p[i].y - p[0].y) / (p[i].x - p[0].x)) * 180.0 / PI;
        if (p[i].x <= p[0].x) {
            p[i].angle -= 180;
        }

        p[i].len = abs(sqrt((double) (pow((p[i].x - p[0].x), 2) + pow((p[i].y - p[0].y), 2))));
    }

    sort(p, p + n, compare);

    double max_a = 360 + p[1].angle - p[n - 1].angle;
    int k = 1;

    for (int i = 1; i < n - 1; i++) {
        if (p[i + 1].angle - p[i].angle > max_a) {
            max_a = p[i + 1].angle - p[i].angle;
            k = i + 1;
        }
    }

    cout << n << endl;
    cout << 1 << endl;

    for (int i = k; i < n; i++) {
        cout << p[i].id + 1 << endl;
    }

    for (int i = 1; i < k; i++) {
        cout << p[i].id + 1 << endl;
    }

    return 0;
}