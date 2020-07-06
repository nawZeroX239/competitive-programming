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
    int n, m, sz, _min;
    cin >> n;
    string nl, buf, s;
    getline(cin, nl);
    for (; n; --n) {
        cin >> m;
        getline(cin, nl);
        vector<int> v;
        
        _min = INT_MAX;
        while (getline(cin, buf)) {
            if (buf.length() == 0) break;
            sz = 0;
            stringstream ss(buf);
            while (ss >> s) {
                ++sz;
            }
            _min = min(sz, _min);
            v.push_back(sz);
        }
        int first = 1;
        for(int i=0; i<v.size(); ++i)
            if (v[i] == _min) {
                if (first) {
                    cout<<i+1; 
                    first = 0;
                } else cout<<' '<<i+1;
            }
        cout << '\n';
    }
 }
