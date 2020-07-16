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

#define N 200000
#define EPS 1e-9

long long a[N], b[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i=0; i<m; ++i)
		cin >> b[i];
	sort(a, a + n);
	sort(b, b + m);
	int c = 0;
	int i, j, inc;
	i = j = 0;
	while (i < n && j < m) {
		if (b[j] >= a[i] - k && b[j] <= a[i] + k) {
			++c;
			++i;
			++j;
		}else if (b[j] > a[i] + k) {
			++i;
		} else if (b[j] < a[i] - k) {
			++j;
		}
	}
	cout << c << '\n';
}