#include <iostream>

using namespace std;

int cube[8];
string dict[8] = {"A", "B", "C", "D", "E", "F", "G", "H"};

void dec(int first, int second) {
    int cnt = min(cube[first], cube[second]);

    for (int i = 0; i < cnt; i++) {
        cout << dict[first] + dict[second] + "-" << endl;
    }

    cube[first] -= cnt;
    cube[second] -= cnt;
}

void print_cube() {
    for (int i = 0; i < 8; i++) {
        cerr << cube[i] << " ";
    }
    cerr << endl;
}

void inc(int first, int second, int cnt) {
    for (int i = 0; i < cnt; i++) {
        cout << dict[first] + dict[second] + "+" << endl;
    }

    cube[first] += cnt;
    cube[second] += cnt;
}

int main() {
    for (int i = 0; i < 8; i++)
        cin >> cube[i];

    if (cube[0] + cube[2] + cube[5] + cube[7] != cube[1] + cube[3] + cube[4] + cube[6]) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    // обнуляем вершину А (cube[0])
    if (cube[0] > 0) {
        dec(0, 1);
        dec(0, 3);
        dec(0, 4);
        inc(1, 5, cube[0]);
        dec(0, 1);
    }

    // обнуляем вершину B (cube[1])
    // вершину A использовать нельзя
    if (cube[1] > 0) {
        dec(1, 2);
        dec(1, 5);
        inc(5, 6, cube[1]);
        dec(1, 5);
    }

    // обнуляем вершину D (cube[3])
    // вершину A использовать нельзя
    if (cube[3] > 0) {
        dec(3, 2);
        dec(3, 7);
        inc(6, 7, cube[3]);
        dec(3, 7);
    }

    // обнуляем вершину E (cube[4])
    // вершину A использовать нельзя
    if (cube[4] > 0) {
        dec(4, 5);
        dec(4, 7);
        inc(6, 7, cube[4]);
        dec(4, 7);
    }

    // обнуляем вершину G (cube[6])
    // вершиныы H, C, F обнуляться автоматически
    if (cube[6] > 0) {
        dec(6, 2);
        dec(6, 5);
        dec(6, 7);
    }
}