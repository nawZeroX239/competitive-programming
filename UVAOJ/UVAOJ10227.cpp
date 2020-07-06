#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <forward_list>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define EPS 1e-100
#define N 10001
#define ll long long
#define pi pair<ll, ll>

using namespace std;

inline void newline() { cout << '\n'; }
inline void split(vector<string>& vect, string& str, char delim) {
    string each;
    for (auto it = str.begin(); it != str.end(); ++it) {
        if (*it != delim)
            each.push_back(*it);
        else {
            vect.push_back(each);
            each.clear();
        }
    }
    if (each.size()) vect.push_back(each);
}

class UnionFind {
private:
    vector<int> p, rank, setSize;
    int numSets;
public:
    UnionFind(int _N) {
        p.assign(_N, 0); for (int i = 0; i < _N; ++i) p[i] = i;
        rank.assign(_N, 0);
        setSize.assign(_N, 1);
        numSets = _N;
    }

    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

    int numDisjointSets() { return numSets; }  
    int sizeOfSet(int i) { return setSize[findSet(i)]; }

    void unionSet(int i, int j) {
        if (isSameSet(i, j)) return;
        int x = findSet(i), y = findSet(j);
        if (rank[x] > rank[y]) swap(x, y);
        p[x] = y;
        if (rank[x] == rank[y]) ++rank[y];
        setSize[y] += setSize[x];
        --numSets;
    }
};

// int arr[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int _case, p, t, a, b, ans;
    string line;
    cin >> _case;
    getline(cin, line);
    while (_case) {
        cin >> p >> t;
        getline(cin, line);
        vector<unordered_set<int>> vect(p);
        while (getline(cin, line)) {
            if (line.length() == 0) break;
            vector<string> inputs;
            split(inputs, line, ' ');
            a = stoi(inputs[0]) - 1;
            b = stoi(inputs[1]) - 1;
            vect[a].insert(b);
        }
        
        vector<int> c(p, 0);
        int ans = p;
        for (int i = 0; i < vect.size() - 1; ++i) {
            for (int j = i+1; j < vect.size(); ++j) {
                if (vect[i].size() - vect[j].size() || c[j])
                    continue;
                auto it = vect[i].begin();
                for (; it != vect[i].end(); ++it) {
                    if (vect[j].find(*it) == vect[j].end())
                        break;
                }
                if (it == vect[i].end()) {
                    c[j] = 1;
                    --ans;
                }
            }
        }
        cout << ans << '\n';
        --_case;
        if (_case) newline();
    }
}
