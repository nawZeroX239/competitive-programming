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

int row[N];
int sol[100][N];
int solcnt;

bool place(int r, int c) {
    for (int col = 0; col < c; ++col)
        if (row[col] == r || abs(row[col] - r) == abs(c - col))
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
    int tc;
    cin >> tc;
    backtrack(0);
    while(tc) {
        int r, c;
        cin >> r >> c;
        cout << "SOLN       COLUMN\n";
        cout << " #      1 2 3 4 5 6 7 8\n\n";
        for (int i = 0, j=1; i < solcnt; ++i) {
            if (sol[i][c-1] == r-1) {
                if(j>9) cout << j << "     ";
                else
                    cout << ' '<<j << "     ";
                for (int k = 0; k < N; ++k)
                    cout << setw(2) << sol[i][k]+1;
                cout << '\n';
                ++j;
            }
        }
        --tc;
        if (tc) cout << '\n';
    }
}