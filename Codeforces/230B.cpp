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
const long long N = 1e6;

template <class T> T gcd(T a, T b) {
	if (b == 0) { return a; }
	return gcd(b, a % b);
}

template <class T> bool isPrime(T x) {
	if (x < 2) return false;
	if (x == 2) return true;
	for (T d = 3; d * d <= x; d+=2) { if (x % d == 0) return false; }
	return true;
}

bool prime[N];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	long long m;
	cin >> n;

	prime[1] = true;
	for (int p = 2; p * p <= N; ++p) {
		if (!prime[p]) {
			for (int i = p * p; i <= N; i += p) {
				prime[i] = true;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		cin >> m;
		int s = sqrt(m);
		if ((long long)s*s == m && !prime[s]) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
	}
}