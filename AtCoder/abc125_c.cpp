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

#define EPS 1e-9
#define PI 3.14159265358979323846264338327950
const int N = 1e5 + 5;


int L[N], R[N];
template <class T>
T gcd(T a, T b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> L[i];
		R[i] = L[i];
	}

	for (int i = 1; i < n; ++i) {
		L[i] = gcd(L[i], L[i - 1]);
	}

	for (int i = n; i > 0; --i) {
		R[i] = gcd(R[i], R[i + 1]);
	}


	int ans = 0;

	for (int i = 1; i <= n; ++i) {
		ans = max(ans, gcd(L[i - 1], R[i + 1]));
	}
	cout << ans << '\n';
	
}
