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
// #define N 1005
#define ll long long
#define pi pair<ll, ll>

using namespace std;
// int arr[N];

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
    UnionFind(int N) {
        p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
        rank.assign(N, 0);
        setSize.assign(N, 1);
        numSets = N;
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



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int _case, n, m, id, u, v;
    string f1, f2;
    cin >> n;
    while (n) {
        UnionFind FF(100000);
        unordered_map<string, int> table;
        id = 1;
        cin >> m;
        for (; m; --m) {
            cin >> f1 >> f2;
            auto it1 = table.find(f1);
            auto it2 = table.find(f2);
            if (it1 == table.end()) {
                u = table[f1] = id;
                ++id;
            } else u = it1->second;

            if (it2 == table.end()) {
                v = table[f2] = id;
                ++id;
            } else v = it2->second;
           FF.unionSet(u, v);
           cout << FF.sizeOfSet(u) << '\n';
        }

        --n;
    }
   
}
