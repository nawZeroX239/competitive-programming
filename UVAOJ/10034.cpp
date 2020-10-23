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

#define INF 999999999
#define  EPS 1e-9

using namespace std;

typedef tuple<int, int, int> iii;
typedef vector<int> vi;

// translation
int x[] = { 0, 0, 1, -1 };
int y[] = { -1, 1, 0, 0 };

template <class T> T gcd(T a, T b) {
    if (b == 0) { return a; }
    return gcd(b, a % b);
}

int toInt(string& s) {
    stringstream ss(s);
    int x;
    ss >> x;
    return x;
}

double dist(pair<double, double> &a, pair<double, double> &b) {
    double c = a.first - b.first, d = a.second - b.second;
    return sqrt(c * c + d * d);
}

// Steven Halim CP3
// UFDS code from ch2/ownlibrary/ufds.cpp
// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
class UnionFind {                                // OOP style
private:
    vi p, rank, setSize;                           // vi p is the key part
    int numSets;
public:
    UnionFind(int N) {
        p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
        rank.assign(N, 0);                           // optional speedup
        setSize.assign(N, 1);                        // optional feature
        numSets = N;                                 // optional feature
    }
    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j) {
        if (isSameSet(i, j)) return;                 // i and j are in same set
        int x = findSet(i), y = findSet(j);          // find both rep items
        if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter' than y
        p[x] = y;                                    // set x under y
        if (rank[x] == rank[y]) ++rank[y];           // optional speedup
        setSize[y] += setSize[x];                    // combine set sizes at y
        --numSets;                                   // a union reduces numSets
    }
    int numDisjointSets() { return numSets; }
    int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int tc, n, m;
    pair<double, double> coord[100];

    cin >> tc;
    while (tc--) {
        cin >> n;
        vector<tuple<double, int, int>> edgeList;
        UnionFind uf(n);
        for (int i = 0; i < n; ++i) {
            cin >> coord[i].first >> coord[i].second;
            // cout << coord[i].first << ' ' << coord[i].second << '\n';
        }

        for (int i = 0; i < n-1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                edgeList.emplace_back(dist(coord[i], coord[j]), i, j);
            }
        }

        sort(edgeList.begin(), edgeList.end());
        double ans = 0;
        m = 0;
        for (int i = 0; i < edgeList.size(); ++i) {
            int u = get<1>(edgeList[i]), v = get<2>(edgeList[i]);
            if (!uf.isSameSet(u, v)) {
                ++m;
                ans += get<0>(edgeList[i]);
                uf.unionSet(u, v);
                if (m == n - 1) break;
                
            }
        }
        cout <<setprecision(2)<<fixed<< ans << '\n';
        if (tc) cout << '\n';
    }
    
}