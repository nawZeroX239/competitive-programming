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

#define TSIZE (int)1e6+1
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m, n, ans;
	long long num;
	while (cin >> n >> m) {
		unordered_set<long long> bucket;
		if (n == 0 && m == 0)
			break;
		while (n) {
			cin >> num;
			bucket.insert(num);
			--n;
		}
		ans = 0;
		while (m) {
			cin >> num;
			if (bucket.find(num) != bucket.end())
				++ans;
			--m;
		}
		cout << ans << '\n';
	}

}