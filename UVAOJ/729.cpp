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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, h, tc;
    cin >> tc;
    while(tc) {
        cin >> n >> h;
        string s;
        for (int i = 0; i < n-h; ++i)
            s.push_back('0');
        for (int i = h; i; --i)
            s.push_back('1');
        set<string> K;
        do {
            K.insert(s);
        } while (next_permutation(s.begin(), s.end()));
        for (auto k : K)
            cout << k << '\n';
        --tc;
        if (tc)cout << '\n';
    }

}