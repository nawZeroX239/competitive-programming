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

#define N 8

using namespace std;
struct price {
	string s;
	int lo, hi;
};

bool sortPred(const price& a, const price& b) {
	return a.hi < b.hi;
}

bool ubPred(const price& a, const price& b) {
	return a.hi < b.hi;
}

bool lbPred(const price& a, const int& b) {
	return a.hi < b;
}

int main() { 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tc, n, m, x, p;
	cin >> tc;
	while (tc--) {
		cin >> n;
		vector<price> arr(n);
		for (int i = 0; i < n; ++i) {
			cin >> arr[i].s >> arr[i].lo >> arr[i].hi;
		}

		sort(arr.begin(), arr.end(), sortPred);

		cin >> m;
		while(m--){
			cin >> p;
			auto it = lower_bound(arr.begin(), arr.end(), p, lbPred);
			auto ans = arr.end();
			x = 0;
			while (it != arr.end()) {
				if (p >= it->lo && p <= it->hi) {
					if (ans == arr.end()) ans = it;
					++x;
				}
				if (x > 1) break;
				++it;
			}

			if (x == 1) cout<<ans->s<<'\n';
			else cout << "UNDETERMINED\n";
			
		}
		
		
		if (tc) cout << '\n';
	}

}