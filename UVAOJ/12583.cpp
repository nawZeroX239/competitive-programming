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
#define N 505
#define EPS 1e-9

bool vis[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int TC, n, k;
	string s;
	cin >> TC;
	for (int tc = 1; tc < TC + 1; ++tc) {
		cin >> n >> k;
		cin >> s;

		int nc = 0;
		int m = k;
		memset(vis, false, n*sizeof(bool));
		for (int i = 1; i < n; ++i) {
			for (int j = i - 1; j >= 0 && j >= i - k; --j)
				if (!vis[j]  && s[i] == s[j]) {
					++nc;
					vis[j] = true;
				}

		}
		cout << "Case " << tc << ": "<<nc<<'\n';
	}
	
}