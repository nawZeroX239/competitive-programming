#include <iostream>
#include <string>
#include <algorithm>
#include <utility> 
#include <unordered_set>
#include <vector>
#include <list> 
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

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a, b, c, d, n, x, y, ans;
	vector<pair<int, int>> vect;
	cin >> n;

	ans = 0;
	for(int i=0; i<n; ++i){
		cin >> x >> y;
		vect.push_back(make_pair(x, y));
	}

	for (int i = 0; i < vect.size(); ++i) {
		a = b = c = d = 0;
		for (int j = 0; j < vect.size(); ++j) {
			if (i == j || (vect[i].first != vect[j].first && vect[i].second != vect[j].second))
				continue;
			if (vect[i].first < vect[j].first)
				a = 1;
			else if (vect[i].first > vect[j].first)
				b = 1;
			else if (vect[i].second < vect[j].second)
				c = 1;
			else if (vect[i].second > vect[j].second)
				d = 1;
		}
		if (a && b && c && d)
			++ans;
	}

	printf("%d\n", ans);
	return 0;
}
