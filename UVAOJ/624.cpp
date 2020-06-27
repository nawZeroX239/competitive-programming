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
#define N 20
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

int goal, n, bestSum;
int arr[N];
vector<int> ans;
vector<int> best;

bool backtrack(int sum, int i) {
    if (sum == goal) {
        bestSum = sum;
        best.assign(ans.begin(), ans.end());
        return true;
    } else {
        for (int j = i; j < n; ++j)
            if (sum + arr[j] <= goal) {
                ans.push_back(arr[j]);
                if (backtrack(sum + arr[j], j + 1))
                    return true;
                if (bestSum == -1 || (bestSum > -1 && abs(sum + arr[j] - goal) < abs(bestSum - goal))) {
                    bestSum = sum + arr[j];
                    if (best.size()) best.clear();
                    best.assign(ans.begin(), ans.end());
                }
                ans.pop_back();
            }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int memo;
    while (cin >> goal>>n) {
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        bestSum = -1;
        backtrack(0, 0);
        for (auto it = best.begin(); it != best.end(); ++it)
             cout << *it << ' ';
        cout << "sum:" << bestSum << '\n';
        ans.clear();
        best.clear();
 
    }
}