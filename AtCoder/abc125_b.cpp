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

#define N 20
#define EPS 1e-9
#define PI 3.14159265358979323846264338327950

int v[N], c[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, ans, s1, s2;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	for (int i = 0; i < n; ++i)
		cin >> c[i];
	ans = 0;
	for (int mask = 1; mask <= (1<<n) - 1; ++mask) {
		s1 = s2 = 0;
		for (int i = 0; i < n; ++i) {
			if ((mask >> i) & 1) {
				s1 += v[i];
				s2 += c[i];
			}
		}
		ans = max(ans,s1 - s2);
	}
	cout << ans << '\n'; 
}
