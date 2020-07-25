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

#define N 1000
#define EPS 1e-9

using namespace std;

int n, x, y, z, sol, temp;
int start;

int solve() {
	sol = INT_MAX;
	for (x = 1; x <= N; ++x) {
		if (x > n) break;
		for (y = 1; y <= N; ++y) {
			if (y > n || x*y > n ) break;
			for (z = 1; z <= N; ++z) {
				temp = x * y * z;
				if (temp >= n) {
					if(temp == n)
						sol = min(sol, (x * y + x * z + y * z)<<1);
					break;
				}	
			}
		}
	}

	return sol;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		cout << solve() << '\n';
	}
}