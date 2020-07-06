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


int arr[N][N];
int row[N];
int sol[100][N];
int solcnt;

bool good(int r, int c) {
    for (int col = 0; col < c; ++col)
        if (row[col] == r || abs(row[col] - r) == abs(col - c))
            return false;
    return true;
}

void backtrack(int c) {
    if (c == N) {
        for (int i = 0; i < N; ++i)
            sol[solcnt][i] = row[i];
        ++solcnt;
    } else {
        for (int r = 0; r < N; ++r)
            if (good(r, c)) {
                row[c] = r;
                backtrack(c + 1);
            }
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, ans, cum;
    cin >> n;
    backtrack(0);
    
    for (; n; --n) {
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                cin >> arr[i][j];
        ans = 0;
        for (int i = 0; i < solcnt; ++i) {
            cum = 0;
            for (int col = 0; col < N; ++col) {
                cum += arr[sol[i][col]][col];
            }
            ans = max(ans, cum);
        }
        cout << setw(5)<< ans<<'\n';
    }

    
}