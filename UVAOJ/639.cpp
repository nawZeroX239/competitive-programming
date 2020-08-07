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
const double EPS = 1e-9;
const int N = 20;

template <class T> T gcd(T a, T b) {
	if (b == 0) { return a; }
	return gcd(b, a % b);
}

string board[4];
string temp[4];
int n;

bool place(int i, int j) {
	if (board[i][j] == '-' || board[i][j] == 'X') return false;
	for (int k = j - 1; k >= 0; --k) {
		if (board[i][k] == '-')
			return false;
		if (board[i][k] == 'X')
			break;

	}

	for (int k = j + 1; k < n; ++k) {
		if (board[i][k] == '-')
			return false;
		if (board[i][k] == 'X')
			break;
	}

	for (int k = i - 1; k >= 0; --k) {
		if (board[k][j] == '-')
			return false;
		if (board[k][j] == 'X')
			break;
	}

	for (int k = i + 1; k < n; ++k) {
		if (board[k][j] == '-')
			return false;
		if (board[k][j] == 'X')
			break;
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int ans, shift, cnt, t;

	while (cin >> n) {
		if (n == 0) break;
		for (int i = 0; i < n; ++i) {
			cin >> temp[i];
		}

		ans = 0;
		shift = n * n;
		
		for (int mask = 0; mask <= (1 << shift) - 1; ++mask) {
			cnt = 0;
			for (int i = 0; i < n; ++i)
				board[i] = temp[i];
			
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					t = n * i + j;
					if ((mask >> t) & 1) {
						if (place(i, j)) {
							board[i][j] = '-';
							++cnt;
						}
					}
				}
			}

			ans = max(ans, cnt);
		}
		cout << ans << '\n';
	}
}