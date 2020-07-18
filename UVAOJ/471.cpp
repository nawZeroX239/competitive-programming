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
using namespace std;
#define N 10001
#define EPS 1e-9

bool isOK(long long x) {
	int used = 0;
	while (x > 0) {
		int d = x % 10;
		if (used & (1 << d)) return false;
		used |= 1 << d;
		x /= 10;
	}
	//if (1 & used) return true;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	long long n;
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (long long i = 1; i <= 9876543210 / n; ++i) {
			long long j = n * i;
			if (isOK(i) && isOK(j))
				cout << j << " / " << i << " = " << n << '\n';

		}
		if (tc) cout << '\n';
	}
}