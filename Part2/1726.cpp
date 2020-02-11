#include <iostream>
#include <bits/stdc++.h>

/**
 * Т.к. люди ходят только параллельно оси ох и оу, то результат - это сумма расстояний между каждым домом с каждым
 * по х и у координатам.
 * Сохраним все координаты и отсортируем.
 * Между каждой парой соседних домов узнаем растояние r и узнаем какое количество человек по ней проходит
 * (а именно i челоаек справа и (n - i) слева). Следовательно, суммарно по этой тропинке пройдут r*i*(n-i)
 * Итоговую сумму разделим на количество тропинок между домами для получения среднего результата.
 */

bool comp(long long a, long long b) {
    return a < b;
}

int main() {
    long long n;
    std::cin >> n;
    long long x_s[n];
    long long y_s[n];
    long long sum = 0;
    for (long long i = 0; i < n; ++i) {
        std::cin >> x_s[i] >> y_s[i];
    }
    std::sort(x_s, x_s + n, comp);
    std::sort(y_s, y_s + n, comp);

    for (long long i = 0; i < n - 1; ++i) {
        sum += (x_s[i + 1] - x_s[i]) * (i + 1) * (n - i - 1);
        sum += (y_s[i + 1] - y_s[i]) * (i + 1) * (n - i - 1);
    }

    sum = 2 * sum / (n * (n - 1));
    std::cout << sum;
    return 0;
}