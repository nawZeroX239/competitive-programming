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

const int N = 100;
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

	long long n, m, x;
	set<long long> S;
	cin >> n >> m;
	
	x = n = n % m;
	S.insert(n);
	if (n == 0) {
		cout << n << '\n';
		return 0;
	}


	while (true) {
		n = abs(n - m);
		if (S.find(n) != S.end())
			break;
		x = min(x, n);
	}
	
	cout << x << '\n';
}