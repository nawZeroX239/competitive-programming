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
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define EPS 1e-2
#define N 500005
#define ll long long
#define pi pair<ll, ll>
using namespace std;

int arr[N];

bool comparator(int a, int b) {
	return abs(a) > abs(b);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, ans, last;
	cin >> n;
	while (n) {
		cin >> m;
		for (int i = 0; i < m; ++i)
			cin >> arr[i];
		sort(arr, arr + m, comparator);
		int ans = (m ? 1 : 0);
		last = 0;
		for (int i = 1; i < m; ++i) {
			if ((arr[last] < 0 && arr[i] > 0) || (arr[last] > 0 && arr[i] < 0)) {
				++ans;
				last = i;
				
			}
		}
		cout << ans << '\n';
		--n;
	}
}
