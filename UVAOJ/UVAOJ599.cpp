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
#define N ('Z' - 'A' + 1)
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


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    string line, nl;
    int _case, acorn, actual, delta;
    cin >> _case;
    getline(cin, nl);
    for (; _case; --_case) {
        vector<pair<int, int>> vect;
        UnionFind network(N);
        actual = network.numDisjointSets();
        while (getline(cin, line)) {
            if (line[0] == '*')
                break;
            network.unionSet(line[1] - 'A', line[3] - 'A');
        }
        getline(cin, line);
       
        acorn = 0;
        unordered_set<int> q;
        for (int i = 0; i < line.length(); ++i)
            if (line[i] >= 'A' && line[i] <= 'Z') {
                int k = network.findSet(line[i] - 'A');
                if (network.sizeOfSet(k) == 1)
                    ++acorn;
                else
                    q.insert(k);
            }
        
        printf("There are %d tree(s) and %d acorn(s).\n", q.size(), acorn);
    }
}
