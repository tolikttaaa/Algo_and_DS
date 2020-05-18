#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> color(100, -1);
vector<int> edge[100];
int n;

void btf(int st) {
    queue<int> q;
    q.push(st);
    color[st] = 0;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int i = 0; i < edge[v].size(); i++) {
            int to = edge[v][i];

            if (color[v] == color[to]) {
                cout << "-1";
                exit(0);
            }

            if (color[to] == -1) {
                color[to] = !color[v];
                q.push(to);
            }
        }
    }
}

int main(){
    cin >> n;

    for (int i = 0; i < n; i++) {
        int e = -1;
        while (e != 0) {
            cin >> e;

            if (e != 0) {
                edge[i].push_back(e - 1);
                edge[e - 1].push_back(i);
            }
        }
    }

    btf(0);

    for (int i = 0; i < n; i++){
        if (color[i] == -1) {
            btf(i);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << color[i];
    }

    return 0;
}