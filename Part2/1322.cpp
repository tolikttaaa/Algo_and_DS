#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    string s;
    int l;
    cin >> l >> s;
    l--;
    map<char, int> c; //сколько раз буква встречается в тексте
    map<char, int> d; //сколько раз встречается все буквы, идущие в алфовитном порядке до текущей
    vector<int> p; //сколько раз буква на позиции i уже встречалась ранее в массиве
    vector<int> t; //тот самый магический вектор
    for (char &i : s) {
        auto it = c.find(i);
        if (it != c.end()){
            p.push_back(it->second);
            it->second++;
        } else {
            c.insert(std::pair<char, int>(i, 1));
            p.push_back(0);
        }
    }
    int sum = 0;
    for (auto &it : c) {
        d.insert(std::pair<char, int>(it.first, sum));
        sum += it.second;
    }
    unsigned long int j = 0;
    for (char &li : s){
        t.push_back(d.find(li)->second + p[j]);
        ++j;
    }
    char res[s.length()];
    for(unsigned long int i = s.length() - 1; i != -1 ; --i) {
        res[i] = s[l];
        l = t[l];
    }
    for (char &cr : res) {
        std::cout << cr;
    }
    return 0;
}