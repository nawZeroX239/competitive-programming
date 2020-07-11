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

#define N 10000

using namespace std;

int main() { 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int k;
	while (cin >> k) {
		vector<pair<int, int>>ans;
		for (int x = k + 1; true; ++x) {
			int y = k * x;
			if (y % (x - k) == 0) {
				y = y / (x - k);
				ans.push_back(make_pair(x, y));
				if (x == y) break;
			}
		}

		cout << ans.size() << '\n';
		for (int i = 0; i < ans.size(); ++i)
			cout << "1/" << k << " = 1/" << ans[i].second << " + 1/" << ans[i].first << '\n';


	}

}