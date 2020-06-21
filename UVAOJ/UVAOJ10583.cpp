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

inline void split(vector<string>& vect, string& str, char delim) {
    string each;
    for (auto it = str.begin(); it != str.end(); ++it)
        if (*it != delim) {
            each.push_back(*it);
        } else {
            vect.push_back(each);
            each.clear();
        }

    if (each.size())
        vect.push_back(each);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int _case,  n, m, i, j;
    _case = 1;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        UnionFind sets(n);
        for (; m; --m) {
            cin >> i >> j;
            sets.unionSet(i-1, j-1);
        }
        cout << "Case " << _case << ": " << sets.numDisjointSets() << '\n';
        ++_case;
    }
}
