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

#define N 1000
#define K 10000
using namespace std;

#define EPS 1e-9

int arr[N];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tc, n, ans;
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		ans = 0;
		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < i; ++j)
				if (arr[j] <= arr[i])
					++ans;
		}
		cout << ans << '\n';
	}
}