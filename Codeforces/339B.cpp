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

#define N (int)1e5
#define EPS 1e-9

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, l;
	long long ans;
	int pos;
	pos = 1; ans = 0;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> l;
		if (l > pos) {
			ans += l - pos;
			pos = l;
		} else if (l < pos) {
			ans += l + n - pos;
			pos = l;
		}
	}
	cout << ans << '\n';
}