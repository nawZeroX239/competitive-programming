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
const int N = 1e3;

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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	string s;
	unordered_map<string, int> mp;

	cin >> n;
	while (n--) {
		cin >> s;
		auto it = mp.find(s);
		if (it == mp.end()) {
			mp[s] = 0;
			cout << "OK" << '\n';
		} else {
			mp[s] = mp[s] + 1;
			cout << s << mp[s] << '\n';
		}
	}
}