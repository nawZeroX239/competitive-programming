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

#define EPS 1e-9
#define N 22
#define NN 8
struct ticket {
	int i, j, load;
};

using namespace std;
int cap, n, m, best;
int counts[NN];
ticket arr[N];

bool ok() {
	for (int i = 0; i < NN; ++i)
		if (counts[i] > cap) return false;
	return true;
}

void backtrack(int k, int earn) {
	best = max(best, earn);
	while (k < m) {
		int local = arr[k].load;
		for (int i = arr[k].i; i < arr[k].j; ++i) {
			counts[i] += arr[k].load;
			local = max(local, counts[i]);
		}

		if (local<= cap)
			backtrack(k + 1, earn + arr[k].load * (arr[k].j - arr[k].i));

		for (int i = arr[k].i; i < arr[k].j; ++i)
			counts[i] -= arr[k].load;
		++k;
	}
}

int main() {
	while (scanf("%d%d%d", &cap, &n, &m)) {
		if (cap + n + m == 0) break;
		
		for (int i = 0; i < m; ++i) {
			// cin >> arr[i].i >> arr[i].j >> arr[i].load;
			scanf("%d%d%d", &arr[i].i, &arr[i].j, &arr[i].load);
		}
		best = 0;
		memset(counts, 0, sizeof counts);
		backtrack(0, 0);
		printf("%d\n", best);
	}
}
