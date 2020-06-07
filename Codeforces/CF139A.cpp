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
	int a[7] = {};
	int n, s, ans;
	cin >> n;
	for (int i = 0; i < 7; ++i)
		cin >> a[i];


	while (n > 0) {
		for (int i = 0; i < 7; ++i) {
			n = n - a[i];
			if (n <= 0) {
				ans = i + 1;
				break;
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}
