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
	int t;
	string s;
	cin>>t;
	long x;
	getline(cin, s);
	getline(cin, s);

	while (t) {
		map<string, int> dp;
		map<string, int>::iterator itr;
		x = 0;
		while (getline(cin, s) && s.length()) {
			itr = dp.find(s);
			if (itr == dp.end())
				dp[s] = 1;
			else
				itr->second = itr->second + 1;
			++x;
		}
		for (itr = dp.begin(); itr != dp.end(); ++itr) {
			// cout << itr->first << ' ' << ((double)itr->second / x * 100.0) << '\n';
			for (int i = 0; i<itr->first.length(); ++i)
				printf("%c", itr->first[i]);
			printf(" %.4f\n", (double)itr->second / x * 100.0);

		}
		--t;
		if (t) puts("");
	}
}