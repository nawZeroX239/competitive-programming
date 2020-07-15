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

#define N 10000
using namespace std;

#define EPS 1e-9
int coord[N];

int main() {
	ios_base::sync_with_stdio(0);
	int n;
	int l, r, h;
	int upper = INT_MIN;
	while (cin >> l >> h >> r) {
		for (int i = l; i < r; ++i)
			if (h > coord[i])
				coord[i] = h;
		upper = max(upper, r);
	}
	for (int i = 1; i < upper; ++i) {
		if (coord[i] != coord[i - 1]) {
			cout <<i << ' ' << coord[i]<<' ';
		}
	}
	cout << upper<<' '<< 0 << '\n';

}