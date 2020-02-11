#include <bits/stdc++.h>

/**
 * Отсортируем массив.
 * Каждый раз будем работать с двумя максимальными по количеству элементами.
 * Каждый раз выводим первые 2 знака, уменьшаем сумму знаков этих типов.
 * В случае, если количество знаков в первых 2 элементах массива больше не максимальное
 * восстанавливаем упорядоченность массива, перемещая эти элементы в правильное место.
 *
 * Таким образом мы каждый раз ставим разные знаки до тех пор, пока не остануутся знаки одного типа,
 * для которых нельзя поставить пару.
 */

bool comp(std::pair<int, int> a, std::pair<int, int> b) {
    return a.second > b.second;
}

int main() {
    std::pair<int, int> p[10000];
    int n;
    std::cin >> n;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i].second;
        sum += p[i].second;
        p[i].first = i + 1;
    }
    sort(p, p + n, comp);
    while (sum--) {
        std::cout << p[0].first << " ";
        p[0].second--;
        if (p[1].second != 0) {
            std::cout << p[1].first << " ";
            p[1].second--;
        }
        int j = 1, k = 2;
        while (p[j].second < p[k].second) {
            int t = p[j].second;
            p[j].second = p[k].second;
            p[k].second = t;
            t = p[j].first;
            p[j].first = p[k].first;
            p[k].first = t;
            k++;
            j++;
            if (k == n) {
                break;
            }
        }
        j = 0, k = 1;
        while (p[j].second < p[k].second) {
            int t = p[j].second;
            p[j].second = p[k].second;
            p[k].second = t;
            t = p[j].first;
            p[j].first = p[k].first;
            p[k].first = t;
            k++;
            j++;
            if (k == n) {
                break;
            }
        }
        if (p[0].second <= 0) {
            return 0;
        }
    }
    return 0;
}