#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

const int inf = 1e9 + 7;
const int width = 10;
const int max_n = 50000;

long long pw[width]; // 1, 10, 100 ...
int cost[width]; // The costs of the prefix matching

struct Node {
    std::vector<std::pair<int, Node*>> v; // Neighbors <cost, Node*>
    Node* parent{}; // Of the shortest path
    int d{}; // Shortest path cost
    bool visited{};
} nodes[max_n];

unordered_map<long long, Node*> m;

int getDigit(long long num, int i) {
    return (int) (num / pw[i] % 10);
}

long long setDigit(long long num, int i, int d) {
    return num - ((long long) getDigit(num, i)) * pw[i] + d * pw[i];
}

int matchPrefix(long long num1, long long num2) {
    int matched = 0;

    for (int i = width - 1; i >= 0; i--) {
        if (getDigit(num1, i) == getDigit(num2, i)) {
            matched++;
        } else {
            break;
        }
    }

    return matched;
}

// Adds this station into the graph at node #id
void add(long long num, int id) {
    vector<pair<int, Node*>> v;

    // Replace digit
    for (int i = 0; i < width; i++) {
        for (int d = 0; d < 10; d++) {
            auto num2 = setDigit(num, i, d);

            if (m.find(num2) != m.end()) {
                int c = cost[matchPrefix(num, num2)];
                v.emplace_back( c, (*m.find(num2)).second );
            }
        }
    }

    // Switch two digits
    for (int i = 0; i < width; i++) {
        for (int j = i + 1; j < width; j++) {
            int di = getDigit(num, i);
            int dj = getDigit(num, j);

            auto num2 = setDigit(setDigit(num, j, di), i, dj);

            if(m.find(num2) != m.end()) {
                int c = cost[matchPrefix(num, num2)];
                v.emplace_back( c, (*m.find(num2)).second );
            }
        }
    }

    m[num] = &nodes[id];

    for(auto p : v){
        p.second->v.emplace_back( p.first, &nodes[id] );
        nodes[id].v.emplace_back( p.first, p.second );
    }
}

// Dijkstra
void search(Node* start, int n) {
    using pin = pair<int, Node*>;
    priority_queue<pin, vector<pin>, greater<>> q;

    for (int i = 0; i < n; i++) {
        nodes[i].d = inf, nodes[i].visited = false;
    }
    start->d = 0;

    q.push( { 0, start } );
    while(!q.empty()) {
        auto p = q.top();
        q.pop();
        auto node = p.second;

        if (node->visited) {
            continue;
        }

        node->visited = true;

        for (auto it = node->v.begin(); it < node->v.end(); it++) {
            auto u = (*it).second;
            int cur_cost = (*it).first;

            if (!u->visited && u->d > node->d + cur_cost) {
                u->parent = node;
                u->d = node->d + cur_cost;
                q.push( { u->d, u });
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long b = 1;
    for (long long & i : pw) {
        i = b, b *= 10;
    }

    int n;

    cin >> n;
    for (int & i : cost) {
        cin >> i;
    }

    for (int i = 0; i < n; i++) {
        long long num;
        cin >> num;
        add(num, i);
    }

    vector<Node*> result;
    search(&nodes[0], n);

    if (!nodes[n - 1].visited) {
        cout << -1;
        return 0;
    }

    cout << nodes[n - 1].d << "\n";

    for (Node* node = &nodes[n - 1]; node; node = node->parent) {
        result.push_back(node);
    }

    cout << result.size() << "\n";

    for (auto it = result.rbegin(); it < result.rend(); it++) {
        cout << 1 + (*it-nodes) << " ";
    }
}