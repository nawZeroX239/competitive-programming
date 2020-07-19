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
#define N 18
#define EPS 1e-9

int arr[N];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;
	int tc = 1;
	while (cin >> n) {
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		long long ans = -1;
		for (int i = 0; i < n; ++i) {
			long long temp = arr[i];
			ans = max(temp, ans);
			for (int j = i + 1; j < n; ++j) {
				temp *= arr[j];
				ans = max(temp, ans);
			}
		}
		cout << "Case #" << tc << ": The maximum product is ";
		if (ans > 0) cout << ans << ".\n";
		else cout << 0 << ".\n";
		cout << '\n';
		++tc;
	}
}