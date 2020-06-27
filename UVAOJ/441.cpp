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
#define N 13
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
    int n, m, p, q;
    int nl = 0;
    while (cin >> n) {
        if (n == 0) break;
        if (nl) puts("");
        for (int i = 0; i < n; ++i) 
            cin >> S[i];

        for (int a = 0; a < n - 5; ++a)
            for (int b = a + 1; b < n - 4; ++b)
                for (int c = b + 1; c < n - 3; ++c)
                    for (int d = c + 1; d < n - 2; ++d)
                        for (int e = d + 1; e < n - 1; ++e)
                            for (int f = e + 1; f < n; ++f)
                                printf("%d %d %d %d %d %d\n", S[a], S[b], S[c], S[d], S[e], S[f]);
        nl = 1;
    }
    
}