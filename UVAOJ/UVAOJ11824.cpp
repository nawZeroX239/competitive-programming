#include <algorithm>
#include <array>
#include <bitset>
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

#define EPS 1e-100
#define N 100000
#define ll long long
#define pi pair<ll, ll>

using namespace std;
int land[N];

bool comparator(int& a, int& b) { return a > b; }

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int _case, amt, ans, k, n;
	int threshold = 5000000;
	cin >> _case;
	while (_case) {
	    n = 0;
		while (cin >> amt) {
			if (amt == 0)
				break;
			land[n++] = amt;
		}
		sort(land, land + n, comparator);

		for (ans = 0, k = 1; k < n + 1; ++k) {
			ans = ans + 2 * pow(land[k - 1], k);
			if (ans > threshold)
				break;
		}

		if (k > n)
			cout << ans << '\n';
		else
			cout << "Too expensive\n";
		--_case;
	}
}
