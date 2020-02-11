#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

#define ll long long
#define PI 3.14159265358979323846

struct Point {
    ll x;
    ll y;
    double angle;
    int id;
};

bool compare(Point p1, Point p2) {
    return p1.angle < p2.angle;
}

int main() {
    int n;
    cin >> n;
    Point p[n];

    ll min_x = 1e10l;
    int first = 0;

    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;

        if (a < min_x) {
            min_x = a;
            first = i;
        }

        p[i].x = a;
        p[i].y = b;
        p[i].id = i;
    }

    for (int i = 0; i < n; i++) {
        if (p[i].id == first) {
            p[i].angle = -1e10f;
        } else if (p[i].x == p[first].x) {
            p[i].angle = (p[i].y > p[first].y) ? 90 : -90;
        } else {
            p[i].angle = atan((double) (p[i].y - p[first].y) / (p[i].x - p[first].x)) * 180.0 / PI;
        }
    }

    sort(p, p + n, compare);

    cout << first + 1 << " " << p[n / 2].id + 1 << endl;

    return 0;
}