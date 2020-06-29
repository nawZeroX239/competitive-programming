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

vector<string> dict;
string rules;

void backtrack(string str, int i) {
    if (i >= rules.length())
        cout << str << '\n';
    else if(rules[i] == '#'){
        for (string s : dict)
            backtrack(str + s, i + 1);
    } else {
        for (char ch = '0'; ch <= '9'; ++ch)
            backtrack(str +ch, i + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    while (cin >> n) {
        dict.clear();
        dict.resize(n);
        for (int i = 0; i < n; ++i)
            cin >> dict[i];
        cin >> m;
        rules.clear();
        cout << "--\n";
        for (int i = 0; i < m; ++i) {
            cin >> rules;
            backtrack("", 0);
        }
    }

}