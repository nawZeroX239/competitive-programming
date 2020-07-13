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

#define N 500
#define K 10000
using namespace std;

#define EPS 1e-9

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, abcde, fghij, x;
	bool sol, nl;
	nl = false;
	while (cin>>n) {
		if (n == 0) break;
		if (nl) cout << '\n';
		sol = false;
		for (fghij= 01234; fghij <= 98765 / n; ++fghij) {
			abcde = fghij * n;
			int digit = abcde < K | fghij < K;

			x = fghij;
			while (x > 0) {
				digit |= 1 << (x % 10);
				x /= 10;
			}
			x = abcde;
			while (x > 0) {
				digit |= 1 << (x % 10);
				x /= 10;
			}

			if ((1 << 10) - 1 == digit) {
				if (abcde < K) cout << 0;
				cout << abcde << " / ";
				if (fghij < K) cout << 0;
				cout<<fghij << " = " << n << '\n';
				sol = true;
			}
		}
		if (!sol) cout << "There are no solutions for " << n << ".\n";
		nl = true;
	}
}