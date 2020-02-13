#include <iostream>
#include <cmath>

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

const int MAX_N = 30001;
Point arr[MAX_N];

bool compare(Point p1, Point p2) {
    if (abs(p1.angle - p2.angle) > EPS) {
        return p1.angle < p2.angle;
    }

    return p1.len < p2.len;
}

void sort(int left, int right) {
    int i = left;
    int j = right;

    Point x = arr[(left + right) / 2];

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
    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].x;
        cin >> arr[i].y;
        arr[i].id = i;

        if (i == 0) {
            arr[i].angle = INT64_MIN;
            arr[i].len = 0;
            continue;
        }

        if (arr[i].x == arr[0].x) {
            arr[i].angle = (arr[i].y > arr[0].y) ? 90 : -90;
            arr[i].len = abs(arr[i].y - arr[0].y);
            continue;
        }

        arr[i].angle = atan((double) (arr[i].y - arr[0].y) / (arr[i].x - arr[0].x)) * 180.0 / PI;
        if (arr[i].x <= arr[0].x) {
            arr[i].angle -= 180;
        }

        arr[i].len = abs(sqrt((double) (pow((arr[i].x - arr[0].x), 2) + pow((arr[i].y - arr[0].y), 2))));
    }

    sort(0, n - 1);

    double max_a = 360 + arr[1].angle - arr[n - 1].angle;
    int k = 1;

    for (int i = 1; i < n - 1; i++) {
        if (arr[i + 1].angle - arr[i].angle > max_a) {
            max_a = arr[i + 1].angle - arr[i].angle;
            k = i + 1;
        }
    }

    cout << n << endl;
    cout << 1 << endl;

    for (int i = k; i < n; i++) {
        cout << arr[i].id + 1 << endl;
    }

    for (int i = 1; i < k; i++) {
        cout << arr[i].id + 1 << endl;
    }

    return 0;
}