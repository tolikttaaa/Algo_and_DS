#include <iostream>
#include <map>

using namespace std;

struct Tree {
    Tree() {
        this->name = "";
        this->children = {};
    }

    Tree(string name) {
        this->name = name;
        this->children = {};
    }

    string name;
    map< string, Tree * > children;
};

void print_tree(Tree *cur_tree, int depth) {
    for (int i = 0; i < depth - 1; i++) {
        cout << " ";
    }
    if (!cur_tree->name.empty()) {
        cout << cur_tree->name << endl;
    }
    depth++;
    for (auto &child_tree : cur_tree->children) {
        print_tree(child_tree.second, depth);
    }
}

int main() {
    int n;
    cin >> n;

    Tree *tree_root = new Tree();

    for (int i = 0; i < n; i++) {
        string path;
        cin >> path;
        string dir;

        Tree *cur_tree = tree_root;

        for (int j = 0; j <= path.size(); j++) {
            if (path[j] == '\\' || path[j] == '\0') {
                auto dir_tr = cur_tree->children.find(dir);

                if (dir_tr == cur_tree->children.end()) {
                    Tree *new_tree = new Tree(dir);
                    cur_tree->children[dir] = new_tree;
                    cur_tree = cur_tree->children.find(dir)->second;
                } else {
                    cur_tree = dir_tr->second;
                }

                dir = "";
            } else {
                dir += path[j];
            }
        }

    }

    print_tree(tree_root, 0);

    return 0;
}