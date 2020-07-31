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
const int N = 24;
const int K = sqrt(50000);
template <class T> T gcd(T a, T b) {
	if (b == 0){ return a;} 
	return gcd(b, a % b);
}

template <class T> bool isPrime(T x) {
	for (T d = 2; d * d <= x; d++) { if (x % d == 0) return false; }
	return true;
}

int a, b, c;
int n, temp;

bool solve() {
	for (a = 0; a <= K; a++) {
		if (a * a > n)
			break;
		for (b = a; b <= K; ++b) {
			temp = a * a + b * b;
			if (temp > n)
				break;
			c = sqrt(n - temp);
			if (temp + c * c == n ) {
				if (a > b) swap(a, b);
				if (a > c) swap(a, c);
				if (b > c) swap(b, c);
				return true;
			}

		}
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;

		if (solve()) {
			cout << a << ' ' << b << ' ' << c << '\n';		
		} else {
			cout << -1 << '\n';
		}

	}
	
}
		