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
#include <numeric>
using namespace std;


const long double PI = 3.14159265358979323846264338327950;
const int N = 3;


template <class T>
T gcd(T a, T b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}


int g[N][N];

bool isBingo() {
	int r, c;
	for (int i = 0; i < N; ++i) {
		r = c = 0;
		for (int j = 0; j < N; ++j) {
			r += g[i][j];
			c += g[j][i];
		}
		if (r == 0 || c == 0)
			return true;
	}

	return g[0][0] + g[1][1] + g[2][2] == 0
		|| g[2][0] + g[1][1] + g[0][2] == 0;
}

void mark(int num) {
	for(int i=0; i<N; ++i)
		for(int j=0; j<N; ++j)
			if (g[i][j] == num) {
				g[i][j] = 0;
				return;
			}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, x;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; ++j)
			cin >> g[i][j];
	cin >> n;
	while (n--) {
		cin >> x;
		mark(x);
	}
	if (isBingo()) {
		cout << "Yes" << '\n';
	} else {
		cout << "No" << '\n';
	}
}
