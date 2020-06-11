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

int a[1000000] = {};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, nmem, m, tt=1;
	string s;
	while (cin >> n && n) {
		cout << "Scenario #" << tt << '\n';
		vector<list<int>> teams(n);
		list<int> order;
		unordered_set<int> dp;

		for (int team = 0; team < n; ++team) {
			cin >> nmem;
			for (int i = 0; i < nmem; ++i) {
				cin >> m;
				a[m] = team;
			}
		}

		while (cin >> s && s != "STOP") {
			if (s == "ENQUEUE") {
				cin >> m;
				if (dp.find(a[m]) == dp.end()) {
					order.push_back(a[m]);
					dp.insert(a[m]);
				}
				teams[a[m]].push_back(m);
			} else {
				cout << teams[order.front()].front() << '\n';
				teams[order.front()].pop_front();
				if (teams[order.front()].size() == 0) {
					dp.erase(dp.find(order.front()));
					order.pop_front();
				}
				
			}
		}
		cout << '\n';
		++tt;
	}
	
}