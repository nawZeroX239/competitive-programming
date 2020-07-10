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

int get(char c) {
	if (c == 'B') return 0;
	if (c == 'C') return 1;
	return 2;
}

int match(int x) {
	if (x == 1) return 2;
	if (x == 2) return 1;
	return 0;
}

int main() {
	int b, g, c;
	string m = "BCG";
	vector<string> S;
	do {
		S.push_back(m);
	} while (next_permutation(m.begin(), m.end()));
	while (cin >> arr[0]) {
		for (int i = 1; i < N; ++i)
			cin >> arr[i];
		b = g = c = 0;
		for (int r = 0; r < 3; ++r) {
			b += arr[3 * r + 0];
			g += arr[3 * r + 1];
			c += arr[3 * r + 2];
		}

		int ans = INT_MAX;
		int idx = 0;

		for (int i = 0; i < S.size(); ++i) {
			int x = 0;
			x += b - arr[3 * 0 + match(get(S[i][0]))];
			x += c - arr[3 * 1 + match(get(S[i][1]))];
			x += g - arr[3 * 2 + match(get(S[i][2]))];

			if (x < ans) {
				ans = x;
				idx = i;
			}
		}

		cout <<S[idx]<<' '<<ans<<'\n';
	}
}