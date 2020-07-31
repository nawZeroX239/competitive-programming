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
const int N = 1e5+5;

template <class T>
T gcd(T a, T b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

bool isPrime(int x) {
	for (int d = 2; d * d <= x; d++) {
		if (x % d == 0)
			return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int m;
	cin >> m;
	if (isPrime(m)) cout << m << '\n';
	else {
		for (m = m + 1; !isPrime(m); ++m);
		cout << m << '\n';

	}
}
		