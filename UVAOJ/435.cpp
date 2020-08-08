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
const int N = 20;

template <class T> T gcd(T a, T b) {
	if (b == 0) { return a; }
	return gcd(b, a % b);
}

int arr[N], cnt[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int tc, n, total, lim;
	cin >> tc;
	while (tc--) {
		cin >> n;
		memset(cnt, 0, sizeof cnt);
		lim = 0;
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
			lim += arr[i];
		}
		lim /= 2;
		for (int mask = 1; mask <= (1 << n) - 1; ++mask) {
			total = 0;
			for (int i = 0; i < n; ++i) {
				if ((mask >> i) & 1) {
					total += arr[i];
				}
			}
			if (total > lim) {
				for (int i = 0; i < n; ++i) {
					if ((mask >> i) & 1) {
						if(total-arr[i] <= lim)
						cnt[i]++;
					}
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			cout << "party " << i + 1 << " has power index " << cnt[i] << '\n';
		}
		
		cout << '\n';
	}
}