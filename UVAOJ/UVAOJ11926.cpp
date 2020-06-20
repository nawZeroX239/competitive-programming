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
#define N 1000001
#define ll long long
#define pi pair<ll, ll>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, ans, start, finish, period;
	while (cin >> n >> m) {
		if (n == 0 && m == 0)
			break;
		bitset<N> slot;
		ans = 1;
		for (; n; --n) {
			cin >> start >> finish;
			if (ans == 0)
				continue;
			for (int i = start; i < finish; ++i) {
				if (slot[i]) {
					ans = 0;
					break;
				}
				slot[i] = 1;
			}
		}

		for (; m; --m) {
			cin >> start >> finish >> period;
			if (ans == 0)
				continue;
			for (int k = 0; k+finish <= N; k += period) {
				for (int i = k+start; i < k + finish; ++i) {
					if (slot[i]) {
						ans = 0;
						break;
					}
					slot[i] = 1;
				}

				if (ans == 0)
					break;
			}
		}

		if (ans)
			cout << "NO CONFLICT" << '\n';
		else
			cout << "CONFLICT" << '\n';
	}
}
