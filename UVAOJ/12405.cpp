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
const int N = 105;
template <class T> T gcd(T a, T b) {
	if (b == 0) { return a; }
	return gcd(b, a % b);
}

bool area[N];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, tc, n, ans ;
	string s;
	cin >> T;
	for (tc = 1; tc <= T; ++tc) {
		memset(area, 0, sizeof area);
		cin >> n >> s;
		ans = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '.' && !area[i]) {
				area[i] = area[i + 1] = area[i + 2] = true;
				++ans;
			}
		}

		cout << "Case " << tc << ": " << ans << '\n';
	}
}
