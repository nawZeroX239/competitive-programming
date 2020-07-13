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
	int n, m, ans, x, dx;
	int tc = 1;
	while (cin >> n) {
		if (n == 0) break;
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		cout << "Case " << tc << ":\n";
		cin >> m;
		while (m--) {
			cin >> x;
			dx = ans = INT_MAX;
			
			for (int i = 0; i < n - 1; ++i) {
				for (int j = i + 1; j < n; ++j) {
					if (abs(arr[i] + arr[j] - x) < dx) {
						ans = arr[i] + arr[j];
						dx = abs(ans - x);
					}
				}
			}
			cout << "Closest sum to "<<x<<" is "<< ans << ".\n";
		}

		++tc;
	}
}