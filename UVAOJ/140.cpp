#include <iostream>
#include <string>
#include <algorithm>
#include <utility> 
#include <unordered_set>
#include <vector>
#include <list> 
#include <string>
#include <iterator> 
#include <deque>
#include <array>
#include <forward_list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <climits>
#include <bitset>
#include <numeric>
using namespace std;


const long double PI = 3.14159265358979323846264338327950;
const double EPS = 1e-9;
const int N = 'Z' - 'A';

template <class T> T gcd(T a, T b) {
    if (b == 0) { return a; }
    return gcd(b, a % b);
}

template <class T> bool isPrime(T x) {
    for (T d = 2; d * d <= x; d++) { if (x % d == 0) return false; }
    return true;
}


bool g[N][N];
vector<int> vert;
vector<int> sol;

int best;

void solve() {
    int dx;
    do {
        dx = INT_MIN;
        for (int i = 0; i < vert.size() - 1; ++i) {
            for (int j = i + 1; j < vert.size(); ++j) {
                if (g[vert[i]][vert[j]] && g[vert[j]][vert[i]])
                    dx = max(dx, j - i);
            }
        }
        if (dx < best) {
            best = dx;
            sol.assign(vert.begin(), vert.end());
        }
    } while (next_permutation(vert.begin(), vert.end()));


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int u, v;
    string s;
    while (cin >> s) {
        if (s[0] == '#')
            break;

        set<int> S;
        memset(g, 0, sizeof g);

        for (int i = 0; i < s.length(); i++) {
            u = s[i] - 'A';
            S.insert(u);
            i += 2;
            while (i<s.length()) {
                if (s[i] == ';') break;
                v = s[i++] - 'A';
                S.insert(v);
                g[u][v]= g[v][u] = true;
            }
        }

        vert.resize(S.size());
        auto it = S.begin();
        for (int i = 0; i < vert.size(); ++i, ++it) {
            vert[i] = *it;
        }

        best = INT_MAX;
        solve();
        for (int i = 0; i < sol.size(); ++i)
            cout << (char)(sol[i] + 'A') << ' ';
        cout <<"-> "<< best << '\n';
    }

}
