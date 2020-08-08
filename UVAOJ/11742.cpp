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
const int N = 8;

template <class T> T gcd(T a, T b) {
	if (b == 0) { return a; }
	return gcd(b, a % b);
}

int rule[20][3];
int arr[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, a, b, c, ans;
	bool ok;
	while (cin >> n >> m) {
		if (n + m == 0) break;
		memset(rule, 0, sizeof rule);
		for (int i = 0; i < n; ++i) {
			arr[i] = i;
		}

		for (int i = 0; i < m; ++i) {
			cin >> rule[i][0]>>rule[i][1]>>rule[i][2];
		}

		if (m == 0) {
			ans = 1;
			for (int i = 1; i <= n; ++i)
				ans *= i;
		} else {
			ans = 0;
			do {
				ok = true;
				for (int i = 0; i < m; ++i) {
					a = b = -1;
					// cout << "a " << rule[i][0] << " b " << rule[i][1] << '\n';
					for (int k = 0; k < n; ++k) {
						if (rule[i][0] == arr[k]) {
							a = k;
						}
						if (rule[i][1] == arr[k]) {
							b = k;
						}
					}
					
					if(rule[i][2] > 0) ok &= abs(a - b) <= rule[i][2];
					else ok &= abs(a - b) >= abs(rule[i][2]);
					if (!ok) break;
				}
				if (ok) ++ans;
			} while (next_permutation(arr, arr + n));
		}
		cout << ans << '\n';

	}
}