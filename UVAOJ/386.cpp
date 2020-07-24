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

#define N 1000
#define EPS 1e-9

long long i, j, k;

void solve(int start) {
	long long a = start * start * start;
	long long res;
	for (i = 2; i <= 200; ++i) {
		for (j = i+1; j <= 200; ++j) {
			for (k = j+1; k <= 200; ++k) {
				 res = i * i * i + j * j * j + k * k * k;
				if (res == a) {
					cout << "Cube = " << start << ", Triple = (" << i << ',' << j << ',' << k << ')' << '\n';
				}
				if (res > a) break;
			}
		}
	}
}

void solve() {
	for (int start = 1; start <= 200; ++start)
		solve(start);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

}