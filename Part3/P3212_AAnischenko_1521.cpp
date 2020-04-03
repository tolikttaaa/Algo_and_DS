#include <vector>
#include <iostream>

using namespace std;

class List {
    vector<int> v;
    int size, bottom, step, current, remains;

    static inline int next_pow(int x) {
        x--;

        for(int i = 1; i <= 16; i *= 2) {
            x |= x >> i;
        }

        return x + 1;
    }

    static int log(int x) {
        int res = 0;

        while (x > 0) {
            x /= 2;
            res++;
        }

        return res;
    }

    static inline int pow2(int n) {
        int res = 1;

        while (n-- > 0) {
            res *= 2;
        }

        return res;
    }

    inline int parent(const int& node) const {
        return node / 2;
    }

    inline int right(const int& node) const {
        return node * 2 + 1;
    }

    inline int left(const int& node) const {
        return node * 2;
    }

    inline bool isInTree(const int& node) const {
        return node <= bottom + size && node > 0;
    }

public:
    List(int n, int step) {
        this->size = n;
        this->remains = n;
        this->step = step;
        this->current = step;

        v.resize(next_pow(n * 2));
        int height = log(n - 1);
        bottom = pow2(height) - 1;

        for(int i = bottom + 1; i <= bottom + n; i++) {
            v[i] = 1;
        }

        for(int i = bottom; i >= 1; i--) {
            v[i] = (isInTree(left(i)) ? v[left(i)] : 0)
                   + (isInTree(right(i)) ? v[right(i)] : 0);
        }
    }

    int remaining() {
        return remains;
    }

    int getNext() {
        remains--;
        if (remains + 1 == size) {
            return current;
        }

        int node = bottom + current;
        while (node > 0) {
            v[node]--;
            node = parent(node);
        }

        node = bottom + current;

        int k = step;
        enum source { left_direction, right_direction, up_direction };
        source source = right_direction;

        while(k) {
            int lc = left(node);
            int rc = right(node);

            if (source == up_direction) {
                if (isInTree(lc) && k > v[lc]) {
                    k -= v[lc];
                    source = up_direction;
                    node = rc;
                } else if(!isInTree(lc) && k == v[node]) {
                    k--;
                } else {
                    source = up_direction;
                    node = lc;
                }
            } else if (source == right_direction) {
                source = node == right(parent(node)) ? right_direction : left_direction;
                node = parent(node);
            } else {
                if(isInTree(rc) && k > v[rc]) {
                    source = node == right(parent(node)) ? right_direction : left_direction;
                    k -= v[rc];
                    node = parent(node);
                } else {
                    node = rc;
                    source = up_direction;
                }
            }

            if(!isInTree(node)) {
                node = bottom + 1;
                k -= v[node];
                source = right_direction;
            }
        }

        return current = node - bottom;
    }
};

int main() {
    int n, k;
    cin >> n >> k;

    List list(n, k);

    while(list.remaining()) {
        int ans = list.getNext();
        cout << ans << " ";
    }

    return 0;
}