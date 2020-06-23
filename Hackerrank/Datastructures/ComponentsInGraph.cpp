#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
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
#define N 30001
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

    int get_min(unordered_set<int> items) {
        int lo = INT_MAX;
        for (auto it = items.begin(); it != items.end(); ++it)
            lo = min(setSize[*it], lo);

        return lo;
    }

    int get_max(unordered_set<int> items) {
        int hi = INT_MIN;
        for (auto it = items.begin(); it != items.end(); ++it)
            hi = max(setSize[*it], hi);

        return hi;
    }

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


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int n, u, v;
    cin >> n;
    UnionFind net(N);
    vector<int> vect;
    for (; n; --n) {
        cin >> u >> v;
        net.unionSet(u, v);
        vect.push_back(u);
    }

    unordered_set<int> items;

    for (auto it = vect.begin(); it != vect.end(); ++it)
        items.insert(net.findSet(*it));

    cout << net.get_min(items) << ' ' << net.get_max(items) << '\n';
}
