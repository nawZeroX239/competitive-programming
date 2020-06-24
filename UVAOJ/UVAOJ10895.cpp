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

int arr[10001][10001];


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int n, m, r, c, num;
    while (cin >> n >> m) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; ++i) {
            cin >> c;
            for (int j = 0; j < c; ++j) {
                cin >> num;
                adj[i].push_back(num - 1);
            }

            for (int j = 0; j < c; ++j)
                cin >> arr[i][adj[i][j]];
        }
        // cout << "*END*\n";
        int col[10001] = {};
        cout << m << ' ' << n << '\n';
        for (int i = 0; i < m; ++i) {
            vector<int> v(n);
            int sz = 0;
            for (int j = 0; j < n; ++j) {
                if (col[j] < adj[j].size() && adj[j][col[j]] == i) {
                    v[j] = i;
                    ++col[j];
                    ++sz;
                } else {
                    v[j] = -1;
                }
            }
            if (sz == 0) {
                cout << sz << "\n\n";
                continue;
            }
            cout << sz;
            for (int i = 0; i < n; ++i) {
                if (v[i] != -1) {
                    cout << ' ' << i+1;
                }
            }
            cout << '\n';
            int first = 1;
            for (int j = 0; j < n; ++j) {
                if (v[j] != -1) {
                    if (first) {
                        cout << arr[j][v[j]];
                        first = 0;
                    }  else {
                        cout << ' ' << arr[j][v[j]];
                    }
                }
            }
            cout << '\n';
            
        }

    }
}
