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
const int N = 100;

template <class T>
T gcd(T a, T b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<string, int> mp;
	string s;
	int n, m;
	m = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		++mp[s];
		m = max(m, mp[s]);
	}
	for (auto it = mp.begin(); it != mp.end(); ++it) {
		if (it->second == m)
			cout << it-> first << '\n';
	}
}
