#include <iostream>
#include <algorithm>
#include <climits>
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
#include <sstream>
#include <string>
#include <set>
#include <map>
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>

#define N 9

int arr[N];
using namespace std;

inline int get(const char c) {
	if (c == 'B') return 0;
	return (c == 'C' ? 2 : 1);
}

int main() {
	int b, g, c, ans, idx, x;
	const char* P[] = { "BCG", "BGC", "CBG", "CGB", "GBC", "GCB" };

	while (scanf("%d", &arr[0]) == 1) {
		for (int i = 1; i < N; ++i)
			scanf("%d", &arr[i]);

		b = arr[0] + arr[3] + arr[6];
		g = arr[1] + arr[4] + arr[7];
		c = arr[2] + arr[5] + arr[8];

		ans = INT_MAX;
		idx = 0;
		for (int i = 0; i < 6; ++i) {
			x = b + c + g- arr[get(P[i][0])] - arr[3 + get(P[i][1])] - arr[6 + get(P[i][2])];
			if (x < ans) {
				ans = x;
				idx = i;
			}
		}
		printf("%s %d\n", P[idx], ans);
	}
}