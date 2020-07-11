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

#define N  100000

using namespace std;

int arr[N];

int main() { 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, tc;
	int ans, nmax;
	scanf("%d", &tc);
	while (scanf("%d", &n) == 1) {
		
		scanf("%d", &arr[0]);
		nmax = arr[0];
		ans = INT_MIN;
		for (int i = 1; i < n-1; ++i) {
			scanf("%d", &arr[i]);
			if (nmax - arr[i] > ans) 
				ans = nmax - arr[i];
			nmax = max(nmax, arr[i]);
		
		}
		scanf("%d", &arr[n - 1]);
		ans = max(nmax - arr[n - 1], ans);
		printf("%d\n", ans);
	}

}