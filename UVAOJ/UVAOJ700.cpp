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

#define EPS 1e-2
#define N 30001
#define ll long long
#define pi pair<ll, ll>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	int _case, a, b, best;
	int years[21];
	int dx[21];
	_case = 1;
	while (cin >> n) {
		if (n == 0)
			break;
		best = -1;
		for (int i = 0; i < n; ++i) {
			cin >> years[i] >> a >> b;
			dx[i] = b - a;
			best = max(best, years[i]);
		}
		int all=1;
		int ans;
		for (ans = best; ans < 10000; ++ans) {
			all = 1;
			for (int i = 0; i < n; ++i) {
				if ((ans - years[i]) % dx[i])
					all = 0;
			}
			if (all)
				break;
		}
		cout << "Case #" << _case<<":\n";
		if (all)
			cout << "The actual year is " << ans << ".\n";
		else
			cout << "Unknown bugs detected.\n";
		cout << '\n';
		++_case;
	}

}
