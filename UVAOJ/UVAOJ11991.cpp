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
#define N 10000
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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k, v;
    while (cin >> n >> m) {
        vector<pair<int, int>> vect;
        for (int i = 0; i < n; ++i) {
            cin >> v;
            vect.push_back(make_pair(v, i+1));
        }
       stable_sort(vect.begin(), vect.end(), sort_pred);
        for (int i = 0; i < m; ++i) {
            cin >> k >> v;
            auto it = lower_bound(vect.begin(), vect.end(), v, lb_pred);
            int pos = (it-vect.begin()) + k-1;
            if (pos < n && vect[pos].first == v)
                printf("%d\n", vect[pos].second);
            else
                printf("%d\n", 0);
        }
    }
 }
