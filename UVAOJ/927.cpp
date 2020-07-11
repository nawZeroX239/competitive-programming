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

#define N 20
using namespace std;

int arr[N+1];
int main() { 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, tc, d, k;
	long long ans;
	scanf("%d", &tc);
	while (scanf("%d", &n) == 1) {
		for (int i = 0; i < n+1; ++i)
			scanf("%d",  &arr[i]);
		scanf("%d%d", &d, &k);
		for (int i = 1, m=1; true; ++i) {
			ans = 0;
			for (int j = 0; j < n+1; ++j)
				ans += arr[j] * pow(i, j);
			// printf("ans: %lld\n", ans);
			if (k >= m && k < m+d * i) {
				break;
			}
			m += d * i;
		}

		printf("%lld\n", ans);
	}
}