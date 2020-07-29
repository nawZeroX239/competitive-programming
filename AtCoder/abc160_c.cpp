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
const int N = 2 * 1e5;


template <class T>
T gcd(T a, T b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

long long arr[N], L[N], R[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k, n;
	long long ans;

	cin >> k >> n;
	
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	L[0] = k - arr[n - 1] + arr[0];
	for (int i = 1; i < n; ++i)
		L[i] = arr[i] - arr[i - 1] + L[i -1];
	for (int i = n - 2; i >= 0; --i)
		R[i] = R[i + 1] + arr[i + 1] - arr[i];

	ans = LLONG_MAX;
	for (int i = 0; i < n - 1; ++i) {
		ans = min(ans, min(L[i] + R[i + 1], L[i] + R[i] - L[0]));
	}

	cout << ans << '\n';
}
