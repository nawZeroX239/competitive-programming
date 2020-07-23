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

#define N 1000
#define EPS 1e-9


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int m, q, best, ans, diff;
	string key;
	while (cin >> m >> q) {
		vector<string> table(m);
		for (int i = 0; i < m; ++i) {
			cin >> table[i];
		}
		while (q--) {
			cin >> key;
			best = INT_MAX;
			ans = -1;
			for (int i = 0; i < m; ++i) {
				if (table[i].length() < key.length())
					continue;
				int outer = INT_MAX;
				for (int j = 0; j < table[i].length() - key.length() + 1; ++j) {	
					diff = 0;
					for (int k = 0; k < key.length(); ++k) {
						if (key[k] != table[i][j + k]) {
							++diff;
						}
					}
					outer = min(diff, outer);
				}

				if (outer < best) {
					best = outer;
					ans = i;
				}
			}
			cout << ans+1<< '\n';
		}
	}
}