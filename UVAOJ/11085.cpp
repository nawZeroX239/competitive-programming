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
#define N 8
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


int arr[N];
int row[N];
int sol[100][N];
int solcnt;

bool place(int r, int c) {
    for (int i = 0; i < c; ++i)
        if (row[i] == r || abs(row[i] - r) == abs(i - c))
            return false;
    return true;
}

void backtrack(int c) {
    if (c == N) {
        for (int i = 0; i < N; ++i)
            sol[solcnt][i] = row[i];
        ++solcnt;
        return;
    }

    for(int r=0; r<N; ++r)
        if (place(r, c)) {
            row[c] = r;
            backtrack(c + 1);
        }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    backtrack(0);
    int tc = 1, x, best, cum;

    while (cin >> x) {
        arr[0] = x - 1;
        for (int i = 1; i < N; ++i) {
            cin >> x; arr[i] = x - 1;
        }
        best = INT_MAX;
        for (int i = 0; i < solcnt; ++i) {
            cum = 0;
            for (int col = 0; col < N; ++col) {
                if (arr[col] != sol[i][col]) {
                    ++cum;
                }
            }
            best = min(best, cum);
        }
        cout << "Case " << tc << ": " << best << '\n';
        ++tc;
    }
}