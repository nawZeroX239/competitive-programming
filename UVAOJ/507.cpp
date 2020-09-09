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

const long double EPS = 1e-9;
const int N = 20000;

using namespace std;
int ar[N];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int b, r = 1, s, k, l, m, n, p, q;
	cin >> b;
	while (b--) {
		cin >> s;
		n = -1;
		for (int i = 0; i < s-1; ++i) {
			cin >> ar[i];
		}
		p = 0; q = -1;
		k = l = m = n = 0;
		for (int i = 0; i < s-1; ++i) {
			if (q < 0) {
				k = i;
				l = k;
				q = 0;
			}

			q += ar[i];
			if (q >= p) {
				l = i;
				if (q > p || l - k > n - m) {
					m = k;
					n = l;
				} 
			}

			// q = max(q, 0);
			p = max(p, q);
		}
		if (p <= 0) {
			cout << "Route " << r++ << " has no nice parts" << '\n';
		} else {
			cout << "The nicest part of route " << r++ << " is between stops " << m + 1 << " and " << n + 2 << '\n';
		}
		
	}
}