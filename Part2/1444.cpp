#include <iostream>
#include <cmath>

#define PI 3.141592653589793238462643383279502884197169399375105820974

/**
 * Для начала нужно понять, что всегда можно обойти все тыквы.
 * Как это достигается? Найдем угол до каждой тыквы от начальной.
 * Отсортируем углы. При одинаковом угле сначала элефпотам должен посетить ту, которая ближе к нему,
 * потом по прямой дойти до остальных.
 * Т.к. все тыквы отсортированы по величине угла от начальной, то пока элефпотам идет до следущей тыквы, он не
 * пересечет свои следы (т.к. элефпотам еще ни разу не был ни в одной из точек плоскости, угол которой выше,
 * чем тот, на котором лежит предыдущая тыква)
 */

struct point {
    long long int x;
    long long int y;
    double angle;
    int num;
};
int n;
point p[30001];

int get_start() {
    double max_a = 90 - p[n - 1].angle + 270 + p[1].angle;
    int max_i = 1;
    for (int i = 1; i < n - 1; ++i) {
        if (p[i + 1].angle - p[i].angle > max_a) {
            max_a = p[i + 1].angle - p[i].angle;
            max_i = i + 1;
        }
    }
    return max_i;
}

int comp(const void *v1, const void *v2) {
    const point *p1 = (point *) v1;
    const point *p2 = (point *) v2;
    if (p1->angle - p2->angle > 1e-10) {
        return 1;
    } else if (p1->angle - p2->angle < -1e-10) {
        return -1;
    } else {
        if ((p1->x - p[0].x) * (p1->x - p[0].x) + (p1->y - p[0].y) * (p1->y - p[0].y) >
            (p2->x - p[0].x) * (p2->x - p[0].x) + (p2->y - p[0].y) * (p2->y - p[0].y)) {
            return 1;
        } else {
            return -1;
        }
    }
}

int main() {
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i].x;
        std::cin >> p[i].y;
        p[i].num = i;
        if (i == 0) {
            p[i].angle = INT64_MIN;
            continue;
        }
        if (p[i].x - p[0].x == 0) {
            p[i].angle = (p[i].y > p[0].y) ? 90 : -90;
            continue;
        }
        p[i].angle = atan((double) (p[i].y - p[0].y) / (p[i].x - p[0].x)) * 180.0 / PI;
        if ((p[i].x - p[0].x) <= 0) {
            p[i].angle -= 180;
        }
    }

    std::qsort(p, n, sizeof(point), comp);

//    for (int i = 0; i < n; ++i) {
//        std::cout << "x: " << p[i].x << " y: " << p[i].y << " angle: " << p[i].angle << " #" << p[i].num << std::endl;
//    }

    std::cout << n << std::endl;

    int k = get_start();

    std::cout << 1 << std::endl;

    for (int i = k; i < n; ++i) {
        std::cout << p[i].num + 1 << std::endl;
    }

    for (int i = 1; i < k; ++i) {
        std::cout << p[i].num + 1 << std::endl;
    }
    return 0;
}