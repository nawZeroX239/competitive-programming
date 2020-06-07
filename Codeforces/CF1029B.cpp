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
	int n;
	long a, b, c, ans;
	cin >> n >> a;
	ans = c = 1;
	for (int i = 1; i < n; ++i) {
		cin >> b;
		if (b <= 2*a)
			++c;
		else
			c = 1;

		ans = max(ans, c);
		a = b;
	}
	
	cout << ans << '\n';
	return 0;
}
