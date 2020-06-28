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

#define EPS 1e-9
#define N 25
#define PIXEL 1024
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

inline bool sort_pred(const pair<int, int>& left, const pair<int, int>& right) {
    return left.first<right.first;
}

inline bool lb_pred(const pair<int, int>& left, int right) {
    return left.first < right;
}
vector<vector<int>>adj;
bool visited[N][N];

int dfs(int i) {
    int best = 0;
    for (int j = 0; j < adj[i].size(); ++j) {
        int k = adj[i][j];
        if (visited[i][k] == false) {
            visited[k][i] = visited[i][k] = true;
            best = max(best, 1 + dfs(k));
            visited[k][i] = visited[i][k] = false;
        }
    }

    return best;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, u, v, ans;
    while (cin >> n >> m) {
        if (n == 0 && m == 0)
            break;
        adj.clear();
        adj.resize(n);
        for (int i = 0; i < m; ++i) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ans = 0;
        for (int i = 0; i < n; ++i) {
            memset(visited, false, sizeof visited);
            ans = max(ans, dfs(i));
        }
        cout << ans << '\n';
    }

}