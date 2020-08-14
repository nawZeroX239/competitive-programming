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
const int N = 1001;
template <class T> T gcd(T a, T b) {
	if (b == 0) { return a; }
	return gcd(b, a % b);
}

int arr[N];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k, cnt, ans;
	bool a, b;
	cin >> n >> m >> k;
	for (int i = 0; i <= m; ++i) {
		cin >> arr[i];
	}
	
	ans = 0;
	for (int i = 0; i < m; ++i) {
		cnt = 0;
		for (int j = 0; j < n; ++j) {
			cnt += ((arr[i] >> j) & 1) ^ ((arr[m] >> j) & 1);
		}
		if (cnt <= k) ++ans;
		//cout << cnt << '\n';
	}
	cout << ans << '\n';
}
