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
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int walk[500];
	int n, k, c;
	cin >> n >> k>>walk[0];
	c = 0;
	for (int i = 1; i < n; ++i) {
		cin >> walk[i];
		if (walk[i - 1] + walk[i] < k) {
			c = c + k - (walk[i - 1] + walk[i]);
			walk[i] = k - walk[i - 1];

		}
	}

	cout << c << '\n';
	cout << walk[0];
	for (int i = 1; i < n; ++i)
		cout << ' ' << walk[i];
	cout << '\n';
}