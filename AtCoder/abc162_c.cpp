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

const int N = 50;
const long double EPS = 1e-9;

using namespace std;

template <class T>
T gcd(T a, T b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, ans;
	cin >> n;
	ans = 0;
	for (int a = 1; a <= n; ++a) {
		for (int b = 1; b <= n; ++b) {
			for (int c = 1; c <= n; ++c) {
				ans += gcd(gcd(a, b), c);
			}
		}
	}
	cout << ans << '\n';
}