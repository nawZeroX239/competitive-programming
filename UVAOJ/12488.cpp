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
#define N 24
#define EPS 1e-9

int start[N], finish[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	while (cin >> n) {
		for (int i = 0; i < n; ++i)
			cin >> start[i];
		for (int i = 0; i < n; ++i)
			cin >> finish[i];
		int nc = 0;
		for (int i = 0; i < n; ++i) {
			if (start[i] != finish[i]) {
				int k;
				for (k = 0; k<n; ++k)
					if (start[k] == finish[i])
						break;
				if (k > i) {
					while (k > i) {
						swap(start[k], start[k - 1]);
						++nc;
						--k;
					}
				} else {
					while (k < i) {
						swap(start[k], start[k + 1]);
						++nc;
						++k;
					}
				}
			}
		}
		cout << nc << '\n';
	}
}