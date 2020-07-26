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
using namespace std;

#define N 100
#define EPS 1e-9

int arr[N];

//int solve(int l, int r) {
//	int diff = INT_MAX;
//	for (int k = l + 1; k < r; ++k)
//		if (abs(x - k) < diff)
//			diff = x;
//}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int x, n, best, x0, x1;
	cin >> x >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	if (n == 0) {
		cout << x << '\n';
	} else if (n == 1) {
		if (arr[0] == x) cout << x - 1 << '\n';
		else cout << x << '\n';
	} else {
		sort(arr, arr + n);

		if (binary_search(arr, arr+n, x)) {
			int lo = x - 1;
			int hi = x + 1;
			int ans = -1;
			best = INT_MAX;
			while (true) {
				x0 = abs(x - lo);
				x1 = abs(x - hi);

				if (x0 > best || x1 > best) break;

				if (!binary_search(arr, arr + n, lo)) {
					if (x0 <= best) {
						best = x0;
						ans = lo;
						if (x1 >= best)
							break;
					}
				}
				
				if (!binary_search(arr, arr + n, hi)) {
					if (x1 < best) {
						best = x1;
						ans = hi;
						if (x0 > best)
							break;
					}
				}


				--lo;
				++hi;
			}
			cout << ans << '\n';
		} else {
			cout << x << '\n';
		}
		
	}

}
