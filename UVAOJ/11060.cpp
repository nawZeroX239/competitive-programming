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
#define N  10000

// translation
int tx[] = { 0, 0, 1,  1, 1, -1, -1, -1 };
int ty[] = {-1, 1, 0, -1, 1,  0, -1,  1 };
using namespace std;

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, tc = 1, indeg[100];
    string s, b1, b2, drinks[100];
    vector<vector<int>> adj;
    priority_queue<int> q;
    unordered_map<string, int> mp;

    while (cin >> n) {
        mp.clear();  adj.clear(); adj.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> drinks[i];
            mp[drinks[i]] = i;
            indeg[i] = 0;
        }

        cin >> m;
        for (int i = 0; i < m; ++i) {
            cin >>b1>>b2;
            adj[mp[b1]].push_back(mp[b2]);

        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < adj[i].size(); ++j) ++indeg[adj[i][j]];
        }

        for (int i = 0; i < n; ++i) {
            if (indeg[i] == 0) q.push(-1 * i);
        }

        cout << "Case #" << tc++ << ": Dilbert should drink beverages in this order:";

        while (q.size()) {
            int u = -1 * q.top(); q.pop();
            for (int i = 0; i < adj[u].size(); ++i) {
                int v = adj[u][i];
                --indeg[v];
                if (indeg[v] == 0) {
                    q.push(-1 * v);
                }
            }
            cout << ' ' << drinks[u];
        }


        cout << ".\n\n";
    }
}