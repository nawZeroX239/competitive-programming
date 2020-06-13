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
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define N (int)1e6+1
using namespace std;
int memo[N] = {};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, lo, hi, bill;
	long long ans;
	while (cin >> n && n) {
		set<int> urn;
		set<int>::iterator itr;
		ans = 0;
		
		for (; n; --n) {
			cin >> m;
			for (; m; --m) {
				cin >> bill;
				++memo[bill];
				urn.insert(bill);
			}
			lo = *(urn.begin());
			hi = *(--urn.end());
			// cout << "lo " << lo << " hi " << hi << '\n';
			ans = ans + hi - lo;
			--memo[lo];
			--memo[hi];
			if(memo[lo] ==0)
				urn.erase(lo);
			if(memo[hi] == 0)
				urn.erase(hi);
		}

		for (itr = urn.begin(); itr != urn.end(); ++itr)
			memo[*itr] = 0;
		cout << ans << '\n';

	}
	
}