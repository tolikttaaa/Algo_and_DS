#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge {
    int a, b;
    double r, c;
};

vector<edge> edges;
double nodes[101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, s;
    double v;

    cin >> n >> m >> s >> v;
    nodes[s] = v;

    for (int i = 0; i < m; i++) {
        int a, b;
        double rab, cab, rba, cba;

        cin >> a >> b >> rab >> cab >> rba >> cba;

        edges.push_back({a, b, rab, cab});
        edges.push_back({b, a, rba, cba});
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < edges.size(); j++) {
            nodes[edges[j].b] = max((nodes[edges[j].a] - edges[j].c) * edges[j].r, nodes[edges[j].b]);
        }
    }
    for (int i = 0; i < edges.size(); i++) {
        if ((nodes[edges[i].a] - edges[i].c) * edges[i].r > nodes[edges[i].b] + 0.000001) {
            cout << "YES";
            exit(0);
        }
    }

    cout << "NO";
}