#include <iostream>
#include <cmath>
using namespace std;

#define ll long long
#define PI 3.14159265358979323846

struct Point {
    ll x;
    ll y;
    double angle;
    int id;
};

const int MAX_N = 10001;
Point arr[MAX_N];

bool compare(Point p1, Point p2) {
    return p1.angle < p2.angle;
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

    ll min_x = 1e10l;
    int first = 0;

    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;

        if (a < min_x) {
            min_x = a;
            first = i;
        }

        arr[i].x = a;
        arr[i].y = b;
        arr[i].id = i;
    }

    for (int i = 0; i < n; i++) {
        if (arr[i].id == first) {
            arr[i].angle = -1e10f;
        } else if (arr[i].x == arr[first].x) {
            arr[i].angle = (arr[i].y > arr[first].y) ? 90 : -90;
        } else {
            arr[i].angle = atan((double) (arr[i].y - arr[first].y) / (arr[i].x - arr[first].x)) * 180.0 / PI;
        }
    }

    sort(0, n - 1);

    cout << first + 1 << " " << arr[n / 2].id + 1 << endl;

    return 0;
}