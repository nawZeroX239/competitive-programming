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


int arr[N], n, p;

bool solve(int k, int sum) {
	if (sum == n)
		return true;
	for (int i = k; i < p; ++i) {
		if (sum + arr[i] == n) {
			return true;
		}
		if (sum + arr[i] < n) {
			if (solve(i + 1, sum + arr[i]))
				return true;
		}
	}

	return false;
}

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> p;
		for (int i = 0; i < p; ++i) {
			cin >> arr[i];
		}
		if (solve(0, 0)) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
	}
}