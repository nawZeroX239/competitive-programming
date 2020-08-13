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
const int N = 8;
template <class T> T gcd(T a, T b) {
	if (b == 0) { return a; }
	return gcd(b, a % b);
}

int g[N][N];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc, n, ans, sum;
	cin >> tc;
	while (tc--) {
		int pick[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
		cin >> n;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> g[i][j];
			}
		}

		ans = INT_MAX;
		do {
			sum = 0;
			for(int r = 0; r<n; ++r){
				sum += g[r][pick[r]];
			}
			ans = min(ans, sum);

		} while (next_permutation(pick, pick + n));

		cout << ans << '\n';
	}

}