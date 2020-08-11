#include <iostream>
#include <string>
#include <algorithm>
#include <utility> 
#include <unordered_set>
#include <vector>
#include <list> 
#include <string>
#include <iterator> 
#include <iomanip>
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

template <class T> T gcd(T a, T b) {
	if (b == 0) { return a; }
	return gcd(b, a % b);
}


int getIndex(char ch) {
	return islower(ch) ?(ch - 'a' + 26): (ch - 'A');
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s, t;
	vector<vector<int>> vvi(52);

	int q, lo, hi;
	bool sol;
	cin >> s >> q;
	
	for (int i = 0; i < s.length(); ++i) {
		vvi[getIndex(s[i])].push_back(i);
	}

	while (q--) {
		cin >> t;
		lo = hi = -1;
		sol = true;
		for (int i = 0; i < t.length(); ++i) {
			int j = getIndex(t[i]);
			auto it = upper_bound(vvi[j].begin(), vvi[j].end(), hi);
			if (it == vvi[j].end()) {
				cout << "Not matched" << '\n';
				sol = false;
				break;
			}

			if (i == 0) {
				lo = *it;
			}
			hi = *it;
		}

		if (sol) {
			cout << "Matched " << lo << ' ' << hi << '\n';
		}
	}


}