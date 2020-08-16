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

const int N = 1e5;
const long double EPS = 1e-9;

using namespace std;

template <class T>
T gcd(T a, T b) 
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

int arr[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, t, ans, lo, hi, sum;
	cin >> n >> t;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	
	ans = lo = hi = 0;
	sum = 0;
	while (hi < n) {
		while (sum <= t && hi < n) {
			sum += arr[hi++];
			ans = max(ans, hi - lo - 1);
		}
		// cout << lo << ' ' << hi << ' ' << sum << '\n';

		while(sum > t && lo <= hi) {
			sum -= arr[lo++];
		}
		// cout << lo << ' ' << hi << ' '<<sum<<'\n';
		ans = max(ans, hi - lo);
	}
	

	cout << ans << '\n';
}