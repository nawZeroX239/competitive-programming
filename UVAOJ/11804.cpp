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
const int N = 10;
const int K = sqrt(50000);

template <class T> T gcd(T a, T b) {
	if (b == 0){ return a;} 
	return gcd(b, a % b);
}

template <class T> bool isPrime(T x) {
	for (T d = 2; d * d <= x; d++) { if (x % d == 0) return false; }
	return true;
}


string arr[N];
string sol[2][5];
string temp[5];
map<string, pair<int, int>> mp;
int u, v;

void solve() {
	int defend, attack;
	int x, y;
	attack = defend = INT_MIN;
	for (int a = 0; a < N - 4; ++a) {
		for (int b = a + 1; b < N - 3; ++b) {
			for (int c = b + 1; c < N - 2; ++c) {
				for (int d = c + 1; d < N - 1; ++d) {
					for (int e = d + 1; e < N; ++e) {
						temp[0] = arr[a]; temp[1] = arr[b];
						temp[2] = arr[c]; temp[3] = arr[d];
						temp[4] = arr[e];
						x = y = 0;
						for (int i = 0; i < 5; ++i) {
							x += (mp.find(temp[i]))->second.first;
							y += (mp.find(temp[i]))->second.second;
						}

						if ((attack<x) || (attack == x && defend < v-y)) {
							for (int i = 0; i < 5; ++i)
								sol[0][i] = temp[i];
							for (int i = 0, k = 0; i < N; ++i) {
								if (!binary_search(sol[0], sol[0] + 5, arr[i])) {
									sol[1][k++] = arr[i];
								}
							}
							attack = x;
							defend = v - y;
						}

					}
				}
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, n, m;
	cin >> T;
	
	for (int tc = 1; tc <= T; ++tc) {
		mp.clear();
		u = v = 0;
		for (int i = 0; i < N; ++i) {
			cin >> arr[i]>> n >> m;
			u += n;
			v += m;
			mp[arr[i]] = make_pair(n, m);
		}

		sort(arr, arr + N);
		solve();

		cout << "Case " << tc << ":" << '\n';
		for(int i=0; i<2; ++i)
			cout <<"(" << sol[i][0] << ", " << sol[i][1] << ", " << sol[i][2] << ", " << sol[i][3] << ", " << sol[i][4] << ")" << '\n';
	}
}
		