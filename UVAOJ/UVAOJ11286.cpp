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
	
	int n, m, ppl;
	string str, course[5], foo;

	while (cin >> n) {
		if (n == 0)
			break;
		unordered_map<string, int> dp;
		unordered_map<string, int>::iterator itr;
		ppl = 1;
		for (int i = 0; i < n; ++i) {
			cin >> course[0] >> course[1] >> course[2] >> course[3] >> course[4];
			sort(course, course + 5);
			string key = course[0] + course[1] + course[2] + course[3] + course[4];
			itr = dp.find(key);
			if (itr == dp.end())
				dp[key] = 1;
			else {
				itr->second = 1 + itr->second;
				ppl = max(itr->second, ppl);
			}
			// cout << "key " << key << '\n';
		}

		int ans = 0;
		for (itr = dp.begin(); itr != dp.end(); ++itr)
			if (itr->second == ppl)
				ans = ans + itr->second;
		cout << ans << '\n';
	}
}