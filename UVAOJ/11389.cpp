#include <iostream>
#include <string>
#include <algorithm>
#include <utility> 
#include <unordered_set>
#include <vector>
#include <list> 
#include <string>
#include <iterator> 
#include <iomanip>
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
const int N = 100;
template <class T> T gcd(T a, T b) {
	if (b == 0) { return a; }
	return gcd(b, a % b);
}


int m[N], e[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, d, r, ans;

	while (cin >> n >> d >> r) {
		if (n == 0 && d == 0 && r == 0) break;
		for (int i = 0; i < n; ++i) {
			cin >> m[i];
		}
		for (int i = 0; i < n; ++i) {
			cin >> e[i];
		}
		
		sort(m, m + n);
		sort(e, e + n, greater<int>());
		ans = 0;
		for (int i = 0; i < n; ++i) {
			if (m[i] + e[i] > d) {
				ans += (m[i] + e[i] - d) * r;
			}
		}
		cout << ans << '\n';
	}
}
