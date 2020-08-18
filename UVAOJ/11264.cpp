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
const int N = 1000;
template <class T> T gcd(T a, T b) {
	if (b == 0) { return a; }
	return gcd(b, a % b);
}

int coins[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T, n, ans;
	long long c, sum;
	bool ok;

	cin >> T;
	while (T--) {
		cin >> n;

		for (int i = 0; i < n; ++i) {
			cin >> coins[i];
		}

		sum = coins[0], ans = 1;
		for (int i = 1; i < n-1; i++) {
			if (sum + coins[i] < coins[i + 1]) {
				sum += coins[i];
				++ans;
			}
		}

		cout << ans+1 << '\n';
	}
}
