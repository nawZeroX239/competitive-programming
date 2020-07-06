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

int arr[N];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int _case, n, m, o, x, y;
    cin >> _case;
    
    for (; _case; --_case) {
        cin >> n >> m;
        unordered_map<int, int> dp;
        UnionFind uf(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        for (int i = 0; i < m; ++i) {
            cin >> x >> y;
            // cout << "x: " << x << "y: " << y << '\n';
            uf.unionSet(x, y);
        }

        for (int i = 0; i < n; ++i) {
            int id = uf.findSet(i);
            auto it = dp.find(id);

            if (it == dp.end())
                dp[id] = arr[i];
            else
                it->second += arr[i];
        }
        int ans = 1;
        for (auto it = dp.begin(); it != dp.end(); ++it)
            if (it->second != 0) {
                ans = 0;
                break;
            }

        if (ans) {
            cout << "POSSIBLE\n";
        } else {
            cout << "IMPOSSIBLE\n";
        }
    }
}
