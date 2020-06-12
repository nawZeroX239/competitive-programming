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

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	long long x, lo, hi, ans;
	unordered_map<long long, long long>::iterator itr;
	cin >> n;
	for(; n; --n) {
		cin >> m;
		unordered_map<long long, long long> dp;
		hi = 1;
		ans =lo = 0;
		for (; m; --m) {
			cin >> x;
			itr = dp.find(x);
			if (itr != dp.end() && itr->second>lo)
				lo = itr->second;
			dp[x] = hi;
			ans = max(ans, hi - lo);
			++hi;
		}
		
		cout << ans << '\n';
	}

}